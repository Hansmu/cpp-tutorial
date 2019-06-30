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

class Player {
private:
    // We don't want to use include namespace in header files because every file that includes them is going to get them.
    // It can unexpectedly change the meaning of code in any other files that include this header.
    std::string name;
    int health {100};

public:
    void setName(std::string newName);
    std::string getName();

    void setHealth(int newHealth);
    int getHealth();
};


#endif //CPP_TUTORIAL_PLAYER_H
