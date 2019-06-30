#include "Player.h"

Player::Player(int currentX) {
    this -> currentX = new int;
    *(this -> currentX) = currentX;
}

// Could also just delegate to another constructor
Player::Player(const Player &source) : name{source.name}, health{source.health} {
    currentX = new int;
    // Copy the pointer data value
    *currentX = *source.currentX;
    std::cout << "Running copy constructor for: " << source.name << std::endl;
}

Player::Player(std::string name, int health) : name{name}, health{health}{
}

Player::~Player() {
    // With shallow copy a problem arises - if one object gets destroyed, then the memory gets released. The other
    // Object still references that area in memory and will keep using it, even though the data is gone.
    delete currentX;
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
