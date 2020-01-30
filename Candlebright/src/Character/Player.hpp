#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <fstream>

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"

namespace Characters {
    class Player : public Character {
        private:
            sf::Sprite pSprite;

            sf::Sprite wSprite; // Whip Sprite
            float whipSize;
            bool whipExpanding;

            static unsigned int score ;

            sf::Keyboard::Key key_right;
            sf::Keyboard::Key key_left;
            sf::Keyboard::Key key_jump;
            sf::Keyboard::Key key_attack;

        public:
            Player(const int _template=-1);
            ~Player();

            void setPosition(sf::Vector2f _pos);
            void moveRight();
            void moveLeft();
            void jump();

            virtual const sf::Vector2f getPosition() const;
            virtual const sf::FloatRect getRect() const;
            virtual void update();
            virtual void draw(System::Engine& engine) const;
            virtual void move(const sf::Vector2f& _move);
            virtual void attack();
            virtual void fall();
            virtual void takeDamage(const float& _damage);

            static unsigned int getScore() { return score; }
            static void setScore(unsigned int _score){ score = _score; }
    };

}