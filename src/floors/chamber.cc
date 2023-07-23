#include "chamber.h"

Chamber::Chamber(int id) : id{id}{}

Chamber::~Chamber() {
    while (!cells.empty()) {
        Cell *c = cells.back();
        delete c;
        cells.pop_back();
    }
}

void Chamber::renderEnemy() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        c = cells.at(rand() % cells.size());
    }

    int m = rand() % 18;
    char e;
    if (0 <= m && m < 4) {
        e = ENEMY_HUMAN;
    } else if (4 <= m && m < 6) {
        e = ENEMY_DWARF;
    } else if (6 <= m && m < 11) {
        e = ENEMY_HALFING; 
    } else if (11 <= m && m < 13) {
        e = ENEMY_ELF;
    } else if (13 <= m && m < 15) {
        e = ENEMY_ORC;
    } else {
        e = ENEMY_MERCHANT;
    }
    Enemy* en = EnemyFactory::createEnemy(e, Character::getRace());
    c->setSymbol(e);
    c->setCharacter(en);
    en->setX(c->getRow());
    en->setY(c->getCol());
}

void Chamber::renderTreasure() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }
    int m = rand() % 8;
    char e;
    ItemDecorator* gold;
    if (0 <= m && m < 5) {
        e = NORMAL_GOLD;
    } else if (5 <= m && m < 6) {
        e = DRAGON_GOLD;
    } else {
        e = SMALL_GOLD;
    }
    switch(e){
        case NORMAL_GOLD:
            gold = new NormalTreasure(nullptr);
            break;
        case SMALL_GOLD:
            gold = new SmallTreasure(nullptr);
            break;
        case DRAGON_GOLD:   
            gold = new DragonTreasure(nullptr);
            break;
        default:
            gold = nullptr;
            break;
    }
    c->setSymbol(GOLD);
    c->setCharacter(gold);
    gold->setX(c->getRow());
    gold->setY(c->getCol());
}

void Chamber::addCell(Cell* c) {
    cells.push_back(c);
}

void Chamber::renderPotion() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }
    int m = rand() % 6;
    ItemDecorator* potion;
    if (m == 0) {
        potion = new BoostAtkPotion(nullptr);
    } else if (m == 1) {
        potion = new WoundAtkPotion(nullptr);
    } else if (m == 2) {
        potion = new BoostDefPotion(nullptr);
    } else if (m == 3) {
        potion = new WoundDefPotion(nullptr);
    } else if (m == 4) {
        potion = new RestoreHealthPotion(nullptr);
    } else {
        potion = new PoisonHealthPotion(nullptr);
    }
    c->setSymbol(POTION);
    c->setCharacter(potion);
    potion->setX(c->getRow());
    potion->setY(c->getCol());
}

void Chamber::renderStairs() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }
    c->setSymbol(STAIRS);
}
