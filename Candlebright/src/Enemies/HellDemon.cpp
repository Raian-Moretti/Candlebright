#include "HellDemon.hpp"

Characters::Hell_Demon::Hell_Demon(sf::Vector2f pos){
    setPosition(pos);
    originalPos = pos;
    moveSpeed = 0.25;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    type = 1;
    score = 3;

    health = 250.0f;
    damage = 5.0f;
    range = 75.0f;
    attackChance = 0.15f / 60.0f; // 15%
    attackSpeed = 150.0f;

    setState(CharacterStates::CharacterState::STATE_WALKING);
    setFacingRight();

    anim = new AnimManager(&eSprite, sf::Vector2i(45, 60));
    anim->addSheet("walk", "sprites/Hell-Demon/new-hell-beast-idle.png");
    anim->addSheet("attack1", "sprites/Hell-Demon/new-hell-beast-burn.png");
    anim->addSheet("attack2", "sprites/Hell-Demon/new-hell-beast-breath.png", 3);

    healthBar.setSize(sf::Vector2f(50.0f, 7.f));
    healthBar.setMaxHealth(health);
}
Characters::Hell_Demon::~Hell_Demon(){ }

void Characters::Hell_Demon::move(const sf::Vector2f& _move){
    eSprite.move(_move);
}

void Characters::Hell_Demon::setPosition(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Characters::Hell_Demon::getPosition() const {
    return eSprite.getPosition();
}

const sf::FloatRect Characters::Hell_Demon::getRect() const {
    return eSprite.getGlobalBounds();
}
void Characters::Hell_Demon::fall(){
    if(getState() != CharacterStates::CharacterState::STATE_JUMPING){
        move(sf::Vector2f(0, 2.50));
    }
}

void Characters::Hell_Demon::moveRight(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
    setState(CharacterStates::CharacterState::STATE_WALKING);
}

void Characters::Hell_Demon::moveLeft(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
    setState(CharacterStates::CharacterState::STATE_WALKING);
}

void Characters::Hell_Demon::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if( getState() == CharacterStates::CharacterState::STATE_FALLING && collidingDown ){
        setState(CharacterStates::CharacterState::STATE_IDLE);
    }

    if(getState() == CharacterStates::CharacterState::STATE_WALKING){
        if(!isFacingRight()){
            if(!collidingLeft)
                moveLeft();
            else
                setFacingRight();
            if(std::abs(pos.x) < std::abs(originalPos.x-5)) setFacingRight();
        }else{
            if(!collidingRight)
                moveRight();
            else
                setFacingRight(false);
            if(std::abs(pos.x) > std::abs(originalPos.x+5)) setFacingRight(false);
        }
    }
    if(collidingUp){
        velocity.y = 0;
        setState(CharacterStates::CharacterState::STATE_FALLING);
    }

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterStates::CharacterState::STATE_WALKING){
        attack();
    }

    if(getState() == CharacterStates::CharacterState::STATE_ATTACKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 200){
            animClock.restart();
            anim->play("attack1", true);
            if(anim->getCount() > 10){
                anim->stop();
                setState(CharacterStates::CharacterState::STATE_IDLE);
            }
        }
    }else if(getState() == CharacterStates::CharacterState::STATE_WALKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 75){
            animClock.restart();
            anim->play("walk");
        }
        if(isFacingRight()){
            anim->setScale(sf::Vector2f(-1.f, 1.f));
        }else{
            anim->setScale(sf::Vector2f(1.f, 1.f));
        }
    }

    if(getState() == CharacterStates::CharacterState::STATE_IDLE) setState(CharacterStates::CharacterState::STATE_WALKING);

    healthBar.setPosition(sf::Vector2f(getPosition().x-25, getPosition().y+60));
}

void Characters::Hell_Demon::draw(System::Engine& engine) const  {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Characters::Hell_Demon::takeDamage(const float& _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0.0f, -1.f));
}

void Characters::Hell_Demon::attack(){
    setState(CharacterStates::CharacterState::STATE_ATTACKING);

    anim->play("attack1", true);
    animClock.restart();
}
