#include "Wall.hpp"

Obstacles::Wall::Wall(sf::Vector2f size, sf::Vector2f pos, sf::Color _col){
    rect = sf::RectangleShape(size);
    rect.setFillColor(_col);
    rect.setPosition(pos);
    position = pos;
    texture = NULL;
    type = 0;
}
Obstacles::Wall::Wall(sf::Vector2f size, sf::Vector2f pos, sf::Texture* _tex){
    rect = sf::RectangleShape(size);
    rect.setTexture(_tex);
    rect.setPosition(pos);
    texture = _tex;
    position = pos;
    texture = NULL;
    type = 0;
}
Obstacles::Wall::~Wall(){ }

void Obstacles::Wall::update(){
    if(texture != NULL) rect.setTexture(texture);
}

void Obstacles::Wall::draw(System::Engine& engine) const {
    engine.draw(rect);
}

const sf::FloatRect Obstacles::Wall::getRect() const {
    return rect.getGlobalBounds();
}