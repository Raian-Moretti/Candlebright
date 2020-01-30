#include "Ghost.hpp"

Characters::Ghost::Ghost(sf::Vector2f pos){
    setPosition(pos);
    originalPos = pos;
    moveSpeed = 0.5f;
    jumpHeight = 80.0f;
    maxSlideX = 0.001f;
    maxSlideY = 80.0f;
    finalJumpHeight = 0.0f;
    type = 1;
    score = 4;

    health = 100.0f;
    damage = 5.0f;
    range = 10.0f;
    attackChance = 0.15f / 60.0f; // 15%
    attackSpeed = 250.0f;

    setState(CharacterStates::CharacterState::STATE_WALKING);
    setFacingRight();

    anim = new AnimManager(&eSprite, sf::Vector2i(35, 60));
    anim->addSheet("walk", "sprites/Ghost/new-ghost-idle.png");
    anim->addSheet("attack", "sprites/Ghost/new-ghost-shriek.png", 3);
}
Characters::Ghost::~Ghost(){ }

void Characters::Ghost::move(const sf::Vector2f& _move){
    eSprite.move(_move);
}

void Characters::Ghost::setPosition(sf::Vector2f _pos){
    eSprite.setPosition(_pos);
}

const sf::Vector2f Characters::Ghost::getPosition() const {
    return eSprite.getPosition();
}

const sf::FloatRect Characters::Ghost::getRect() const {
    return eSprite.getGlobalBounds();
}
void Characters::Ghost::fall(){
    move(sf::Vector2f(0, 0.05));
}

void Characters::Ghost::moveRight(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(moveSpeed, 0));
    setFacingRight();
    setState(CharacterStates::CharacterState::STATE_WALKING);
}

void Characters::Ghost::moveLeft(){
    if(anim->isLocked()) return;
    move(sf::Vector2f(-moveSpeed, 0));
    setFacingRight(false);
    setState(CharacterStates::CharacterState::STATE_WALKING);
}

void Characters::Ghost::update(){
    sf::Vector2f pos = eSprite.getPosition();

    if(getState() == CharacterStates::CharacterState::STATE_WALKING){
        if(!isFacingRight()){
            if(!collidingLeft)
                moveLeft();
            else
                setFacingRight();
            if(std::abs(pos.x) < std::abs(originalPos.x-30)) setFacingRight();
        }else{
            if(!collidingRight)
                moveRight();
            else
                setFacingRight(false);
            if(std::abs(pos.x) > std::abs(originalPos.x+30)) setFacingRight(false);
        }
    }

    if(((float) rand()) / (float) RAND_MAX <= attackChance && getState() == CharacterStates::CharacterState::STATE_WALKING){
        attack();
    }

    if(getState() == CharacterStates::CharacterState::STATE_ATTACKING){
        if(animClock.getElapsedTime().asMilliseconds() >= 450){
            animClock.restart();
            anim->play("attack", true);
            if(anim->getCount() >= 4){
                anim->stop();
                setState(CharacterStates::CharacterState::STATE_IDLE);
            }
        }
    }else{
        if(animClock.getElapsedTime().asMilliseconds() >= 200){
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

void Characters::Ghost::draw(System::Engine& engine) const  {
    engine.draw(eSprite);
    healthBar.draw(engine);
}

void Characters::Ghost::takeDamage(const float& _damage){
    health -= _damage;
    healthBar.setHealth(health);
    move(sf::Vector2f(0.0f, -1.f));
}

void Characters::Ghost::attack(){
    if(attackTimer.getElapsedTime().asSeconds() < 1/attackSpeed) return;
    setState(CharacterStates::CharacterState::STATE_ATTACKING);
    anim->play("attack", true);
    animClock.restart();
}
