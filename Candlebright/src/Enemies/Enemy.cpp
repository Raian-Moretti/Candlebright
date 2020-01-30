#include "Enemy.hpp"

unsigned int Characters::Enemy::enemyCount = 0;

Characters::Enemy::Enemy(){
    enemyCount++;
    score = 0;
}
Characters::Enemy::~Enemy(){
    enemyCount--;
    Player::setScore(Player::getScore()+score);
}

void Characters::Enemy::setPosition(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Characters::Enemy::getPosition() const {
    return eSprite.getPosition();
}
