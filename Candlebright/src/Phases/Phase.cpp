#include "Phase.hpp"

Phase::Phase(): col_mngr(&things){

}
Phase::~Phase(){
    entities.clear();
    things.clear();
    characters.clear();
    obstacles.clear();
}

void Phase::update(){
    col_mngr.checkCollisions();
    entities["update"];

    std::set<Characters::Character*> killBuffer;
    checkAttack(&killBuffer);
    checkObstacles(&killBuffer);

    std::set<Characters::Character *>::iterator chr;
    for(chr = killBuffer.begin(); chr != killBuffer.end(); ++chr){
        things.remove(*chr);
        characters.remove(*chr);
        if((*chr)->getType() != 0){
            entities.remove(*chr); // Continua imprimindo jogadores mortos na tela
            delete *chr;
        }else{
            (*chr)->setDead(true);
        }
    }
}

void Phase::drawAll(System::Engine& engine){
    draw(engine);
    for(int i = 0; i < entities.size(); i++){
        if(entities[i] == NULL) continue;
        entities[i]->draw(engine);
    }
}

void Phase::draw(System::Engine& engine) const {
    engine.draw(*background);
}

void Phase::gravity(){
    std::vector<Thing *>::iterator itr;
    for(itr = things.begin(); itr != things.end(); ++itr){
        Thing* obj1 = *itr;
        if(!obj1->isCollidingDown()){
            obj1->fall();
        }
    }
}

const float Phase::getDistance(const sf::Vector2f& p1, const sf::Vector2f& p2) const {
    return sqrt(pow(p1.x-p2.x,2.0) + pow(p1.y-p2.y,2.0));
}

void Phase::loadEnemies(const int act_world){
    /* Remove todos os Characters */
    while(!characters.characters.empty()){
        entities.remove(*characters.begin());
        things.remove(*characters.begin());
        characters.remove(*characters.begin());
    }

    /* Carrega os Inimigos */
    std::string line;
    std::ifstream file("Save/GameSave.txt");
    Characters::Enemy* enemy;
    if(file.is_open())
    {
        getline(file,line);
        if(act_world != getIntFromString(line))
        {
            std::cerr << "Mundo não condizente com o jogo já salvo." << std::endl;
            return;
        }
        while (getline(file,line))
        {
            const int type = getIntFromString(line.substr(0, line.find(',') + 1));
            if(type != 1) continue;

            line = line.substr(line.find(',') + 1, line.size());
            const int subtype = getIntFromString(line.substr(0, line.find(',') + 1));

            line = line.substr(line.find(',') + 1, line.size());
            const float health = getIntFromString(line.substr(0, line.find(',') + 1));

            line = line.substr(line.find(',') + 1, line.size());
            const float px = getFloatFromString(line.substr(0, line.find(',') + 1));
            line = line.substr(line.find(',') + 1, line.size());
            const float py = getFloatFromString(line);

            if(type == 1) // Inimigo
            {
                if(subtype == 1)
                {
                    enemy = new Characters::Zombie(sf::Vector2f(px, py));
                }
                else if(subtype == 2)
                {
                    enemy = new Characters::Dressed_Zombie(sf::Vector2f(px, py));
                }
                else if(subtype == 3)
                {
                    enemy = new Characters::Ghost(sf::Vector2f(px, py));
                }
                else if(subtype == 4)
                {
                    enemy = new Characters::Hell_Demon(sf::Vector2f(px, py));
                }
                else if(subtype == 5)
                {
                    enemy = new Characters::Sylathus(sf::Vector2f(px, py));
                }
            }
            enemy->setHealth(health);
            addCharacter(enemy);
        }
        file.close();
    }
}

const sf::Vector2f Phase::getRandomPosition(const sf::View& view){
    sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f);

    float   left    = view.getCenter().x - view.getSize().x/2,
            right   = view.getCenter().x + view.getSize().x/2;

    float   top     = view.getCenter().y - view.getSize().y/2,
            bottom  = view.getCenter().y + view.getSize().y/2;

    float   random_x,
            random_y;

    int     tries = 0;

    while(tries < 1000){
        tries++;

        random_x = left + static_cast <float> (rand()) / ( static_cast <float> ( RAND_MAX/(right-left) ));
        random_y = top  + static_cast <float> (rand()) / ( static_cast <float> ( RAND_MAX/(bottom-top) ));

        pos = sf::Vector2f(random_x, random_y);


        /* Determina melhor Y */
        std::list<Obstacles::Obstacle *>::iterator plt;
        bool best_y_success = false;
        float best_distance = -1.f;
        float best_y = 0.0f;
        for(plt = obstacles.begin(); plt != obstacles.end(); ++plt){
            if((*plt)->getType() != 0) continue; // Spawn apenas em cima de plataformas
            if(random_x < (*plt)->getRect().left+100 || random_x > (*plt)->getRect().left+(*plt)->getRect().width-100) continue; // random_x fora das bordas da Plataforma
            float dist = std::abs(pos.y-(*plt)->getRect().top);
            if(dist < best_distance || best_distance == -1.f){
                best_y = (*plt)->getRect().top;
                best_distance = dist;
            }
            best_y_success = true;
        }
        if(!best_y_success || best_y == 0.0f) continue;
        /* Melhor Y determinado */

        
        
        pos = sf::Vector2f(random_x, best_y - 30.0);



        /* Testa posição de outros Obstáculos */
        std::list<Obstacles::Obstacle *>::iterator obs;
        bool obstacles_test_success = true;
        for(obs = obstacles.begin(); obs != obstacles.end(); ++obs){
            if((*obs)->getType() == 0 || (*obs)->getType() == 1) continue; // Ignora plataformas e paredes
            if(getDistance(pos,(*obs)->getPosition()) < (*obs)->getRange() + 15.0){
                obstacles_test_success = false;
                break;
            }   
        }
        if(!obstacles_test_success) continue;
        /* Passou pelo teste de Obstáculos */



        /* Testa posição de Personagens */
        std::set<Characters::Character *>::iterator chr;
        bool char_test_success = true;
        for(chr = characters.begin(); chr != characters.end(); ++chr){
            if(getDistance(pos,(*chr)->getPosition()) < 100.0){
                char_test_success = false;
                break;
            }
        }
        if(!char_test_success) continue;
        /* Passou pelo teste de Personagens */

        break;
    }

    if(tries == 1000){
        std::cerr << "Erro ao tentar achar alguma posição aleatória dentro do mapa" << std::endl;
        return sf::Vector2f(0.0f, 0.0f);
    }

    return pos;
}

