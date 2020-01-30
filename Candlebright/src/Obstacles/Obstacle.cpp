#include "Obstacle.hpp"

Obstacles::Obstacle::Obstacle(){
    damage = 0.0f;
    attackRate = 0.0f;
}
Obstacles::Obstacle::~Obstacle(){ }

const float Obstacles::Obstacle::getRange() const {
    return range;
}
const float Obstacles::Obstacle::getDamage() const {
    return damage;
}
const float Obstacles::Obstacle::getAttackRate() const {
    return attackRate;
}
sf::Clock* Obstacles::Obstacle::getAttackClock(){
    return &attackClock;
}
const short Obstacles::Obstacle::getType() const {
    return type;
}