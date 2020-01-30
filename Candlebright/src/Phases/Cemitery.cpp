#include "Cemitery.hpp"

Phases::Cemitery::Cemitery(){
    Obstacles::Platform* p;
    p = new Obstacles::Platform(sf::Vector2f(1510.0f, 80.0f), sf::Vector2f(0.0f, 733.f), getTexture("sprites/ground2.png")); // Chão
    addObstacle(p);

    Obstacles::Obstacle* o;
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.0f), sf::Vector2f(215.f, 670.0f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.0f), sf::Vector2f(215.f, 700.0f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.0f), sf::Vector2f(230.0f, 600.0f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(25.f, 10.0f), sf::Vector2f(230.0f, 635.f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Platform(sf::Vector2f(15.f, 10.0f), sf::Vector2f(250.0f, 550.0f), sf::Color::Cyan);
    addObstacle(o);

    o = new Obstacles::Black_Hole(sf::Vector2f(500.0f, 650.0f), 40);
    addObstacle(o);
    o = new Obstacles::Fire(sf::Vector2f(450.0f, 650.0f), 40);
    addObstacle(o);

    /* Bordas do mapa */
    o = new Obstacles::Wall(sf::Vector2f(10.0f, 800.0f), sf::Vector2f(0.0f, 0.0f), sf::Color::Black);
    addObstacle(o);
    o = new Obstacles::Wall(sf::Vector2f(10.0f, 800.0f), sf::Vector2f(1500.0f, 0.0f), sf::Color::Black);
    addObstacle(o);

    Characters::Enemy* e;
    e = new Characters::Zombie(sf::Vector2f(180.0f, 600.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(550.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(650.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Ghost(sf::Vector2f(700.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Ghost(sf::Vector2f(750.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Ghost(sf::Vector2f(350.0f, 500.0f));
    addCharacter(e);
    e = new Characters::Dressed_Zombie(sf::Vector2f(800.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Dressed_Zombie(sf::Vector2f(830.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(1200.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Zombie(sf::Vector2f(1300.0f, 600.0f));
    addCharacter(e);
    e = new Characters::Zombie(sf::Vector2f(1325.f, 600.0f));
    addCharacter(e);
    e = new Characters::Zombie(sf::Vector2f(1350.0f, 600.0f));
    addCharacter(e);
    e = new Characters::Zombie(sf::Vector2f(1375.f, 600.0f));
    addCharacter(e);
    e = new Characters::Zombie(sf::Vector2f(1400.0f, 600.0f));
    addCharacter(e);
    e = new Characters::Zombie(sf::Vector2f(1450.0f, 600.0f));
    addCharacter(e);
    e = new Characters::Ghost(sf::Vector2f(1350.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Ghost(sf::Vector2f(1450.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Sylathus(sf::Vector2f(1500.0f, 550.0f));
    addCharacter(e);


    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background2.png")){
        std::cerr << "Erro ao ler background..." << std::endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition(sf::Vector2f(0.0f, 230.0f));

    background_music = new System::Music("songs/cemitery_theme.ogg");
    background_music->run();
}
Phases::Cemitery::~Cemitery(){
    background_music->stop();
    delete background_music;
}

const sf::Vector2f Phases::Cemitery::getSpawnPoint() const {
    return sf::Vector2f(50.0f, 600.0f);
}