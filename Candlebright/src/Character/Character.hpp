#pragma once
#include <SFML/Graphics.hpp>

#include "../Thing.hpp"
#include "../AnimManager.hpp"
#include "../Animatable.hpp"
#include "../System/Engine.hpp"

#include "HealthBar.hpp"
#include "CharacterState.hpp"
#include "IdleState.hpp"
#include "WalkingState.hpp"
#include "JumpingState.hpp"
#include "FallingState.hpp"
#include "AttackingState.hpp"

namespace Characters {
    class Character : public Animatable {
        public:
            Character();
            virtual ~Character();
            virtual void move(const sf::Vector2f& _move) = 0;
            virtual void takeDamage(const float& _damage) = 0;
            virtual void setPosition(sf::Vector2f _pos) = 0;

            /* Funções de get */
            virtual const sf::Vector2f getPosition() const = 0;
            virtual const sf::Vector2f getSize() const;
            virtual const float getDamage() const;
            virtual const float getAttackSpeed() const;
            virtual sf::Clock* getAttackClock();
            virtual const float getRange() const;
            virtual const float getHealth() const;

            /*  0 = Player
                1 = Enemy */
            virtual const short getType() const;
            /* Específico para cada "sub-classe" */
            virtual const short getSubType() const;

            /* CharacterState com enum */
            virtual bool setState(const CharacterStates::CharacterState::State _newState);
            virtual const CharacterStates::CharacterState::State getState() const;
            /* CharacterState no âmbito POO */
            virtual void setCharacterState(CharacterStates::CharacterState* _newState);
            virtual const CharacterStates::CharacterState* getCharacterState() const;

            virtual void setFacingRight(bool _facingRight = true);
            virtual const bool isFacingRight() const;

            virtual void setHealth(const float& _health);

            const bool isDead() const { return dead; }
            void setDead(bool _dead){ this->dead = _dead; }

        protected:
            sf::Vector2f velocity;
            float health;
            float moveSpeed;
            float jumpHeight;
            float finalJumpHeight;
            float maxSlideX;
            float maxSlideY;
            float damage;
            float range;

            short type;

            bool facingRight;

            HealthBar healthBar;

            CharacterStates::CharacterState* currentState;

            sf::Clock attackTimer;
            float attackSpeed; // Intervalo entre os ataques em milissegundos

            bool dead;
    };
}