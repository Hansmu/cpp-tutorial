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
    // Static binding is the default in C++. That means it will call the parent's method instead of the child's as it is in Java.
    // So an Account withdraw will be called, instead of its child SavingAccount withdraw. Happens in compile time.
    // Dynamic binding is what Java uses by default. Happens in run time.
    // Virtual doesn't have to be used again, but it's clearer.
    virtual void move() override; // Function definitions have to match exactly when compared to the parent's, otherwise it won't be an override, but a new definition.
    // Use the override specifier to make sure that override happens. Very similar method signatures can otherwise produce errors, where
    // Overriding isn't actually done, but new methods are defined.
    virtual ~Enemy();
};


#endif //CPP_TUTORIAL_ENEMY_H
