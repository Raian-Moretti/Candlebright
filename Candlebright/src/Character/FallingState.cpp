#include "FallingState.hpp"

CharacterStates::FallingState::FallingState(): CharacterState(STATE_FALLING){

}

CharacterStates::FallingState::~FallingState(){

}

const bool CharacterStates::FallingState::walking(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

const bool CharacterStates::FallingState::idle(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}