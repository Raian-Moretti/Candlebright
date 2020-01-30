#include "Zombie.hpp"

Characters::Zombie::Zombie(sf::Vector2f pos){
    setPosition(pos);
    originalPos = pos;
    moveSpeed = 1.5f;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    type = 1;
    score = 1;

    health = 100.0f;
    damage = 5.0f;
    range = 50.0f;
    attackChance = 0.25f / 60.0f; // 25%
    attackSpeed = 250.0f;

    setState(CharacterStates::CharacterState::STATE_IDLE);
    setFacingRight();

    anim = new AnimManager(&eSprite, sf::Vector2i(20, 50));
    anim->addSheet("walk", "sprites/Zombie/new-zombie-walking.png");

    healthBar.setSize(sf::Vector2f(40.0f, 5));
}
Characters::Zombie::~Zombie(){ }

void Characters::Zombie::move(const sf::Vector2f& _move){
    eSprite.move(_move);
}

void Characters::Zombie::setPosition(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Characters::Zombie::getPosition() const {
    return eSprite.getPosition();
}

const sf::FloatRect Characters::Zombie::getRect() const {
    return eSprite.getGlobalBounds();
}
void Characters::Zombie::fall(){
    if(getState() != CharacterStates::CharacterState::STATE_JUMPING){
        move(sf::Vector2f(0, 2.50));
    }
}

void Characters::Zombie::moveRight(){
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
    setState(CharacterStates::CharacterState::STATE_WALKING);
}

void Characters::Zombie::moveLeft(){
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
    setState(CharacterStates::CharacterState::STATE_WALKING);
}

void Characters::Zombie::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterStates::CharacterState::STATE_WALKING){
        attack();
    }

    if(getState() == CharacterStates::CharacterState::STATE_FALLING && collidingDown){
        setState(CharacterStates::CharacterState::STATE_IDLE);
    }

    if(getState() == CharacterStates::CharacterState::STATE_JUMPING && collidingUp){
        velocity.y = 0;
        setState(CharacterStates::CharacterState::STATE_FALLING);
    }

    if(getState() == CharacterStates::CharacterState::STATE_WALKING){
        if(!isFacingRight()){
            if(!collidingLeft)
                moveLeft();
            else
                setFacingRight();
            if(std::abs(pos.x) < std::abs(originalPos.x-100)) setFacingRight();
        }else{
            if(!collidingRight)
                moveRight();
            else
                setFacingRight(false);
            if(std::abs(pos.x) > std::abs(originalPos.x+100)) setFacingRight(false);
        }

        if(animClock.getElapsedTime().asMilliseconds() >= 150){
            animClock.restart();
            anim->play("walk");
        }
        if(isFacingRight()){
            anim->setScale(sf::Vector2f(-1.f, 1.f));
        }else{
            anim->setScale(sf::Vector2f(1.f, 1.f));
        }
    }else if(getState() == CharacterStates::CharacterState::STATE_ATTACKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 500){
            setState(CharacterStates::CharacterState::STATE_IDLE);
        }
    }

    if(getState() == CharacterStates::CharacterState::STATE_IDLE) setState(CharacterStates::CharacterState::STATE_WALKING);

    healthBar.setPosition(sf::Vector2f(getPosition().x-20, getPosition().y+50));
}

void Characters::Zombie::draw(System::Engine& engine) const  {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Characters::Zombie::takeDamage(const float& _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0.0f, -1.f));
    moveSpeed += moveSpeed * 0.05;
}

void Characters::Zombie::attack(){
    setState(CharacterStates::CharacterState::STATE_ATTACKING);
    animClock.restart();
}
