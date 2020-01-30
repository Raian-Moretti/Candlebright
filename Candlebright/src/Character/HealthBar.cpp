#include "HealthBar.hpp"

HealthBar::HealthBar(const sf::Vector2f pos){
    size = sf::Vector2f(50.0f, 5.0f);
    background.setPosition(pos);
    foreground.setPosition(pos);

    background.setFillColor(sf::Color(60, 0, 0));
    foreground.setFillColor(sf::Color(255, 0, 0));

    background.setSize(size);
    foreground.setSize(size);

    maxHealth = 100.0f;
    health = 100.0f;
}
HealthBar::~HealthBar(){ }

void HealthBar::setHealth(const float& _health){
    health = _health;
    
    float rate = maxHealth/size.x;
    foreground.setSize(sf::Vector2f(_health/rate,size.y));
}

void HealthBar::setMaxHealth(float _health){
    maxHealth = _health;
}

void HealthBar::setPosition(const sf::Vector2f& _pos){
    background.setPosition(_pos);
    foreground.setPosition(_pos);
}

void HealthBar::setSize(const sf::Vector2f _size){
    size = _size;

    float rate = maxHealth/size.x;
    foreground.setSize(sf::Vector2f(health/rate, size.y));
    background.setSize(sf::Vector2f(health/rate, size.y));
}

void HealthBar::draw(System::Engine& engine) const {
    engine.draw(background);
    engine.draw(foreground);
}