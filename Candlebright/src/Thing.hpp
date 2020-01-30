#pragma once
#include <SFML/Graphics.hpp>
#include "System/Entity.hpp"

class Thing : public System::Entity {
    protected:
        bool collidingUp;
        bool collidingRight;
        bool collidingLeft;
        bool collidingDown;
    
    public:
        Thing(){
            collidingUp = false;
            collidingRight = false;
            collidingLeft = false;
            collidingDown = false;
        }
        virtual ~Thing(){ }
        virtual void fall(){ }
        virtual const sf::FloatRect getRect() const { return sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f); }
        virtual const sf::Vector2f getPosition() const { return sf::Vector2f(0.0f, 0.0f); }

        void setCollidingUp(bool _isColliding){ collidingUp = _isColliding; }
        void setCollidingRight(bool _isColliding){ collidingRight = _isColliding; }
        void setCollidingLeft(bool _isColliding){ collidingLeft = _isColliding; }
        void setCollidingDown(bool _isColliding){ collidingDown = _isColliding; }
        
        bool isCollidingUp(){ return collidingUp; }
        bool isCollidingRight(){ return collidingRight; }
        bool isCollidingLeft(){ return collidingLeft; }
        bool isCollidingDown(){ return collidingDown; }
};