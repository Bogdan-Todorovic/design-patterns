#include <iostream>
#include <memory>
#include <string>

class Prototype {
public:
    [[nodiscard]] virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual ~Prototype() = default;
};

class Enemy : public Prototype{
private:
    std::string name;
    int health;
    int armor;

public:
    Enemy(std::string name, int health, int armor) :
        name(std::move(name)), health(health), armor(armor)
    {}

    [[nodiscard]] std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<Enemy>(*this);
    }

    void setHealth(int health) {
        this->health = health;
    }

    void display() {
        std::cout << name << " " << health << " " << armor << "\n";
    }
};

int main() {
    Enemy original("Goblin", 100, 200);

    auto copy = original.clone();
    auto* enemy = dynamic_cast<Enemy*> (copy.get());

    if (enemy)
        enemy->display();
}
