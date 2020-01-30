#pragma once

#include <list>
#include "../Obstacles/Obstacle.hpp"

namespace Lists {
    class ObstaclesList {
        public:
            std::list<Obstacles::Obstacle*> obstacles;

            void add(Obstacles::Obstacle* _el){
                obstacles.push_back(_el);
            }
            void remove(Obstacles::Obstacle* _el){
                obstacles.remove(_el);
            }
            void clear(){
                obstacles.clear();
            }

            const std::list<Obstacles::Obstacle*>::iterator begin(){ return obstacles.begin(); }
            const std::list<Obstacles::Obstacle*>::iterator end(){ return obstacles.end(); }
    };
}