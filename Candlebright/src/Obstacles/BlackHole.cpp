#include "BlackHole.hpp"

Obstacles::Black_Hole::Black_Hole(sf::Vector2f pos, float _size){
    oSprite.setPosition(pos);
    position = pos;
    type = 3;

    anim = new AnimManager(&oSprite, sf::Vector2i(35, 33));
    anim->addSheet("hole", "sprites/Obstacle/new-Black-Hole.png", 1);
    anim->defineRect();

    // Computa o ataque, taxa de ataque, dano e tamanho
    anim->setScale(sf::Vector2f(_size/35, _size/33)); // Tamanho
    damage = _size/300;
    attackRate = _size/30 * 50;
    range = oSprite.getGlobalBounds().width + oSprite.getGlobalBounds().width*4;
}
Obstacles::Black_Hole::~Black_Hole(){ }

void Obstacles::Black_Hole::update(){
    if(animClock.getElapsedTime().asMilliseconds() > attackRate + 50){
        anim->play("hole");
        oSprite.setScale(sf::Vector2f(3.f, 3.f));
        animClock.restart();
    }
}

void Obstacles::Black_Hole::draw(System::Engine& engine) const {
    engine.draw(oSprite);
}

const sf::Vector2f Obstacles::Black_Hole::getPosition() const {
    return position;
}