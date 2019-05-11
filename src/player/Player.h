class Player{
    private:
        string name;
        int score;
        float moveSpeed;

        sf::RectangleShape player;
        sf::View* view;

        void move(sf::Vector2f vec){
            player.setPosition({player.getPosition().x + vec.x, player.getPosition().y + vec.y});
            if(player.getPosition().x > 100)
                view->move({vec.x,0});
            else if(player.getPosition().x < 100)
                view->move({vec.x,0});
        }
    public:
        Player(string _name = ""):
            name(_name){
            player.setSize({20,60});
            player.setFillColor(sf::Color::Blue);
            setPos({50, 700});
            moveSpeed = 0.25;
        }
        ~Player(){}
        void drawTo(sf::RenderWindow &window) {
            window.draw(player);
        }
 
        void setPos(sf::Vector2f newPos) {
            player.setPosition(newPos);
        }

        void moveRight(){
            move({moveSpeed,0});
        }
        void moveLeft(){
            move({-moveSpeed,0});
        }

        void setView(sf::View* _view){
            view = _view;
            //view->setCenter(player.getPosition());
        }

};