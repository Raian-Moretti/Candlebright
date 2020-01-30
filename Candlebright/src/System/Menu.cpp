#include "Menu.hpp"
System::Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("fonts/OldLondon.ttf"))
    {
        std::cerr<<"Erro ao ler fonte"<<std::endl;
    }
    menuTitle.setFont(font);
    menuTitle.setCharacterSize(42);
    menuTitle.setString("Candlebright: Ominous Whip");
    menuTitle.setOrigin(menuTitle.getGlobalBounds().left + menuTitle.getGlobalBounds().width/2.0f,
                        menuTitle.getGlobalBounds().top  + menuTitle.getGlobalBounds().height/2.0f);
    menuTitle.setPosition(300,50);
    menuTitle.setFillColor(sf::Color::White);
    menuTitle.setOutlineColor(sf::Color::Black);
    menuTitle.setOutlineThickness(1);

    sf::Texture* textureMenu = new sf::Texture;
    spriteMenu = new sf::Sprite;
    int menu_opt;
    menu_opt=rand()%2;
    if(menu_opt==0){
        if (!textureMenu->loadFromFile("sprites/menubg1.png"))
            std::cerr << "Erro ao ler background..." << std::endl;
    }
    else if(menu_opt==1){
        if (!textureMenu->loadFromFile("sprites/menubg2.png"))
            std::cerr << "Erro ao ler background..." << std::endl;
    }

    spriteMenu->setTexture(*textureMenu);

    sf::Texture* textureWhip = new sf::Texture;
    spriteWhip = new sf::Sprite;
    if(!textureWhip->loadFromFile("sprites/Player/whip.png")){
        std::cerr << "Erro ao chicote do player..." << std::endl;
    }

    spriteWhip->setTexture(*textureWhip);
    spriteWhip->setScale(sf::Vector2f(8.f, 8.f));
    spriteWhip->setPosition(50,75);

    addMenuItem(MENU_MAIN, L"Jogar", true, font);
    addMenuItem(MENU_MAIN, L"Sair", false, font);

    addMenuItem(MENU_PHASES, L"Cidade (1)", true, font);
    addMenuItem(MENU_PHASES, L"Cemitério (2)", false, font);

    addMenuItem(MENU_PLAYERS, L"1 Jogador", true, font);
    addMenuItem(MENU_PLAYERS, L"2 Jogadores", false, font);

    enabled = true;
    selectedItem = 0;
    currentMenu = MENU_MAIN;

}
System::Menu::~Menu()
{
    //dtor
}

void System::Menu::draw(System::Engine& engine) const {
    engine.draw(*spriteMenu);
    engine.draw(*spriteWhip);
    for(int i=0; i<getMenuItems(currentMenu); i++){
        engine.draw(menu_text[currentMenu][i]);
    }
    engine.draw(menuTitle);
}

void System::Menu::moveUp(){
    if(selectedItem -1 >= 0)
    {
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color(200,200,200));
        menu_text[currentMenu][selectedItem].setOutlineThickness(0);
        selectedItem--;
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color::Red);
        menu_text[currentMenu][selectedItem].setOutlineThickness(2);
     }
}

void System::Menu::moveDown(){

    if(selectedItem +1 < getMenuItems(currentMenu))
    {
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color(200,200,200));
        menu_text[currentMenu][selectedItem].setOutlineThickness(0);
        selectedItem++;
        menu_text[currentMenu][selectedItem].setFillColor(sf::Color::Red);
        menu_text[currentMenu][selectedItem].setOutlineThickness(2);
     }
}

void System::Menu::update(Engine* engine){
    sf::Event event;
    while (engine->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::Up){
                moveUp();
            }else if(event.key.code == sf::Keyboard::Down){
                moveDown();
            }else if(event.key.code == sf::Keyboard::Enter){
                switch (currentMenu){
                    case MENU_MAIN:
                        if(selectedItem == 0){
                            currentMenu = MENU_PHASES;
                            menuTitle.setString("Escolha a fase");
                            menuTitle.setPosition(400,50);
                        }
                        else if(selectedItem == 1){
                            engine->getWindow()->close();
                        }
                        selectedItem = 0;
                        break;
                    case MENU_PHASES:
                        if(selectedItem == 0) world = 1;
                        else if(selectedItem == 1) world = 2;
                        currentMenu = MENU_PLAYERS;
                        menuTitle.setString("Escolha a quantidade de jogadores");
                        menuTitle.setPosition(275,50);
                        selectedItem = 0;
                        break;
                    case MENU_PLAYERS:
                        if(selectedItem == 0) players = 1;
                        else if(selectedItem == 1) players = 2;
                        enabled = false;
                        break;
                    default:
                        break;
                }
            }
        }else if(event.type == sf::Event::Closed){
            engine->getWindow()->close();
        }
    }
}

const int System::Menu::getMenuItems(int _menu) const {
    if(_menu == MENU_MAIN) return 2;
    else if(_menu == MENU_PHASES) return 2;
    else if(_menu == MENU_PLAYERS) return 2;

    return -1;
}

void System::Menu::addMenuItem(int _menu, std::wstring _title, bool isPrimary, sf::Font _font){
    int index = 0;
    for(int i = 0; i < MAX_ITEMS; i++){
        if(menu_text[_menu][i].getFont() == NULL){
            index = i;
            break;
        }
    }
    menu_text[_menu][index].setFont(font);
    menu_text[_menu][index].setCharacterSize(36);
    menu_text[_menu][index].setFillColor(isPrimary ? sf::Color::Red : sf::Color(200,200,200));
    menu_text[_menu][index].setOutlineColor(sf::Color::Black);
    menu_text[_menu][index].setOutlineThickness(isPrimary ? 2 : 0);
    menu_text[_menu][index].setString(_title);

    sf::FloatRect textRect = menu_text[_menu][index].getGlobalBounds();
    menu_text[_menu][index].setOrigin(  textRect.left + textRect.width/2.0f,
                                        textRect.top  + textRect.height/2.0f);
    menu_text[_menu][index].setPosition(sf::Vector2f(600/2, 75 + 75 * (index+1)));
}
