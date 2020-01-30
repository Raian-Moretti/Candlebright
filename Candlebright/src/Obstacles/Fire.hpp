#pragma once

#include <SFML/Graphics.hpp>
#include "../Animatable.hpp"
#include "Obstacle.hpp"

namespace Obstacles {

    class Fire : public Obstacle, public Animatable {    
        public:
            Fire(sf::Vector2f pos, float _size);
            ~Fire();

            virtual void update();
            virtual void draw(System::Engine& engine) const;
            virtual const sf::Vector2f getPosition() const;    
    };

}