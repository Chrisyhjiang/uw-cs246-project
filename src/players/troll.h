#ifndef ___TROLL_H___
#define ___TROLL_H___

#include "player.h"

class Troll : public Player {
    public:
        Troll();
        int calculateDmgToEnemy(Enemy* enemy) override;
        void addReward(Enemy* enemy) override;
};

#endif