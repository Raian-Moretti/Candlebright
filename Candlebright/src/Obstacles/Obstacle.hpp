#pragma once

#include <SFML/Graphics.hpp>
#include "../Thing.hpp"

namespace Obstacles {

    class Obstacle : public Thing {
        protected:
            short type;
            float damage;
            float attackRate; // Milisegundo por ataque
            float size;
            float range;
            sf::Clock attackClock;
            sf::Sprite oSprite;
            sf::Texture* texture;
            sf::Vector2f position;

        public:
            Obstacle();
            virtual ~Obstacle();

            virtual const float getRange() const;
            virtual const float getDamage() const;
            virtual const float getAttackRate() const;
            virtual sf::Clock* getAttackClock();
            
            /*  0 = Platform
                1 = Wall
                2 = Fire
                3 = Black Hole
            */
            const short getType() const;

    };

}