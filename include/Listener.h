#pragma once
class Listener{
    public:
        Listener(){}
        ~Listener(){}
        virtual void onUpdate() = 0;
        virtual void drawTo(sf::RenderWindow& window) = 0;
};
