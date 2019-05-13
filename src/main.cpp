#include "includes.hpp"

#include "Plataform.hpp"
#include "Object.hpp"
#include "World.hpp"
#include "Listener.hpp"
#include "Player.hpp"
#include "Engine.hpp"

int main(){
    sf::RenderWindow window;
    /* view
        x1            x2
        y1            y2
    *///                        x1    y1     x2     y2
    sf::View view(sf::FloatRect(0.f, 300.f, 600.f, 500.f));

    World w1;

    Engine engine(window,view);
    Player player(view);

    sf::Texture texture;
    if (!texture.loadFromFile("sprites/bg.png")){
        cout << "Erro ao ler arquivo..." << endl;
    }
    texture.setSmooth(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    engine.addSprite(&sprite);
    engine.addPlayer(&player);
    engine.setWorld(&w1);
    player.setWorld(&w1);

    w1.addObject(dynamic_cast<Object*>(&player));

    engine.update();
    return 0;
}
