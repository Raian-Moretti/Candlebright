#include "World.hpp"

World::World(){
    Plataform p1({0,700},{1280,720}, sf::Color::Green);
    p1.setTexture("sprites/grass_side.png");
    plataforms.push_back(p1);
}
World::~World(){}

void World::draw(sf::RenderWindow& window){
    for(auto itr = plataforms.begin(); itr != plataforms.end(); ++itr){
        itr->draw(window);
    }
}

void World::addObject(Object* o){
    objects.push_back(o);
}

void World::gravity(){
    for(auto itr = objects.begin(); itr != objects.end(); ++itr){
        if(!isColliding((*itr)->getRect())){
            (*itr)->fall();
        }
    }
}

bool World::isColliding(sf::FloatRect rect){
    for(auto itr = plataforms.begin(); itr != plataforms.end(); ++itr){
        sf::FloatRect p_rect = itr->getRect();
        if(p_rect.intersects(rect)) return true;
    }
    return false;
}
