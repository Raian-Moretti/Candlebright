#include "Player.hpp"

Player::Player(sf::View& _view, string _name):
        Listener(),
        view(_view), name(_name){

    player.setSize({20,60});
    player.setFillColor(sf::Color::Blue);
    setPos({50.0, 600});
    moveSpeed = 1.5;
    jumpHeight = 75;
    maxVelocityX = 0.001;
    maxVelocityY = 100;
    isJumping = false;
    finalJumpHeight=0;
    world = NULL;
}
Player::~Player(){}

void Player::move(sf::Vector2f vec){
    player.setPosition({player.getPosition().x + vec.x,
                        player.getPosition().y + vec.y});
    if(player.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  > -50   && vec.x > 0)
        view.move({vec.x,0});
    if(player.getPosition().x - (view.getCenter().x+((view.getSize().x)/2))  < -550  && vec.x < 0)
        view.move({vec.x,0});
}

void Player::setPos(sf::Vector2f newPos) {
    player.setPosition(newPos);
}

void Player::moveRight(){
    move({moveSpeed,0});
}

void Player::moveLeft(){
    Player::move({-moveSpeed,0});
}

void Player::jump(){

    acc.y -= 2.50;
    move({0,-2.50});
    isJumping=true;

}

void Player::onUpdate(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(acc.x < maxVelocityX)
            acc.x += 10;
        if(acc.x > maxVelocityX) acc.x = maxVelocityX;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(acc.x > -maxVelocityX)
            acc.x -= 10;
        if(acc.x < -maxVelocityX) acc.x = -maxVelocityX;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && world->isColliding(player.getGlobalBounds()) == true){
        if(!isJumping){
            if(acc.y < maxVelocityY)
                acc.y += jumpHeight;
            if(acc.y > maxVelocityY) acc.y = maxVelocityY;
            finalJumpHeight = (player.getPosition().y) - jumpHeight;

        }
    }

    if(acc.x > 0.001){
        acc.x -= 1 * abs(acc.x*0.09);
        moveRight();
    }else if(acc.x < -0.001){
        acc.x += 1 * abs(acc.x*0.09);
        moveLeft();
    }
    if(acc.y > 0.001){
        jump();
    }
    cout<<player.getPosition().y<<','<<finalJumpHeight<<endl;
    if(player.getPosition().y < finalJumpHeight + 5)
        isJumping=false;
    if(player.getPosition().y > 800)
        respawn();
}


void Player::drawTo(sf::RenderWindow &window) {
    window.draw(player);
}
void Player::fall(){
    if(!isJumping)
        move({0,2.50});
}

sf::FloatRect Player::getRect(){
    return player.getGlobalBounds();
}
void Player::respawn(){

    setPos({50.0, 600});
}
