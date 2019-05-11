#include "player/Player.h"

int main(){
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 350);

    window.create(sf::VideoMode(600, 400), "Joguinho!", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    /* view
        x1            x2

        y1            y2
    *///                        x1   y1     x2     y2
    sf::View view(sf::FloatRect(0.f, 300.f, 600.f, 500.f));

    Player player;
    player.setView(&view);

    sf::Texture texture;
    if (!texture.loadFromFile("sprites/bg.png")){
        cout << "Erro ao ler arquivo..." << endl;
    }
    texture.setSmooth(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.moveRight();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.moveLeft();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            player.moveUp();
        }



        window.clear();
        window.setView(view);

        window.draw(sprite); // background vem antes

        player.drawTo(window);
        window.display();
    }

    return 0;
}
