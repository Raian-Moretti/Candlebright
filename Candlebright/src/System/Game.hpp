#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "../Phases/City.hpp"
#include "../Phases/Cemitery.hpp"
#include "../Character/Player.hpp"
#include "Engine.hpp"
#include "Entity.hpp"
#include "Menu.hpp"

namespace System {
    class Game {
        private:
            Engine engine;
            sf::RenderWindow* window;

            Characters::Player* player1;
            Characters::Player* player2;
            Phase* world;
            sf::View view;

            unsigned short act_world;

            Menu menu;
            bool game_paused;
            bool menuEnabled;

            sf::Clock timer;

            sf::Clock enemySpawnTimer;
            unsigned int enemySpawnDelay; // Delay entre os spawns aleatórios de inimigos em segundos

            sf::Clock obstacleSpawnTimer;
            unsigned int obstacleSpawnDelay; // Delay entre os spawns aleatórios de inimigos em segundos

            const int getIntFromString(const std::string& _str) const;
            const float getFloatFromString(const std::string& _str) const;

        public:
            Game();
            ~Game();

            void run();
            void update();

            sf::View* getView(){ return &view; }
            void setView(sf::View _view){ this->view=_view; }

            void saveGame();
            void loadPlayers();

            void draw(sf::RenderWindow& window);

            void spawnRandomEnemy();
            void spawnRandomObstacle();

            void nextPhase();
    };
}