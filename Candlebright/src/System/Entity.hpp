#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.hpp"

namespace System {
    class Entity {
        public:
            Entity(){}
            virtual ~Entity(){}
            virtual void update() = 0;
            virtual void draw(System::Engine& engine) const = 0;
            inline sf::Texture* getTexture(std::string filename){
                sf::Texture* _tex = new sf::Texture;
                if(!_tex->loadFromFile(filename)){
                    std::cerr << "Não foi possível ler textura do arquivo: " << filename << std::endl;
                    return NULL;
                }
                return _tex;
            }
    };
}