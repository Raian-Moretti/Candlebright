#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

namespace CharacterStates {
    class JumpingState : public CharacterState {
        public:
            JumpingState();
            virtual ~JumpingState();

            virtual const bool walking(Characters::Character* _char);
            virtual const bool falling(Characters::Character* _char);
    };
}