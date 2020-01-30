#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

namespace Characters {
    class Dressed_Zombie : public Enemy {
        public:
            Dressed_Zombie(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
            ~Dressed_Zombie();
            void setPosition(sf::Vector2f _pos);
            void moveRight();
            void moveLeft();

            virtual const sf::Vector2f getPosition() const;
            virtual const sf::FloatRect getRect() const;
            virtual void takeDamage(const float& _damage);
            virtual void fall();
            virtual void update();
            virtual void draw(System::Engine& engine) const;
            virtual void move(const sf::Vector2f& _move);
            virtual void attack();

            virtual const short getSubType() const{ return 2; }
    };
}