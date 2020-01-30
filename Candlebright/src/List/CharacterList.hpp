#pragma once

#include <set>
#include "../Character/Character.hpp"

namespace Lists {
    class CharacterList {
        public:
            std::set<Characters::Character*> characters;

            void add(Characters::Character* _el){
                characters.insert(_el);
            }
            void remove(Characters::Character* _el){
                characters.erase(_el);
            }
            void clear(){
                characters.clear();
            }
            std::set<Characters::Character *>::iterator begin(){ return characters.begin(); }
            std::set<Characters::Character *>::iterator end(){ return characters.end(); }

    };
}