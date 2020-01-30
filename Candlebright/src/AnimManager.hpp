#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class AnimManager {
    private:
        sf::Sprite* sprite;
        const sf::Vector2i size;
        sf::IntRect rect;
        sf::Vector2f scale;
        bool goingBack;
        std::string current;
        std::map<std::string, sf::Texture*> animes; // animes["idle"] -> sf::Texture*
        std::map<std::string, int> modes;

        unsigned int count; // Contagem de quantas animações foram feitas
        bool locked;

        sf::Texture* getTexture(std::string filename);

    public:
        AnimManager(sf::Sprite* _sprite, const sf::Vector2i _size = sf::Vector2i(0, 0));
        ~AnimManager();

        /*  mode = 0: vai e volta
            mode = 1: vai e volta pro começo
            mode = 2: vai e fica nos 2 ultimos, não sobrepõe
            mode = 3: vai e destranca as animações              
            mode = 4: vai e fica, destranca depois de terminado     */
        void addSheet(std::string name, std::string filename, int mode = 0);

        /*  lock = true: não deixa outra animação sobrepor e 
                         impede que o personagem mude seu State */
        void play(std::string name, bool lock = false);
        void stop();
        
        void setScale(sf::Vector2f _scale);
        void defineRect();
        const unsigned int getStage() const { return (int)rect.left/rect.width; }
        const unsigned int getCount() const { return count; }
        const bool isLocked() const { return locked; }
};
