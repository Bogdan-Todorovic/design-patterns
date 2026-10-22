#include <iostream>
#include <memory>

// Interface of products that all factories derived from Abstract factory must implement
class Button {
public:
    virtual void render() const = 0;
    virtual ~Button() = default;
};

class CheckBox {
public:
    virtual void render() const = 0;
    virtual ~CheckBox() = default;
};

// Implementing concrete Windows Button
class WindowsButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Windows Button\n";
    }
};

// Implementing concrete Windows CheckBox
class WindowsCheckBox : public CheckBox {
public:
    void render() const override {
        std::cout << "Rendering Windows CheckBox\n";
    }
};

// Implementing Concrete Mac Button
class MacButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Mac Button\n";
    }
};

// Implementing concrete Mac CheckBox
class MacCheckBox : public CheckBox {
public:
    void render() const override {
        std::cout << "Rendering Mac CheckBox\n";
    }
};

// Abstract Factory that defines all the products
class GUIFactory {
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<CheckBox> createCheckBox() = 0;
    virtual ~GUIFactory() = default;
};

// Concrete Windows Factory that implements Windows elements
class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<WindowsButton>();
    }

    std::unique_ptr<CheckBox> createCheckBox() override {
        return std::make_unique<WindowsCheckBox>();
    }
};

// Concrete Mac Factory that implements Mac elements
class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<MacButton>();
    }

    std::unique_ptr<CheckBox> createCheckBox() override {
        return std::make_unique<MacCheckBox>();
    }
};

// Client's code
int main() {
    GUIFactory* factory = new MacFactory();
    //GUIFactory* factory = new WindowsFactory();

    std::unique_ptr<Button> button = factory->createButton();
    std::unique_ptr<CheckBox> checkBox = factory->createCheckBox();

    button->render();
    checkBox->render();

    delete factory;
}
