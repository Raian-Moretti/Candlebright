#include "AttackingState.hpp"

CharacterStates::AttackingState::AttackingState(): CharacterState(STATE_ATTACKING){

}

CharacterStates::AttackingState::~AttackingState(){

}

const bool CharacterStates::AttackingState::idle(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

const bool CharacterStates::AttackingState::falling(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}