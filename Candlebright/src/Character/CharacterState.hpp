#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Characters {
    class Character;
}
namespace CharacterStates {

    class CharacterState {
        public:
            enum State {
                STATE_IDLE,         //  0
                STATE_WALKING,      //  1
                STATE_JUMPING,      //  2
                STATE_FALLING,      //  3
                STATE_ATTACKING     //  4
            };

            CharacterState(State _state);
            virtual ~CharacterState();

            virtual const bool idle(Characters::Character* _char);
            virtual const bool walking(Characters::Character* _char);
            virtual const bool jumping(Characters::Character* _char);
            virtual const bool falling(Characters::Character* _char);
            virtual const bool attacking(Characters::Character* _char);

            const State getState() const { return state; }
        
        private:
            State state;
    };
}