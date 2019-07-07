#include "Player.h"

Player::Player(int currentX) : Player("Player", 100) {
    this -> currentX = new int; // this is a reserved keyword that contains the address of the current object.
    // It's a pointer to the object.
    *(this -> currentX) = currentX;
}

// Could also just delegate to another constructor
Player::Player(const Player &source) : name{source.name}, health{source.health} {
    currentX = new int;
    // Copy the pointer data value
    *currentX = *source.currentX;
    std::cout << "Running copy constructor for: " << source.name << std::endl;
}

// As seen in the above copy constructor we assign a new memory block to our pointer and then copy the pointer data value over.
// With a move constructor we take control of the data. We set the reference of the rvalue to be null and then assign our new object
// That memory block. Thus we take over the created data. Destructor won't free that bit of memory either as the original rvalue
// No longer has a reference to the block. There's no const in the signature because we need to be able to null out its pointer.
Player::Player(Player &&source) : currentX{source.currentX} { // Steal the data
    source.currentX = nullptr; // Null out the pointer
}

Player::Player(std::string name, int health) : name{name}, health{health} {
    Player::numberOfPlayers++;
}

Player::~Player() {
    // With shallow copy a problem arises - if one object gets destroyed, then the memory gets released. The other
    // Object still references that area in memory and will keep using it, even though the data is gone.
    delete currentX;
    std::cout << "Destroyed!" << std::endl;
    Player::numberOfPlayers--;
}

// :: is the scope resolution operator.
void Player::setName(std::string newName) {
    name = newName;
}

std::string Player::getName() const {
    return name;
}

void Player::setHealth(int newHealth) {
    health = newHealth;
}

int Player::getHealth() const {
    return health;
}

int Player::numberOfPlayers {0}; // Cannot be initialized inside of the header.
int Player::getNumberOfPlayers() {
    return numberOfPlayers;
}
