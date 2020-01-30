#include "Character.hpp"

Characters::Character::Character(){
    currentState = NULL;
}

Characters::Character::~Character(){

}

bool Characters::Character::setState(const CharacterStates::CharacterState::State _newState){
    if(currentState != NULL){
        if(_newState == currentState->getState()) return true; // Não há necessidade de "renovar" o estado
        if(anim->isLocked()) return false; // Personagem ocupado com uma animação, não sobrepor
        //delete currentState; -> Movido para respectiva função
    }else{
        currentState = new CharacterStates::IdleState();
    }
    switch (_newState){
        case CharacterStates::CharacterState::STATE_IDLE:
            return currentState->idle(this);
        case CharacterStates::CharacterState::STATE_WALKING:
            return currentState->walking(this);
        case CharacterStates::CharacterState::STATE_JUMPING:
            return currentState->jumping(this);
        case CharacterStates::CharacterState::STATE_FALLING:
            return currentState->falling(this);
        case CharacterStates::CharacterState::STATE_ATTACKING:
            return currentState->attacking(this);
        default:
            return currentState->idle(this);
    }
}

const sf::Vector2f Characters::Character::getSize() const {
    return sf::Vector2f(getRect().width, getRect().height);
}

const float Characters::Character::getDamage() const {
    return damage;
}

const float Characters::Character::getAttackSpeed() const {
    return attackSpeed;
}

sf::Clock* Characters::Character::getAttackClock(){
    return &attackTimer;
}

const float Characters::Character::getRange() const {
    return range;
}

const float Characters::Character::getHealth() const {
    return health;
}

const short Characters::Character::getType() const {
    return type;
}

const short Characters::Character::getSubType() const {
    return 0;
}

const CharacterStates::CharacterState::State Characters::Character::getState() const {
    return currentState->getState();
}

const CharacterStates::CharacterState* Characters::Character::getCharacterState() const {
    return currentState;
}

void Characters::Character::setCharacterState(CharacterStates::CharacterState* _newState){
    currentState = _newState;
}

void Characters::Character::setFacingRight(bool _facingRight){
    facingRight = _facingRight;
}

const bool Characters::Character::isFacingRight() const {
    return facingRight;
}

void Characters::Character::setHealth(const float& _health){
    health = _health;
}