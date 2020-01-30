#pragma once

#include <SFML/Graphics.hpp>
#include "AnimManager.hpp"
#include "Thing.hpp"

class Animatable : public Thing {
    protected:
        AnimManager* anim;
        sf::Clock animClock;

    public:
        Animatable(){ anim = NULL; }
        virtual ~Animatable(){ }
        virtual AnimManager* getAnim(){ return anim; }
};