void Phase::checkAttack(std::set<Characters::Character*>* killBuffer){
    std::set<Characters::Character *>::iterator issuer;
    for(issuer = characters.begin(); issuer != characters.end(); ++issuer){
        if( (*issuer)->getState() == CharacterStates::CharacterState::STATE_ATTACKING && 
            (*issuer)->getAttackClock()->getElapsedTime().asMilliseconds() >= (*issuer)->getAttackSpeed()){
            std::set<Characters::Character *>::iterator damaged;
            for(damaged = characters.begin(); damaged != characters.end(); ++damaged){
                /* Exclusões */
                if(issuer == damaged) continue; // auto-dano
                if((*issuer)->getType() == (*damaged)->getType()) continue; // Não ataca personagens do mesmo tipo
                if(getDistance((*issuer)->getPosition(), (*damaged)->getPosition()) > (*issuer)->getRange()) continue; // Fora do range

                if( (*issuer)->isFacingRight() && (*damaged)->getPosition().x < (*issuer)->getPosition().x) continue; // Previnir ataques de costas
                if(!(*issuer)->isFacingRight()  && (*damaged)->getPosition().x > (*issuer)->getPosition().x) continue; // Previnir ataques de costas
                
                (*damaged)->takeDamage((*issuer)->getDamage());

                if((*damaged)->getHealth() <= 0){
                    killBuffer->insert(*damaged);
                }
            }
            (*issuer)->getAttackClock()->restart();
        }
    }
}

void Phase::checkObstacles(std::set<Characters::Character*>* killBuffer){
    std::list<Obstacles::Obstacle *>::iterator obs;
    for(obs = obstacles.begin(); obs != obstacles.end(); ++obs){
        if((*obs)->getAttackClock()->getElapsedTime().asMilliseconds() < (*obs)->getAttackRate()) continue; // Attack rate
        std::set<Characters::Character *>::iterator chr;
        for(chr = characters.begin(); chr != characters.end(); ++chr){
            if((*chr)->getType() != 0) continue; // Só afeta players

            if((*obs)->getType() == 2){ // Fogo
                if(getDistance((*obs)->getPosition(), (*chr)->getPosition()) > (*obs)->getRange()) continue; // Range

                (*chr)->takeDamage((*obs)->getDamage());

                if((*chr)->getHealth() <= 0){
                    killBuffer->insert(*chr);
                }
            }else if((*obs)->getType() == 3){ // Black Hole
                if(getDistance((*obs)->getPosition(), (*chr)->getPosition()) > (*obs)->getRange()) continue; // Range

                if(getDistance((*obs)->getPosition(), (*chr)->getPosition()) < (*obs)->getRange()*0.2){
                    (*chr)->takeDamage((*obs)->getDamage());

                    if((*chr)->getHealth() <= 0){
                        killBuffer->insert(*chr);
                    }
                }
                
                if((*chr)->getPosition().x < (*obs)->getPosition().x){ // Player a esquerda do buraco
                    (*chr)->move(sf::Vector2f(3.f, 0.0f));
                }else{
                    (*chr)->move(sf::Vector2f(-3.f, 0.0f));
                }
            }
        }
        (*obs)->getAttackClock()->restart();
    }
}

void Phase::addEntity(System::Entity* _e){
    entities.add(_e);
}

void Phase::addThing(Thing* _thing){
    addEntity(static_cast<System::Entity*>(_thing));
    things.add(_thing);
}

void Phase::addCharacter(Characters::Character* _char){
    addThing(static_cast<Thing*>(_char));
    characters.add(_char);
}

void Phase::addObstacle(Obstacles::Obstacle* _obs){
    addThing(static_cast<Thing*>(_obs));
    obstacles.add(_obs);
}

const int Phase::getIntFromString(const std::string& _str) const {
    int result;
    sscanf(_str.c_str(), "%d", &result);
    return result;
}

const float Phase::getFloatFromString(const std::string& _str) const {
    float result;
    sscanf(_str.c_str(), "%f", &result);
    return result;
}