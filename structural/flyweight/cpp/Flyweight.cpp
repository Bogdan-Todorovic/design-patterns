#include <iostream>
#include <string>

class BulletType {
private:
    std::string texture;
    int damage;

public:
    BulletType(std::string texture, int damage) : texture(std::move(texture)), damage(damage) {}

    void render(int x, int y) {
        std::cout << "Rendering " << texture << "Bullet " << x << " " << y
        << damage << "\n";
    }
};

class BulletTypeFactory {
private:
    std::unordered_map<std::string, std::unique_ptr<BulletType>> types;

public:
    BulletType& getType(std::string name, std::string texture, int damage) {
        auto it = types.find(name);

        if (it == types.end()) {
            auto type = std::make_unique<BulletType>(texture, damage);
            it = types.emplace(name, std::move(type)).first;
        }

        return *it->second;
    }
};

class Bullet {
private:
    BulletType& bulletType;
    int x;
    int y;

public:
    Bullet(BulletType& bulletType, int x, int y) : bulletType(bulletType), x(x), y(y) {}
    void render() {
        bulletType.render(x, y);
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

int main() {
    BulletTypeFactory factory;
    BulletType& normalType = factory.getType("normal", "normal.jpg", 10);

    Bullet bullet1(normalType, 10, 20);
    Bullet bullet2(factory.getType("normal", "normal.jpg", 10), 30, 450);

    bullet1.render();
    bullet2.render();
}
