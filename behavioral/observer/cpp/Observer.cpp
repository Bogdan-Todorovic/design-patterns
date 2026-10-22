#include <iostream>
#include <vector>

class Observer {
public:
    virtual void update(double temperature) = 0;
    virtual ~Observer() = default;
};

class WeatherStation {
private:
    std::vector<std::unique_ptr<Observer>> observers;
    double temperature = 0;

    void notifyObservers() const {
        for (auto o : observers)
            o->update(temperature);
    }

public:
    void subscribe(std::unique_ptr<Observer> observer) {
        observers.push_back(std::move(observer));
    }

    void unsubscribe(const std::unique_ptr<Observer> &observer) {
        for (auto it = observers.begin(); it < observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void setTemperature(double temperature_) {
        this->temperature = temperature_;
        notifyObservers();
    }
};

class PhoneDisplay : public Observer {
public:
    void update(double temperature) override {
        std::cout << "Phone display: " << temperature << " C\n";
    }
};

class Dashboard : public Observer {
public:
    void update(double temperature) override {
        std::cout << "Dashboard updated: " << temperature << " C\n";
    }
};

int main() {
    WeatherStation station;

    station.subscribe(std::make_unique<PhoneDisplay>());
    station.subscribe(std::make_unique<Dashboard>());

    station.setTemperature(25.0);
    station.setTemperature(28.5);

    station.setTemperature(30.0);
    return 0;
}