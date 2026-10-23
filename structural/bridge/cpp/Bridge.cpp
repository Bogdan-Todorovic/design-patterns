#include <iostream>
#include <memory>
using namespace std;

// Implementation interface
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setVolume(int volume) = 0;
    virtual ~Device() = default;
};

class TV : public Device {
public:
    void turnOn() override {
        cout << "TV is on\n";
    }

    void turnOff() override {
        cout << "TV is off\n";
    }

    void setVolume(int volume) override {
        cout << "TV volume: " << volume << '\n';
    }
};

class Radio : public Device {
public:
    void turnOn() override {
        cout << "Radio is on\n";
    }

    void turnOff() override {
        cout << "Radio is off\n";
    }

    void setVolume(int volume) override {
        cout << "Radio volume: " << volume << '\n';
    }
};

// Abstraction
class RemoteControl {
protected:
    Device& device;

public:
    explicit RemoteControl(Device& device) : device(device) {}

    virtual ~RemoteControl() = default;

    void turnOn() {
        device.turnOn();
    }

    void turnOff() {
        device.turnOff();
    }

    void setVolume(int volume) {
        device.setVolume(volume);
    }
};

// Refined Abstraction
class AdvancedRemote : public RemoteControl {
public:
    using RemoteControl::RemoteControl;

    void mute() {
        device.setVolume(0);
    }
};

int main() {
    TV tv;
    Radio radio;

    RemoteControl basicRemote(tv);
    AdvancedRemote advancedRemote(radio);

    basicRemote.turnOn();
    basicRemote.setVolume(30);

    advancedRemote.turnOn();
    advancedRemote.setVolume(20);
    advancedRemote.mute();
}