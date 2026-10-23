#include <iostream>

class TemperatureSensor {
public:
    [[nodiscard]] virtual double getTemperatureCelsius() const = 0;
    virtual ~TemperatureSensor() = default;
};

class FahrenheitSensor {
public:
    double getTemperatureFahrenheit() const {
        return 98.6;
    }
};

class FahrenheitSensorAdapter : public TemperatureSensor {
private:
    const FahrenheitSensor& sensor;

public:
    explicit FahrenheitSensorAdapter(const FahrenheitSensor& sensor)
        : sensor(sensor) {}

    [[nodiscard]] double getTemperatureCelsius() const override {
        double fahrenheit = sensor.getTemperatureFahrenheit();
        return (fahrenheit - 32) * 5.0 / 9.0;
    }
};

int main() {
    FahrenheitSensor oldSensor;
    FahrenheitSensorAdapter adapter(oldSensor);

    TemperatureSensor& sensor = adapter;

    std::cout << "Temperature: " << sensor.getTemperatureCelsius() << " C\n";
}