#include <iostream>

class Beverage {
public:
    // Template method
    void prepare() {
        boilWater();
        brew();
        pourIntoCup();
        addCondiments();
    }

    virtual ~Beverage() = default;

protected:
    virtual void brew() = 0;

    // Optional hook operation
    virtual void addCondiments() {
        // do nothing
    }

private:
    void boilWater() {
        std::cout << "Boiling Water\n";
    }

    void pourIntoCup() {
        std::cout << "Pouring into cup\n";
    }
};

class Coffee : public Beverage {
protected:
    void brew() override {
        std::cout << "Brewing coffee\n";
    }

    void addCondiments() override {
        std::cout << "Add sugar\n";
    }
};

class Tea : public Beverage {
protected:
    void brew() override {
        std::cout << "Brewing tea\n";
    }
};

int main() {
    auto tea = new Tea();
    auto coffee = new Coffee();

    tea->prepare();
    coffee->prepare();

    delete tea;
    delete coffee;
}