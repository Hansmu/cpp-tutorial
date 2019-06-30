#include "Player.h"

// :: is the scope resolution operator.
void Player::setName(std::string newName) {
    name = newName;
}

std::string Player::getName() {
    return name;
}

void Player::setHealth(int newHealth) {
    health = newHealth;
}

int Player::getHealth() {
    return health;
}
