#include "Player.h"

Player::Player() : name{"Player"}, health{100} {

}

Player::Player(std::string name) : name{name}, health{100}{
}

Player::Player(std::string name, int health) : name{name}, health{health}{
}

Player::~Player() {
    std::cout << "Destroyed!" << std::endl;
}

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
