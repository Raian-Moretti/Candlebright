#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Character/Player.hpp"
#include "../Character/Character.hpp"

namespace Characters {
    class Enemy : public Character {
        protected:
            sf::Sprite eSprite;
            sf::Vector2f originalPos;
            sf::Vector2f moving;
            std::string name;
            float attackChance; // Chance de ataque a cada 1/60 segundos
            unsigned int score;


        public:
            Enemy();
            virtual ~Enemy();
            virtual void attack() = 0;
            virtual void setPosition(sf::Vector2f _pos);
            virtual const sf::Vector2f getPosition() const;

            static unsigned int enemyCount;
    };
}