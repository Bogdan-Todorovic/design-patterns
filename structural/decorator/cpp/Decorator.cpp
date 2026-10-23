#include <iostream>
#include <string>

class Drink {
public:
    virtual std::string getDescription() = 0;
    virtual int getPrice() = 0;
    virtual ~Drink() = default;
};

class Juice : public Drink {
public:
    std::string getDescription() override {
        return "Juice";
    }

    int getPrice() override {
        return 100;
    }
};

class Soda : public Drink {
public:
    std::string getDescription() override {
        return "Soda";
    }

    int getPrice() override {
        return 120;
    }
};

class DrinkDecorator : public Drink{
protected:
    std::unique_ptr<Drink> drink;

public:
    explicit DrinkDecorator(std::unique_ptr<Drink> drink) : drink(std::move(drink)){}
};

class MilkDecorator : public DrinkDecorator {
public:
    explicit MilkDecorator(std::unique_ptr<Drink> drink) : DrinkDecorator(std::move(drink));

    std::string getDescription() override {
        return drink->getDescription() + " milk";
    }

    int getPrice() override {
        return drink->getPrice() + 100;
    }
};

class CaramelDecorator : public DrinkDecorator {
public:
    explicit CaramelDecorator(std::unique_ptr<Drink> drink) : DrinkDecorator(std::move(drink)){}

    std::string getDescription() override {
        return drink->getDescription() + " caramel";
    }

    int getPrice() override {
        return drink->getPrice() + 120;
    }
};

int main() {
    std::unique_ptr<Drink> juice = std::make_unique<Juice>();
    std::unique_ptr<Drink> soda = std::make_unique<Soda>();

    juice = std::make_unique<MilkDecorator>(std::move(juice));
    juice = std::make_unique<CaramelDecorator>(std::move(juice));

    std::cout << juice->getDescription();
}


