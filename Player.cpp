#include "Player.h"

// Could also just delegate to another constructor
Player::Player(const Player &source) : name{source.name}, health{source.health} {
    std::cout << "Running copy constructor for: " << source.name << std::endl;
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
