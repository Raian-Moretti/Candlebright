#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <unistd.h>

using namespace std;
using namespace chrono;

int main(){
    float size = 100;
    bool up = true;
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
 
    window.create(sf::VideoMode(900, 900), "SFML Project", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
 
    window.setKeyRepeatEnabled(true);

    sf::CircleShape shape(size);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(!up)
            size--;
        else if(up)
            size++;
        if(size == 300 || size == 0) up = !up;
        shape = sf::CircleShape(size);
        shape.setFillColor(sf::Color::Green);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}