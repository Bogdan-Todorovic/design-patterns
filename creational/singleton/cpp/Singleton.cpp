#include <iostream>

class Singleton {
private:
    // Only instance of a class
    static Singleton* instance;

    // Constructor is private
    Singleton() {
        std::cout << "Singleton Created\n";
    }
public:
    // Copy constructor deleted
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static method for getting only instance
    static Singleton *get_instance() {
        if (instance == nullptr)
            instance = new Singleton();

        return instance;
    }

    void doSomething() {
        std::cout << "Singleton Working\n";
    }
};

// Initialization of static member
Singleton* Singleton::instance = nullptr;

// Test program
int main() {
    Singleton* first = Singleton::get_instance();
    Singleton* second = Singleton::get_instance();

    first->doSomething();

    std::cout << std::boolalpha;
    std::cout << "Same instance: " << (first == second);

    return 0;
}
