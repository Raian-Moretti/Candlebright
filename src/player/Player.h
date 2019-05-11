#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <string>
#include <string.h>
#include <unistd.h>

using namespace std;
using namespace chrono;

class Player{
    private:
        string name;
        int score;
        float moveSpeed;

        sf::RectangleShape player;
        sf::View* view;

        void move(sf::Vector2f vec){
            player.setPosition({player.getPosition().x + vec.x, player.getPosition().y + vec.y});
            if(player.getPosition().x - (view->getCenter().x+((view->getSize().x)/2))  > -50   && vec.x > 0)
                view->move({vec.x,0});
            if(player.getPosition().x - (view->getCenter().x+((view->getSize().x)/2))  < -550 && vec.x < 0)
                view->move({vec.x,0});


        }
    public:
        Player(string _name = ""):
            name(_name){
            player.setSize({20,60});
            player.setFillColor(sf::Color::Blue);
            setPos({50, 700});
            moveSpeed = 0.25;
        }
        ~Player(){}
        void drawTo(sf::RenderWindow &window) {
            window.draw(player);
        }

        void setPos(sf::Vector2f newPos) {
            player.setPosition(newPos);
        }

        void moveRight(){
            move({moveSpeed,0});
        }
        void moveLeft(){
            move({-moveSpeed,0});
        }
        void moveUp(){

            for(int i=0; i<5;i++)
                move({0,-moveSpeed});
        }
        void moveDown(){
            for(int i=5; i>0;i--)
                move({0,moveSpeed});
        }

        void setView(sf::View* _view){
            view = _view;
            //view->setCenter(player.getPosition());
        }

};
