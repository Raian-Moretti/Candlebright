#pragma once
#include "includes.hpp"
#include "World.hpp"
#include "Player.hpp"
class Engine{
    private:
        sf::RenderWindow& window;
        sf::View& view;

        vector<Listener*> listeners;
        vector<sf::Sprite*> sprites;

        World* world;
    public:
        Engine(sf::RenderWindow& _win,  sf::View& _view);
        ~Engine();
        void update();

        void addPlayer(Player* p);
        void addSprite(sf::Sprite* spr);

        const sf::View& getView() const{ return view; }
        const sf::RenderWindow& getWindow() const{ return window; }

        void setWorld(World* _world){ world = _world; }
};
