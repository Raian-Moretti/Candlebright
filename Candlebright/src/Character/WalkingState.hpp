#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

namespace CharacterStates {
    class WalkingState : public CharacterState {
        public:
            WalkingState();
            virtual ~WalkingState();

            virtual const bool idle(Characters::Character* _char);
            virtual const bool jumping(Characters::Character* _char);
            virtual const bool falling(Characters::Character* _char);
            virtual const bool attacking(Characters::Character* _char);
    };
}