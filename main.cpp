// Include with angle brackets is used to include system header files
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <memory>
#include <iomanip> // Needed for manipulators
#include <fstream>

// Double quotes are used to include header files that are local to this project
// Always include .h files, never include .cpp files.
#include "Player.h"
#include "GenericClass.h"

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
void pointerExample();
void passByReferenceExample(int *num);
void display(const vector<string> *const v);
int* createArray(size_t size, int init_value = 0);
void displayPlayer(Player p);
void displayPlayerName(Player &player);
void smartPointerExample();
void exceptionExample();
void fileStreamExample();
void stringStreamExample();
void iteratorExample();

// typename and class are both used in the brackets.
template <typename T1, class T2>
T1 min(T1 a, T2 b) {
    return ( a < b) ? a : b;
}

// Struct is essentially the same as a class, except its members are public by default where as a class' members
// Are private by default. Use a struct for passive objects with public access, do not declare methods in struct.
// If you start making things private, just use a class instead.
struct Example {
    string name;
};

int main() {
    // All sorts of stream options can be set
    std::cout << std::boolalpha; // Set a boolean to be displayed as true/false
    std::cout.setf(std::ios::boolalpha);
    // Reset to default
    std::cout << std::resetiosflags(std::ios::boolalpha);

    int i = 20;
    int &j = i; // Can be used to declare a reference, that means that it will be pointing to the same memory address as i.
    int &&r_ref = 200;

    cout << "RUNNING REFS" << endl;
    cout << &i << endl;
    cout << &j << endl;
    cout << &r_ref << endl;

    vector<Player> vec;
    // We're creating an rvalue, no reference to the value
    // Without a move constructor we'll allocate the memory, then call the copy constructor and allocate memory again to
    // Be able to copy the value over. Then a destructor will be called to free up the original object raw pointers.
    // With a move constructor we'll create the original object with a raw pointer. Then after the rvalue is created we'll
    // Call the move constructor and steal the data from the raw pointer, meaning that we won't have to do additional allocations.
    // The original object is going to go to release data from the null pointer, so it won't affect the new object.
    vec.push_back(Player{10});

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
    cout << endl << "Changed num value: " << num << endl;

    vector<int> test {1, 4, 56, 1};
    print(test);

    staticExample();
    staticExample();

    pointerExample();

    int num2 {100};
    passByReferenceExample(&num2);
    cout << "After the reference: " << num2 << endl;

    int* newArr = createArray(10, -5);

    delete newArr;

    // Use a loop variable by reference, this way a copy won't be made and it'll speed up execution.
    // Could be a performance problem if there's some custom class that's really big. Add the const to make sure
    // The reference isn't changed.
    for (auto const &number: test) {
        cout << number;
    }

    cout << endl;

    Player noArgsConstructor;
    Player bob("Bobbert");
    Player hero("Hero", 250);

    bob.setName("Bobbert");

    // Copy constructors will be called to put them into the array.
    Player players[] {bob, hero};

    Player* enemy {nullptr};
    enemy = new Player;
    // The following are the same ways to access attribute
    (*enemy).setHealth(100);
    enemy -> setHealth(150);

    delete enemy;

    displayPlayer(bob);
    Player copiedByConstructor {bob};

    cout << "Static call: " << Player::getNumberOfPlayers() << endl;

    Example example;
    example.name = "Bananas";

    displayPlayerName(bob);

    cout << "Assignment start" << endl;
    noArgsConstructor = bob; // Assignment. Default shallow copy. If we have raw pointer data we have to deep copy.
    // If there is no raw pointer in the class, then there's no need to create an overloaded operator.
    cout << noArgsConstructor.getName() << endl;
    cout << bob.getName() << endl;
    cout << "Assignment end" << endl;


    cout << "Before increment: " << bob.getHealth() << ", " << bob.getCurrentX() << endl;
    bob++;
    cout << "After increment: " << bob.getHealth() << ", " << bob.getCurrentX() << endl;

//    cin >> bob;
    cout << bob;

    smartPointerExample();

    exceptionExample();

    fileStreamExample();

    stringStreamExample();

    cout << "Running min: " << endl;
    cout << min<double, double>(2.0, 2.3) << endl;
    cout << min(2.0, 2.3) << endl; // In simpler cases the compiler can deduce the types on its own.

    GenericClass<int> ex{};
    ex.setProperty(10);
    cout << "Getting from generic class: " << ex.getProperty() << endl;

    iteratorExample();

    return 0;
}

