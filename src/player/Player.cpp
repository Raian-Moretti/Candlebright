Player::Player(sf::View& _view, float ground, string _name):
        Listener(),
        view(_view), groundHeight(ground), name(_name){
    
    player.setSize({20,60});
    player.setFillColor(sf::Color::Blue);
    setPos({50.0, ground});
    moveSpeed = 0.1;
    jumpHeight = 150;
    maxVelocity = 15;
    isJumping = false;
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
    if(isJumping) return;
    isJumping = true;
    for(float i = 0.0; i < jumpHeight; i += 0.1){
        move({0,-0.01});
        cout << "jump" << endl;
    }
    for(float i = 0.0; i < jumpHeight; i += 0.1){
        move({0,0.01});
        cout << "jump2" << endl;
    }
    isJumping = false;
}

void Player::onUpdate(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(acc.x < maxVelocity)
            acc.x += 10;
        if(acc.x > maxVelocity) acc.x = maxVelocity;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(acc.x > -maxVelocity)
            acc.x -= 10;
        if(acc.x < -maxVelocity) acc.x = -maxVelocity;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(!isJumping){
            acc.y += jumpHeight;
            isJumping = true;
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
        acc.y -= 0.09;
        move({0,-0.09});
    }else isJumping = false;
    if(player.getPosition().y < groundHeight && isJumping == false){
        move({0,0.09});
    }
}
void Player::drawTo(sf::RenderWindow &window) {
    window.draw(player);
}