#include "Platform.hpp"

Obstacles::Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Color _col):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    mRight = false;
    mUp = false;
    sprite = NULL;
    texture = NULL;
    moving = false;
    type = 0;
}
Obstacles::Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex):
    originalPos(pos){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    rect.setPosition(pos);
    sprite = NULL;
    moving = false;
    texture = _tex;
    type = 0;
}
Obstacles::Platform::Platform(sf::Vector2f size, sf::Vector2f pos, sf::Sprite* _spr):
    originalPos(pos){
    sprite = new sf::Sprite(*(_spr->getTexture()), sf::IntRect(pos.x,pos.y,size.x,size.y));
    sprite->setPosition(pos);
    texture = NULL;
    moving = false;
    type = 0;
}
Obstacles::Platform::~Platform(){ }

void Obstacles::Platform::draw(System::Engine& engine) const {
    if(sprite != NULL) engine.draw(*sprite);
    else engine.draw(rect);
}

void Obstacles::Platform::update(){
    if(moving){
        fmove();
    }
    if(texture != NULL){
        rect.setTexture(texture);
    }
}

const sf::FloatRect Obstacles::Platform::getRect() const {
    if(sprite == NULL) return rect.getGlobalBounds();
    else return sprite->getGlobalBounds();
}

void Obstacles::Platform::setMoveSpeed(sf::Vector2f _vel){
    vel = _vel;
}

void Obstacles::Platform::setmove(const sf::Vector2f& _move){
    move = _move;
    if(_move != sf::Vector2f(0,0)) moving = true;
}

void Obstacles::Platform::setMoving(bool _moving){
    moving = _moving;
}

const sf::Vector2f Obstacles::Platform::getPosition() const {
    return rect.getPosition();
}

void Obstacles::Platform::fmove(){
    sf::Vector2f pos = rect.getPosition();
    if(mRight){
        rect.move(sf::Vector2f(-vel.x, 0));
        if(std::abs(pos.x) < std::abs(originalPos.x-move.x)) mRight = false;
    }else{
        rect.move(sf::Vector2f(vel.x, 0));
        if(std::abs(pos.x) > std::abs(originalPos.x+move.x)) mRight = true;
    }
    if(mUp){
        rect.move(sf::Vector2f(0, -vel.y));
        if(std::abs(pos.y) < std::abs(move.y-originalPos.y)) mUp = false;
    }else{
        rect.move(sf::Vector2f(0, vel.y));
        if(std::abs(pos.y) > std::abs(move.y+originalPos.y)) mUp = true;
    }
}
