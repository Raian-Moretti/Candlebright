#pragma once
#include "includes.h"
#include "Listener.h"
#include "../src/player/Player.h"
class Engine{
    private:
        sf::RenderWindow& window;
        sf::View& view;

        vector<Listener*> listeners;
        vector<sf::Sprite*> sprites;
    public:
        Engine(sf::RenderWindow& _win,  sf::View& _view);
        ~Engine();
        void update();

        void addPlayer(Player* p);
        void addSprite(sf::Sprite* spr);

        const sf::View& getView() const{ return view; }
        const sf::RenderWindow& getWindow() const{ return window; }
};
