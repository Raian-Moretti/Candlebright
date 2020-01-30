#pragma once

#include <SFML/Graphics.hpp>
#include "../List/ThingsList.hpp"

#define LIMIT   6
class CollisionManager {
    public:
        CollisionManager(Lists::ThingsList* _things);
        ~CollisionManager(){ }

        void checkCollisions();

    private:
        /* Parte de baixo do obj1 com a parte de cima do obj2. */
        const bool intersectsDown(sf::FloatRect obj1, sf::FloatRect obj2) const;
        /* Parte de cima do objeto obj1 com a parte de baixo do obj2. */
        const bool intersectsUp(sf::FloatRect obj1, sf::FloatRect obj2) const;
        /* Lado direito do obj1 com o lado esquerdo do obj2. */
        const bool intersectsRight(sf::FloatRect obj1, sf::FloatRect obj2) const;
        /* Lado esquerdo do obj1 com o lado direito do obj2. */
        const bool intersectsLeft(sf::FloatRect obj1, sf::FloatRect obj2) const;

        Lists::ThingsList* things;
};