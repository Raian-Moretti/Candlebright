#pragma once

#include <SFML/Graphics.hpp>
#include "../System/Engine.hpp"

class HealthBar {
    private:
        sf::RectangleShape background;
        sf::RectangleShape foreground;
        sf::Vector2f size;
        float maxHealth;
        float health;

    public:
        HealthBar(const sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
        ~HealthBar();

        void setPosition(const sf::Vector2f& _pos);
        void setSize(const sf::Vector2f _size);
        void setHealth(const float& _health);
        void setMaxHealth(float _health);

        void draw(System::Engine& engine) const;
};