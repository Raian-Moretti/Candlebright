#include "Fire.hpp"

Obstacles::Fire::Fire(sf::Vector2f pos, float _size){
    oSprite.setPosition(pos);
    position = pos;
    type = 2;

    anim = new AnimManager(&oSprite, sf::Vector2i(20, 60));
    anim->addSheet("fire", "sprites/Obstacle/new-Fire.png");
    anim->defineRect();
    // Computa o ataque, taxa de ataque, dano e tamanho
    anim->setScale(sf::Vector2f(_size/25, _size/30)); // Tamanho
    damage = _size/750;
    attackRate = _size/50 * 300;
    range = oSprite.getGlobalBounds().width + oSprite.getGlobalBounds().width*0.05;
}
Obstacles::Fire::~Fire(){ }

void Obstacles::Fire::update(){
    if(animClock.getElapsedTime().asMilliseconds() > 200){
        anim->play("fire");
        animClock.restart();
    }
}

void Obstacles::Fire::draw(System::Engine& engine) const {
    engine.draw(oSprite);
}

const sf::Vector2f Obstacles::Fire::getPosition() const {
    return position;
}