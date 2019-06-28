#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

void variableExamples();
void arraysAndVectorsExamples();
void operatorExamples();
void controlStatementExamples();
void characterAndStringsExamples();
double defaultParameterExample(double param1 = 0, double param2 = 2.11);
void arrayLoop(const int arr[], size_t size);
void passByReferenceExample(int &num);
void print(const vector<int> &v);
void staticExample();

int main() {
    variableExamples();
    arraysAndVectorsExamples();
    operatorExamples();
    controlStatementExamples();
    characterAndStringsExamples();
    defaultParameterExample();
    defaultParameterExample(10);
    defaultParameterExample(10, 3);
    int arr[] {1, 2, 3, 4};
    arrayLoop(arr, 4);

    int num = 234;
    passByReferenceExample(num);
    cout << endl << num << endl;

    vector<int> test {1, 4, 56, 1};
    print(test);

    staticExample();
    staticExample();

    return 0;
}

void staticExample() {
    // Value is kept between every call
    static int var = 10;
    var++;
    cout << endl << var << " ";
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

    // Dynamic size
    vector<char> vowelsVector (5);
    vector<int> numbers(10); // Automatically initialized to 0
    vector<char> initializedChars {'a', 'e', 'i', 'o', 'u'};

    vector<double> temps (3, 90.9); // Number of elements, elements to initialize to

    vowelsVector.at(0) = 'a';

    cout << temps[0] << endl; // Can use [] to access value. This option returns gibberish when out of bounds.
    cout << temps.at(1) << endl; // Or .at(). This option, however, gives an exception when out of bounds.
    cout << temps.size() << endl;

    temps.push_back(100.8); // Add new value to the end of the vector

    cout << temps.size() << endl;

    vector<vector<int>> twoDimensionVector {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    // Inserting into vectors creates a copy of the value inserted. If you'd insert a vector inside of the above vector
    // And then if you'd change the inserted vector, then the one in the 2D vector would not change as it's a copy inside
    // of that, not the original value.
    cout << twoDimensionVector.at(0).at(1) << endl;
}

void operatorExamples() {
    int num1 {200};
    int num2 {100};

    bool truthy = true;

    num1 + num2;
    num1 - num2;
    num1 * num2;
    num1 / num2;
    num1 % num2;

    ++num1;
    num1++;

    num1--;
    --num1;

    // (double)num1; // old style
    double castNum1 = static_cast<double>(num1);

    num1 == 100;
    num1 != 100;

    num1 > num2;
    num1 < num2;
    num1 >= num2;
    num1 <= num2;

    !truthy;
    not truthy;

    truthy && truthy;
    truthy and truthy;

    truthy || truthy;
    truthy or truthy;

    num1 += 2;
    num1 -= 2;
    num1 /= 5;
    num1 ^= 2;
}

void controlStatementExamples() {
    int num1 {100}, num {};
    vector<int> someVector {17, 26, 35, 42, 51};

    num = true ? 100 : 0;

    switch (num1) {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }

    if (true) {
        while(false) {

        }
    } else if (false) {

    } else {
        do {

        } while (false);
    }

    for (int i = 0; i < 1; i++) {

    }

    for (auto variable : someVector) {

    }
}

void characterAndStringsExamples() {
    // There are C style strings and C++
    // C style has a null termination character
    // All of the C style functions require the null character to exist

    char str[80];
    strcpy(str, "Hello");
    strcat(str, " there");
    strlen(str);
    strcmp(str, "Bananas");

    // C++ string sizes are dynamic. Can use regular operators +, = etc.
    string s2 {"Bobbert"};
    string bob {s2, 0, 3};
    string fullName = bob + " " + s2;
    fullName += ", PhD";
    bob == s2;

    fullName.substr(0, 3);
    fullName.find(bob);

    for (char c : fullName) {
        cout << c << endl;
    }
}


double defaultParameterExample(double param1, double param2) {
    return param1 * param2;
}

// Have to pass in the size as the method knows nothing about the size of the array, since a pointer to the first element is passed in
void arrayLoop(const int arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void passByReferenceExample(int &num) {
    num = 1000;
}

// A vector is passed by copy, so the entire vector would get copied, this can lead to performance issues
// So it's better to pass a vector by reference.
void print(const vector<int> &v) {
    for (auto num : v) {
        cout << num << " ";
    }
}
