#include "CollisionManager.hpp"

CollisionManager::CollisionManager(Lists::ThingsList* _things){
    things = _things;
}

void CollisionManager::checkCollisions(){
    std::vector<Thing *>::iterator itr;
    for(itr = things->begin(); itr != things->end(); ++itr){
        Thing* thing1 = *itr;
        thing1->setCollidingUp(false);
        thing1->setCollidingRight(false);
        thing1->setCollidingLeft(false);
        thing1->setCollidingDown(false);
    }
    std::vector<Thing *>::iterator itr1, itr2;
    for(itr1 = things->begin(); itr1 != things->end(); ++itr1){
        Thing* thing1 = *itr1;
        for(itr2 = itr1; itr2 != things->end(); ++itr2){
            Thing* thing2 = *itr2;
            if(thing1 == thing2) continue;
            if(intersectsUp(thing1->getRect(), thing2->getRect())){
                thing1->setCollidingUp(true);
                thing2->setCollidingDown(true);
            }else if(intersectsDown(thing1->getRect(), thing2->getRect())){
                thing1->setCollidingDown(true);
                thing2->setCollidingUp(true);
            }
            if(intersectsRight(thing1->getRect(), thing2->getRect())){
                thing1->setCollidingRight(true);
                thing2->setCollidingLeft(true);
            }else if(intersectsLeft(thing1->getRect(), thing2->getRect())){
                thing1->setCollidingLeft(true);
                thing2->setCollidingRight(true);
            }
        }
    }
}

/* Parte de baixo do obj1 com a parte de cima do obj2. */
const bool CollisionManager::intersectsDown(sf::FloatRect obj1, sf::FloatRect obj2) const {
    if( obj1.top+obj1.height >= obj2.top &&
        obj1.top+obj1.height <= obj2.top+LIMIT &&
        obj1.top+obj1.height < obj2.top+obj2.height &&
        obj1.left+obj1.width > obj2.left &&
        obj1.left < obj2.left+obj2.width ) return true;
    else return false;
}

/* Parte de cima do objeto obj1 com a parte de baixo do obj2. */
const bool CollisionManager::intersectsUp(sf::FloatRect obj1, sf::FloatRect obj2) const {
    if( obj1.top <= obj2.top+obj2.height &&
        obj1.top >= obj2.top+obj2.height-LIMIT &&
        obj1.top >= obj2.top &&
        obj1.left+obj1.width > obj2.left &&
        obj1.left < obj2.left+obj2.width ) return true;
    else return false;
}

/* Lado direito do obj1 com o lado esquerdo do obj2. */
const bool CollisionManager::intersectsRight(sf::FloatRect obj1, sf::FloatRect obj2) const {
    if( obj1.left+obj1.width >= obj2.left &&
        obj1.left+obj1.width <= obj2.left+LIMIT &&
        obj1.left+obj1.width < obj2.left+obj2.width &&
        obj1.top+obj1.height > obj2.top &&
        obj1.top < obj2.top+obj2.height ) return true;
    else return false;
}

/* Lado esquerdo do obj1 com o lado direito do obj2. */
const bool CollisionManager::intersectsLeft(sf::FloatRect obj1, sf::FloatRect obj2) const {
    if( obj1.left <= obj2.left+obj2.width &&
        obj1.left >= obj2.left+obj2.width-LIMIT &&
        obj1.left > obj2.left &&
        obj1.top+obj1.height > obj2.top &&
        obj1.top < obj2.top+obj2.height ) return true;
    else return false;
}