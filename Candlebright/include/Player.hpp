#pragma once
#include "includes.hpp"
#include "Listener.hpp"
#include "World.hpp"
class Player: public Listener, public Object{
    private:
        string name;
        int score;
        float moveSpeed;
        bool isJumping;
        float jumpHeight;
        float finalJumpHeight;
        float maxVelocityX;
        float maxVelocityY;
        sf::Vector2f acc; // vetor de aceleração
        sf::RectangleShape player;
        sf::View& view;

        World* world;

        void move(sf::Vector2f vec);
    public:
        Player(sf::View& _view, string _name = "");
        ~Player();

        void setPos(sf::Vector2f newPos);
        void moveRight();
        void moveLeft();
        void jump();
        void onUpdate();
        void drawTo(sf::RenderWindow &window);
        void fall();
        void respawn();
        sf::FloatRect getRect();

        void setWorld(World* _world){ world = _world; }
};
