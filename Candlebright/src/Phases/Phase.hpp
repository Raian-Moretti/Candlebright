#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>
#include <stdlib.h>

#include "../Character/Player.hpp"
#include "../Enemies/Zombie.hpp"
#include "../Enemies/Ghost.hpp"
#include "../Enemies/HellDemon.hpp"
#include "../Enemies/DressedZombie.hpp"
#include "../Enemies/Sylathus.hpp"
#include "../List/LinkedList.hpp"
#include "../List/EntityList.hpp"
#include "../List/CharacterList.hpp"
#include "../List/ThingsList.hpp"
#include "../List/ObstacleList.hpp"
#include "../System/Engine.hpp"
#include "../System/Entity.hpp"
#include "../System/Music.hpp"
#include "../Thing.hpp"
#include "CollisionManager.hpp"

class Phase : public System::Entity {
    private:
        const int getIntFromString(const std::string& _str) const;
        const float getFloatFromString(const std::string& _str) const;
    
    protected:
        sf::Sprite* background;
        Lists::EntityList entities;
        Lists::ThingsList things;
        Lists::CharacterList characters;
        Lists::ObstaclesList obstacles;
        CollisionManager col_mngr;

        const float getDistance(const sf::Vector2f& p1, const sf::Vector2f& p2) const;

    public:
        Phase();
        virtual ~Phase();

        virtual const sf::Vector2f getSpawnPoint() const = 0;

        void setBackground(sf::Sprite* _bg){ background = _bg; }
        sf::Sprite* getBackground(){ return background; }
        void update(); // Atualizar a lista de entidades dentro do mundo
        void draw(System::Engine& engine) const;
        void drawAll(System::Engine& engine);
        void gravity();

        void loadEnemies(const int act_world);

        void addEntity(System::Entity* _e);
        void addThing(Thing* _thing);
        void addCharacter(Characters::Character* _char);
        void addObstacle(Obstacles::Obstacle* _obs);

        Lists::CharacterList* getCharList(){ return &characters;}

        const sf::Vector2f getRandomPosition(const sf::View& view);

        /* Processa os ataques dos personagens */
        void checkAttack(std::set<Characters::Character*>* killBuffer);
        /* Processa os obstáculos */
        void checkObstacles(std::set<Characters::Character*>* killBuffer);
};