void iteratorExample() {
    vector<int> numbers {1, 2, 3, 4, 5}; // End of the vector is after the last element, so the sixth element.
    auto it = numbers.begin();
    cout << "Iterator examples: " << endl;
    cout << *it << endl; // This isn't a real pointer, the syntax simply looks like it. It's an object.

    it++;
    cout << *it << endl;

    it = numbers.end() - 1;
    cout << *it << endl;

    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        cout << *iter << endl;
    }

    // Reverse order
    for (auto iter = numbers.rbegin(); iter != numbers.rend(); iter++) {
        cout << *iter << endl;
    }

    cout << "Iterator examples end" << endl;

}

void stringStreamExample() {
    // Instead of a file we now have the data in a string, we can read it as if we were reading it from a file
    int num {};
    double total {};
    string name {};
    string info {"Moe 100 1234.1"};

    std::istringstream iss {info};

    iss >> name >> num >> total;
}

void fileStreamExample() {
    std::ifstream inFile;
    std::ofstream outFile {"../output.txt", std::ios::app}; // Specify append mode. By default opens for overwriting.
    string line{};
    inFile.open("../test.txt"); // The executable gets put into cmake-build-debug/cpp_tutorial.exe, so we have to go one folder up to get to our source directory.

    if (!inFile) {
        cerr << "Unable to open file" << endl;
    }

    // Read until the first space.
    inFile >> line;

    cout << "Read line: " << line << endl;

    line = "";
    // Rewind to the start of the file.
    inFile.clear();
    inFile.seekg(0);

    std::getline(inFile, line);

    cout << "Read line again: " << line << endl;

    outFile << line << endl;

    inFile.close();
    outFile.close();
}

class SomeException : std::exception {
public:
    const char* what() const noexcept override {
        return "Some exception was thrown";
    }
};

// Destructors should never throw an exception. A constructor may throw an exception.
void exceptionExample() {
    try {
        throw 0;
    } catch(...) {
        cerr << "Caught whatever exception!" << endl;
    }

    try {
        throw SomeException();
    } catch(const SomeException &ex) {
        cerr << "Error caught " << ex.what() << endl;
    }
}

void custom_deleter(Player *raw_pointer) {
    cout << "Running custom deleter." << endl;
    delete raw_pointer;
}

void smartPointerExample() {
    // Unique pointer - can't have multiple unique pointers pointing at the same object. They cannot be copied or assigned.
    // However, they can be moved.
    // .reset() method makes the reference a nullptr. The memory it points to gets released.
    std::unique_ptr<Player> p1 {new Player{255}};
    // make_unique is more efficient - no new or delete calls.
    std::unique_ptr<Player> p2 = std::make_unique<Player>(255);
    auto p3 = std::make_unique<Player>(255);

    // Give ownership over to p4, setting p3 to null.
    unique_ptr<Player> p4;
    p4 = move(p3);

    p1 -> attack();
    cout << "P1: " << *p1 << endl;

    // push_back into a vector cannot simply be used, as copies aren't allowed. Can be moved into the vector, though.
    vector<unique_ptr<Player>> vec;
//    vec.push_back(p1); This would produce a compiler error, as it would call a copy
    vec.push_back(std::move(p1)); // p1 sets it to a nullptr. Ownership of the pointer goes to the vector.

    if (!p1) {
        cout << "The pointer of p1 is now a nullptr" << endl;
    }

    // Shared pointer counts pointers to it, when the count reaches 0, then it gets deleted. .use_count()
    // Similar to make_unique, there's a make_shared which is more efficient.
    shared_ptr<Player> p5 = make_shared<Player>(125);
    shared_ptr<Player> p6 {p5};
    vector<shared_ptr<Player>> shared_vec;

    cout << "Use count before push: " << p5.use_count() << endl;
    shared_vec.push_back(p5);
    cout << "Use count after push: " << p5.use_count() << endl;

    // Weak pointers are used on shared pointers. It isn't counted towards usage. If two classes refer to each other, then
    // It can produce a memory leak. As there are references when they go out of scope.
    weak_ptr<Player> p7 {p5};

    shared_ptr<Player> p8 {new Player(), custom_deleter};
}

