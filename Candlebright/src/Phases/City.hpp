#pragma once

#include <SFML/Graphics.hpp>
#include "../Enemies/Zombie.hpp"
#include "../Enemies/Ghost.hpp"
#include "../Enemies/HellDemon.hpp"
#include "../Enemies/DressedZombie.hpp"
#include "../Obstacles/Platform.hpp"
#include "../Obstacles/Wall.hpp"
#include "../Obstacles/Fire.hpp"
#include "../Obstacles/BlackHole.hpp"
#include "Phase.hpp"

namespace Phases {

    class City : public Phase {
        private:
            System::Music* background_music;
        
        public:
            City();
            ~City();
            
            virtual const sf::Vector2f getSpawnPoint() const;
    };

}