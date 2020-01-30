#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

namespace CharacterStates {
    class FallingState : public CharacterState {
        public:
            FallingState();
            virtual ~FallingState();

            virtual const bool walking(Characters::Character* _char);
            virtual const bool idle(Characters::Character* _char);
    };

}