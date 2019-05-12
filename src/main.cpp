#include "includes.h"

#include "engine/Listener.h"
#include "player/Player.h"
#include "engine/Engine.h"

int main(){
    sf::RenderWindow window;
    /* view
        x1            x2

        y1            y2
    *///                        x1   y1     x2     y2
    sf::View view(sf::FloatRect(0.f, 300.f, 600.f, 500.f));


    float ground = 700;

    Engine engine(window,view);
    Player player(view, ground);

    sf::Texture texture;
    if (!texture.loadFromFile("sprites/bg.png")){
        cout << "Erro ao ler arquivo..." << endl;
    }
    texture.setSmooth(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    engine.addSprite(&sprite);
    engine.addPlayer(&player);

    engine.update();
    return 0;
}
