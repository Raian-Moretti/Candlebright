#include "IdleState.hpp"

CharacterStates::IdleState::IdleState(): CharacterState(STATE_IDLE){

}

CharacterStates::IdleState::~IdleState(){

}

const bool CharacterStates::IdleState::idle(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new IdleState());
    return true;
}

const bool CharacterStates::IdleState::jumping(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new JumpingState());
    return true;
}

const bool CharacterStates::IdleState::walking(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new WalkingState());
    return true;
}

const bool CharacterStates::IdleState::falling(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new FallingState());
    return true;
}

const bool CharacterStates::IdleState::attacking(Characters::Character* _char){
    delete _char->getCharacterState();
    _char->setCharacterState(new AttackingState());
    return true;
}