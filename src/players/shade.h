#ifndef ___SHADE_H___
#define ___SHADE_H___

#include "player.h"

class Shade : public Player {
    public:
        Shade();
        void addReward(Enemy* enemy) override;
        
};

#endif