void displayPlayerName(Player &player) {
    cout << player.name << endl;
}

void displayPlayer(Player p) {
    cout << "The player is " << p.getName() << endl;
}

int* createArray(size_t size, int init_value) {
    int *new_storage {nullptr};

    new_storage = new int[size];

    for (size_t i {0}; i < size; i++) {
        *(new_storage + i) = init_value;
    }

    return new_storage;
}

void display(const vector<string> *const v) {
    for (auto el: *v) {
        cout << el << " ";
    }

    cout << endl;
}

void passByReferenceExample(int *num) {
    *num *= 2;
}

void pointerExample() {
    // Without initialization a pointer variable can point anywhere and it might be data we should not be touching.
    // Always initialize pointer variables.
    int *int_ptr {nullptr};
    int num {10};

    cout << "Value is " << num << endl;
    cout << "Address is " << &num << endl;

    // Now the value stored in int_ptr is the address where num is situated in memory.
    int_ptr = &num;

    cout << "Value is the memory address to which it is pointing " << int_ptr << endl;
    cout << "Address is the block in memory where the pointer value (memory address it is pointing to) is stored " << &int_ptr << endl;

    // Change the value in the address that it's pointing to, so the original num would change as well, since they're both using
    // The same memory address. So it overwrites the value in the memory block. Changes the 10 to 211.
    *int_ptr = 211;

    cout << "Values: " << num << " " << *int_ptr << endl;

    vector<string> vec {"Bob", "Moe", "Joe"};
    vector<string> *vec_ptr {&vec};

    cout << "First element: " << (*vec_ptr).at(0) << endl;

    for (auto el : *vec_ptr) {
        cout << el << " ";
    }

    cout << endl;

    // Memory for pointers comes from the heap.
    int_ptr = nullptr;

    int_ptr = new int; // Allocate an int size block from the heap. Contains garbage data.
    // If you lose your reference to the block of memory, then you have a memory leak.
    // Have to clear the memory block to avoid memory leaks after you're done using the memory.

    delete int_ptr; // Frees the allocated storage.

    // Allocate continuous block of memory for an int array
    int_ptr = new int[5]; // Get a reference to the first element's memory block.

    // Release int array block.
    delete [] int_ptr;

    int arr[] {50, 12, 31};
    int_ptr = arr;

    cout << "Second element via different methods: " << *(arr + 1) << " " << arr[1] << " " << *(int_ptr + 1) << " " << int_ptr[1] << endl;
    cout << "Second element address via different methods: " << arr + 1 << " " << &arr[1] << " " << int_ptr + 1 << " " << &int_ptr[1] << endl;

    int scores[] {100, 92, 41, 21, -1};
    int *score_ptr {scores};

    // Loop through array using a pointer
    while (*score_ptr != -1) {
        cout << *score_ptr << " " << endl;
        score_ptr++;
    }

    // Can define a pointer that has a constant value or a constant memory address
    // A const pointer to the value, cannot change the value using this, but can change the memory address.
    const int *score_ptr2 {scores};
//    *score_ptr2 = 21; //Illegal
    score_ptr2 = &arr[1];

    // A const pointer to the memory address, cannot change the memory address this pointer references.
    int *const score_ptr3 {scores};
    *score_ptr3 = 12;
//    score_ptr3 = &arr[2]; // Illegal

    // And can combine them both
    const int *const score_ptr4 {scores};
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
