#pragma once

#include <SFML/Graphics.hpp>
#include "../Enemies/Zombie.hpp"
#include "../Enemies/Sylathus.hpp"
#include "../Obstacles/Platform.hpp"
#include "../Obstacles/Wall.hpp"
#include "../Obstacles/Fire.hpp"
#include "../Obstacles/BlackHole.hpp"
#include "Phase.hpp"

namespace Phases {

    class Cemitery : public Phase {
        private:
            System::Music* background_music;
        
        public:
            Cemitery();
            ~Cemitery();

            virtual const sf::Vector2f getSpawnPoint() const;
    };

}