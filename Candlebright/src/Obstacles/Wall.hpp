#pragma once

#include <SFML/Graphics.hpp>
#include "../Thing.hpp"
#include "Obstacle.hpp"

namespace Obstacles {

    class Wall : public Obstacle {
        private:
            sf::RectangleShape rect;
            sf::Color color;

        public:
            Wall(sf::Vector2f size, sf::Vector2f pos, sf::Color _col);
            Wall(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex);
            ~Wall();
            virtual void update();
            virtual void draw(System::Engine& engine) const;
            virtual const sf::FloatRect getRect() const;
    };

}