#include "AnimManager.hpp"

AnimManager::AnimManager(sf::Sprite* _sprite, const sf::Vector2i _size): size(_size){
    sprite = _sprite;
    rect = sf::IntRect(0, 0, _size.x, _size.y);
    scale = sf::Vector2f(1.f, 1.f);
    goingBack = false;
    count = 0;
    locked = false;

    sprite->setOrigin(sf::Vector2f((float)size.x/2, 0.0f));
}
AnimManager::~AnimManager(){
    std::map<std::string, sf::Texture *>::iterator itr;
    for(itr = animes.begin(); itr != animes.end(); ++itr){
        delete (*itr).second;
    }
    animes.clear();
}

void AnimManager::play(std::string name, bool lock){
    if(name == current){
        sprite->setTextureRect(rect);
        if(modes[name] == 0){
            if(goingBack) rect.left -= rect.width;
            else rect.left += rect.width;
            if(rect.left >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                goingBack = true;
            }else if(rect.left <= 0){
                goingBack = false;
            }
        }else if(modes[name] == 1){
            if(goingBack) rect.left -= rect.width;
            else rect.left += rect.width;
            if(rect.left >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                rect.left = 0;
            }
        }else if(modes[name] == 2){
            if(goingBack){
                rect.left -= rect.width;
                goingBack = false;
            }else rect.left += rect.width;
            if(rect.left >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                goingBack = true;
            }
        }else if(modes[name] == 3){
            if(rect.left >= static_cast<signed>(animes[current]->getSize().x-rect.width)){
                locked = false;
                current = "NULL";
            }
            rect.left += rect.width;
        }else if(modes[name] == 4){
            if(rect.left < static_cast<signed>(animes[current]->getSize().x-rect.width)){
                rect.left += rect.width;
            }
        }
        count++;
    }else{
        try {
            animes.at(name);
        }catch (const std::out_of_range& oor){
            std::cerr << "Out of Range error: " << oor.what() << std::endl;
        }
        if(locked){
            return;
        }
        locked = lock;
        count = 0;
        rect.left = 0;
        sprite->setTextureRect(rect);
        sprite->setTexture(*animes[name]);
        current = name;
    }
}

void AnimManager::stop(){
    current = "NULL";
    locked = false;
}

void AnimManager::defineRect(){
    sprite->setTextureRect(rect);
}

void AnimManager::setScale(sf::Vector2f _scale){
    if(scale == _scale) return;
    sprite->setOrigin(sf::Vector2f((float)size.x/2, 0.0));
    
    sprite->setScale(_scale);
    scale = _scale;
}

void AnimManager::addSheet(std::string name, std::string filename, int mode){
    if(mode < 0 || mode > 4) mode = 0;
    sf::Texture* tex = new sf::Texture;
    if(!tex->loadFromFile(filename)){
        std::cerr << "Não foi possível ler textura do arquivo: " << filename << std::endl;
    }
    animes.insert(std::pair<std::string, sf::Texture*>(name, tex));
    modes.insert(std::pair<std::string, int>(name, mode));
}