#include "Enemy.h"

const std::string &Enemy::getMasterName() const {
    return masterName;
}

void Enemy::setMasterName(const std::string &masterName) {
    Enemy::masterName = masterName;
}

void Enemy::attack() {
    std::cout << "For " << this -> masterName << "!" << std::endl;
    Player::attack();
}

// If the parent constructor is not specified, then it calls the no args constructor.
Enemy::Enemy(std::string masterName) : Player{"Minion for " + masterName, 56} {
    this -> masterName = masterName;
}

// Copy, move and assignment operators aren't inherited by default, have to explicitly call them.
Enemy::Enemy(const Enemy &source) : Player{source} {
    std::cout << "Calling copy constructor" << std::endl;
}

void Enemy::move() {
    std::cout << "Moving for the glory of " << masterName << std::endl;
}

// By default would call the base class destructor, but that might lead to memory leaks if we have separate resources defined in our child classes.
Enemy::~Enemy() {

}