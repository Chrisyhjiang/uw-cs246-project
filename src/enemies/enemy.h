#ifndef ___ENEMY_H___
#define ___ENEMY_H___

#include <string>
#include "../character.h"
#include "../floors/cell.h"


class Enemy : public Character{
    private:
        char symbol;
        bool movable;
        bool isMoved;

    public:
    
        Enemy(int hp, int atk, int def, string race, char symbol);
        ~Enemy() override;
        char getSymbol();
        void setSymbol(char symbol);
        void attachPlayer();
        bool isPlayerInRange();
        void takeDamage(int damage);
        virtual int calculateDamageToPlayer() = 0;
        bool isDead() override;
        bool hasMoved();
        void setMoved(bool moved);
        int giveRewardToPlayer();
        void move(Cell* cell);
        virtual bool isMovable() = 0;
        
};

#endif