#include "City.hpp"

Phases::City::City(){
    sf::Texture* tex = getTexture("sprites/platform.png");
    tex->setRepeated(true);

    Obstacles::Platform* p;
    p = new Obstacles::Platform(sf::Vector2f(1510.0f, 80.0f), sf::Vector2f(0.0f, 733.f), getTexture("sprites/ground.png")); // Chão
    addObstacle(p);
    p = new Obstacles::Platform(sf::Vector2f(1152.f, 16.f), sf::Vector2f(300.0f, 620.0f), new sf::Sprite(*tex)); // Platforma branca
    addObstacle(p);


    Obstacles::Obstacle* o;
    o = new Obstacles::Wall(sf::Vector2f(50.0f, 10.0f), sf::Vector2f(220.0f, 670.0f), sf::Color::Cyan);
    addObstacle(o);
    o = new Obstacles::Fire(sf::Vector2f(130.0f, 675.f), 25);
    addObstacle(o);
    o = new Obstacles::Black_Hole(sf::Vector2f(500.0f, 650.0f), 40);
    addObstacle(o);

    /* Bordas do mapa */
    o = new Obstacles::Wall(sf::Vector2f(10.0f, 800.0f), sf::Vector2f(0.0f, 0.0f), sf::Color::Black);
    addObstacle(o);
    o = new Obstacles::Wall(sf::Vector2f(10.0f, 800.0f), sf::Vector2f(1500.0f, 0.0f), sf::Color::Black);
    addObstacle(o);

    Characters::Enemy* e;
    e = new Characters::Zombie(sf::Vector2f(182.f, 600.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(500.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(550.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Dressed_Zombie(sf::Vector2f(800.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Dressed_Zombie(sf::Vector2f(830.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(1000.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(1200.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Dressed_Zombie(sf::Vector2f(1300.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Hell_Demon(sf::Vector2f(1300.0f, 540.0f));
    addCharacter(e);
    e = new Characters::Dressed_Zombie(sf::Vector2f(1300.0f, 600.0f));
    addCharacter(e);
    e = new Characters::Dressed_Zombie(sf::Vector2f(1200.0f, 600.0f));
    addCharacter(e);

    sf::Texture* backgroundTexture = new sf::Texture;
    background = new sf::Sprite;

    if (!backgroundTexture->loadFromFile("sprites/background1.png")){
        std::cerr << "Erro ao ler background..." << std::endl;
    }

    backgroundTexture->setSmooth(true);
    background->setTexture(*backgroundTexture);
    background->setPosition(sf::Vector2f(0.0f, 300.0f));

    background_music = new System::Music("songs/city_theme.ogg");
    background_music->run();
}
Phases::City::~City(){
    background_music->stop();
    delete background_music;
}

const sf::Vector2f Phases::City::getSpawnPoint() const {
    return sf::Vector2f(50.0f, 600.0f);
}