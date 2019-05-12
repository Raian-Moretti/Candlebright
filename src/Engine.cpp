#include "Engine.h"

Engine::Engine(sf::RenderWindow& _win,  sf::View& _view):
    window(_win), view(_view){
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 350);
    window.create(sf::VideoMode(600, 400), "Joguinho!", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
}
Engine::~Engine(){}

void Engine::addPlayer(Player* p){
    listeners.push_back(dynamic_cast<Listener*>(p));
}

void Engine::addSprite(sf::Sprite* spr){
    sprites.push_back(spr);
}

void Engine::update(){
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.setView(view);

        for(auto itr = sprites.begin(); itr != sprites.end(); ++itr){
            window.draw(*(*itr));
        }

        for(auto itr = listeners.begin(); itr != listeners.end(); ++itr){
            (*itr)->onUpdate();
            (*itr)->drawTo(window);
        }

        window.display();
    }
}
