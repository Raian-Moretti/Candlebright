#include "CharacterState.hpp"

CharacterStates::CharacterState::CharacterState(State _state): state(_state){

}

CharacterStates::CharacterState::~CharacterState(){}

const bool CharacterStates::CharacterState::idle(Characters::Character* _char){
    return false;
}

const bool CharacterStates::CharacterState::walking(Characters::Character* _char){
    return false;
}

const bool CharacterStates::CharacterState::jumping(Characters::Character* _char){
    return false;
}

const bool CharacterStates::CharacterState::falling(Characters::Character* _char){
    return false;
}

const bool CharacterStates::CharacterState::attacking(Characters::Character* _char){
    return false;
}