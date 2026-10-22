#include <iostream>
// Command
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Receiver
class Light {
public:
    void turnOn() {
        std::cout << "Turn on\n";
    }

    void turnOff() {
        std::cout << "Turn off\n";
    }
};

// Concrete command
class TurnOnCommand : public Command {
private:
    Light light;

public:
    explicit TurnOnCommand(Light light) : light(light){}
    void execute() override {
        light.turnOn();
    }
};

// Concrete command
class TurnOffCommand : public Command {
private:
    Light light;

public:
    explicit TurnOffCommand(Light light) : light(light) {}
    void execute() override {
        light.turnOff();
    }
};

// Invoker
class RemoteControl {
private:
    std::unique_ptr<Command> command;
public:
    void setCommand(std::unique_ptr<Command> command_) {
        command = std::move(command_);
    }

    void pressButton() const {
        command->execute();
    }
};

// Client
int main() {
    Light light;
    RemoteControl remoteControl;

    remoteControl.setCommand(std::make_unique<TurnOnCommand>(light));
    remoteControl.pressButton();

    remoteControl.setCommand(std::make_unique<TurnOffCommand>(light));
    remoteControl.pressButton();
}