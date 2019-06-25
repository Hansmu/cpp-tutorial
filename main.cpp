#include <iostream>

using namespace std;

void variableExamples();

int main() {
    variableExamples();

    return 0;
}

void variableExamples() {
    // Three different ways to initialize an int
    int age = 21;
    int constructorInt (22);
    int arrayLikeInt {23};

    unsigned short examScore {55};
    long populationNumber {1234125125};
    // If we would've used = initialization then if the variable would've been a long we would've got an overflow but the
    // program would have compiled. With {} we got a compilation error instead.
    long long peopleOnEarth {7'600'000'000}; // ' can be used for formatting to have the number more easily readable

    float rate {42.2};
    double someNumber {3.121421241};
    long double largeAmount {2.7e120};

    bool isGameOver {false};

    char initial {'J'};

    short value1 {3000};

    cout << "Hello, World!" << endl;
    cout << age << " " << constructorInt << " " << arrayLikeInt << endl;

    const double pricePerRoom {30};
    const double salesTax {0.06};
    const int estimateExpirationDays {30};
}

void arraysAndVectorsExamples() {
    int uninitialized [5];
    int testScores [5] {100, 95, 99, 86, 12};
    double initAllToZero [365] {0};
    double initAllToZeroAlso [365] {};
    int automaticSizeCalculation [] {1, 2, 3, 4, 5};

    testScores[0] = 72;

    char vowels[] {'a', 'e', 'i', 'o', 'u'};
}
