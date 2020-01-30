#include "JumpingState.hpp"

CharacterStates::JumpingState::JumpingState(): CharacterState(STATE_JUMPING){

}

CharacterStates::JumpingState::~JumpingState(){

}

const bool CharacterStates::JumpingState::walking(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

const bool CharacterStates::JumpingState::falling(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}