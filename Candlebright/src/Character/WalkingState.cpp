#include "WalkingState.hpp"

CharacterStates::WalkingState::WalkingState(): CharacterState(STATE_WALKING){

}

CharacterStates::WalkingState::~WalkingState(){

}

const bool CharacterStates::WalkingState::idle(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

const bool CharacterStates::WalkingState::jumping(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new JumpingState());
    return true;
}

const bool CharacterStates::WalkingState::falling(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}

const bool CharacterStates::WalkingState::attacking(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new AttackingState());
    return true;
}