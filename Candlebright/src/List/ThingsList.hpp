#pragma once

#include <vector>
#include "../Thing.hpp"

namespace Lists {
    class ThingsList {
        public:
            std::vector<Thing*> things;

            void add(Thing* _el){
                things.push_back(_el);
            }
            void remove(Thing* _el){
                std::vector<Thing*>::iterator itr;
                for(itr = begin(); itr != end(); ++itr){
                    if(*itr == _el){
                        things.erase(itr);
                        break;
                    }
                }
            }
            void clear(){
                things.clear();
            }

            std::vector<Thing*>::iterator begin(){ return things.begin(); }
            std::vector<Thing*>::iterator end(){ return things.end(); }
    };
}