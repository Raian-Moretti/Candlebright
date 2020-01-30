#pragma once
#include "includes.hpp"
class Object{
    public:
        virtual void fall(){}
        virtual sf::FloatRect getRect(){ return {0,0,0,0}; }
        Object();
        ~Object();
};
