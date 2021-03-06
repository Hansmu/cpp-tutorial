// If we include the same header file include in multiple places, then the compiler will give us a duplicate implementation error.
// In order to avoid this, we can include an include guard to make sure the compiler will process this file only once.
// An include guard is a processor directive that makes sure the file is included once. We wrap our header in this directive.
// The name can be anything you want as long as it's unique in the program. If the processor has the directive defined, then it
// Goes to the end of the directive's endif and doesn't process it as it has already been seen.
// #pragma once
// The above could also be used, but not every compiler supports it but most do.
#ifndef CPP_TUTORIAL_PLAYER_H
#define CPP_TUTORIAL_PLAYER_H

#include <string>
#include <iostream>

// Adding a final keyword means that the class cannot be derived from. No extending
// class Player final { }
class Player {
friend void displayPlayerName(Player &player);
friend Player operator-(const Player &obj);
friend std::ostream &operator<<(std::ostream &os, const Player &rhs);
friend std::istream &operator>>(std::istream &in, Player &rhs); // Since we're getting a value from the input, we won't have it as const
// As we will be overwriting it.

private:
    // We don't want to use include namespace in header files because every file that includes them is going to get them.
    // It can unexpectedly change the meaning of code in any other files that include this header.
    std::string name;
    int health;
    int* currentX;
    static int numberOfPlayers;

public:
    // Copy constructor. It is called when a copy has to be made. For example when an object is passed by value to a function as a parameter
    // Or returning an object from a function by value.
    // If it isn't defined, then a compiler generates a default one.
    // Pointers will be copied but not the value it is pointing to. This is called a shallow copy.
    // Always define a user defined copy constructor if you're using raw pointers.
    // Has to be passed by reference, otherwise it'd just create an endless loop as you're constantly copying.
    Player(const Player &source);

    // lvalue - points to a specific memory location. So an lvalue is essentially a reference. Lvalue references are declared with a single &.
    // rvalue - doesn't point to anywhere. Rvalue references are declared with two &. (&&)
    // int& setGlobal() {
    //      return global;
    //  }
    //  setGlobal() = 400;
    // The above works because the function is returning a reference, thus it is returning an lvalue. If it would just
    // return a number, then it'd be a rvalue and the assignment would not be possible.
    //
    // Copy constructors are called whenever a compiler needs to create a copy of our object.
    // If our object contains a raw pointer, then we need to implement deep copy. We need to allocate space for the pointer
    // And then copy its contents. The move constructor addresses this by moving the reference rather than copying it in the case of an rvalue.
    // If a move constructor is not implemented, then a copy constructor is called. Implementing a move constructor is good
    // for efficiency. A move constructor might not always be called as C++ may optimize the copying away. Sometimes
    // not even a copy constructor can be seen. This could be due to a thing called copy elision.
    Player(Player &&source);
    Player(int currentX);
    Player(std::string name = "Player", int health = 100);

    // Destructors are proceeded with a tilde and they are automatically run when an object is destroyed. Only 1 destructor
    // Is allowed per class, it cannot be overloaded. Useful for releasing memory and other resources.
    // When the object memory is released or they go out of scope the destructor is called.
    virtual ~Player(); // If a function has virtual functions, then that class should supply a virtual destructor.

    void setName(std::string newName);
    // In order to call methods on a const object we have to tell the compiler that a certain method will not modify the class object.
    std::string getName() const;

    void setHealth(int newHealth);
    int getHealth() const;

    int getCurrentX();

    void attack();

    static int getNumberOfPlayers();

    Player &operator=(const Player &player);
    Player &operator=(Player &&player);

    Player operator++(int); //Unary operators do not take a parameter as you have a single parameter.
    Player operator+(const Player &rightHandSide) const; // Binary ones take a parameter.

    bool operator==(const Player &rhs) const;

    // Add final here means that the function cannot be overriden by a child class
    // virtual void move() final;
    // If we'd add = 0 to the end, then we'd be defining an abstract class.
    // virtual void move() = 0;
    virtual void move();
};


#endif //CPP_TUTORIAL_PLAYER_H
