#ifndef CPP_TUTORIAL_GENERICCLASS_H
#define CPP_TUTORIAL_GENERICCLASS_H

// Template classes are typically completely contained in header files, so we only have the .h file.
template<typename T>
class GenericClass {
private:
    T property;
public:
    T getProperty() {
        return this -> property;
    }
    void setProperty(T newProperty) {
        this -> property = newProperty;
    }
};


#endif //CPP_TUTORIAL_GENERICCLASS_H
