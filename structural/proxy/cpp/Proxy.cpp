#include <iostream>
#include <string>

class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage : public Image {
private:
    std::string filename;

public:
    explicit RealImage(std::string filename) : filename(std::move(filename)){}
    void display() override {
        std::cout << "Displaying image\n";
    }
};

class ProxyImage : public Image {
private:
    std::string filename;
    std::unique_ptr<Image> realImage = nullptr;
public:
    explicit ProxyImage(std::string filename) : filename(std::move(filename)){}

    void display() override {
        if (realImage == nullptr)
            realImage = std::make_unique<RealImage>(filename);

        realImage->display();
    }
};

int main() {
    ProxyImage image("large-photo.jpg");

    std::cout << "Image object created.\n";
    std::cout << "User opens the image:\n";

    image.display();
    image.display();
}