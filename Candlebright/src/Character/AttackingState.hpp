#pragma once

#include "CharacterState.hpp"
#include "Character.hpp"

namespace CharacterStates {
    class AttackingState : public CharacterState {
        public:
            AttackingState();
            virtual ~AttackingState();

            virtual const bool idle(Characters::Character* _char);
            virtual const bool falling(Characters::Character* _char);
    };
}