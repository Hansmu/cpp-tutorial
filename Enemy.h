#ifndef CPP_TUTORIAL_ENEMY_H
#define CPP_TUTORIAL_ENEMY_H

#include "Player.h"

class Enemy : public Player {
private:
    std::string masterName;
public:
    void attack();
    const std::string &getMasterName() const;
    void setMasterName(const std::string &masterName);
    Enemy(std::string masterName);
    Enemy(const Enemy &source);
};


#endif //CPP_TUTORIAL_ENEMY_H
