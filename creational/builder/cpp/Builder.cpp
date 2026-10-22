#include <iostream>
#include <string>
#include <utility>

class Character {
private:
    std::string name;
    std::string weapon;
    std::string armor;
    int health;
    double speed;

    Character(std::string  name, std::string  weapon,
              std::string  armor, int health, double speed)
        : name(std::move(name)), weapon(std::move(weapon)), armor(std::move(armor)),
          health(health), speed(speed) {}

public:
    class Builder {
    private:
        std::string name;
        std::string weapon = "None";
        std::string armor = "None";
        int health = 100;
        double speed = 5.0;

    public:
        explicit Builder(std::string  name) : name(std::move(name)) {}

        Builder& setWeapon(const std::string& weapon) {
            this->weapon = weapon;
            return *this;
        }

        Builder& setArmor(const std::string& armor) {
            this->armor = armor;
            return *this;
        }

        Builder& setHealth(int health) {
            this->health = health;
            return *this;
        }

        Builder& setSpeed(double speed) {
            this->speed = speed;
            return *this;
        }

        [[nodiscard]] Character build() const {
            return Character(name, weapon, armor, health, speed);
        }
    };

    void display() const {
        std::cout << "Character: " << name << '\n';
        std::cout << "Weapon: " << weapon << '\n';
        std::cout << "Armor: " << armor << '\n';
        std::cout << "Health: " << health << '\n';
        std::cout << "Speed: " << speed << '\n';
    }
};

int main() {
    Character knight = Character::Builder("Knight")
        .setWeapon("Sword")
        .setArmor("Heavy Armor")
        .setHealth(150)
        .build();

    Character archer = Character::Builder("Archer")
        .setWeapon("Bow")
        .setSpeed(8.0)
        .build();

    knight.display();
    std::cout << '\n';
    archer.display();
}