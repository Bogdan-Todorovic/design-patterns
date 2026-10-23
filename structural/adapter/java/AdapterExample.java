// Existing class (interface) we don't want to modify
interface TemperatureSensor{
    double getTemperatureCelsius();
}

class FahrenheitSensor {
    public double getTemperatureFahrenheit(){
        return 98.5;
    }
}

// Adapter allows for Fahrenheit sensor to use Celsius interface
class FahrenheitSensorAdapter implements TemperatureSensor {
    private final FahrenheitSensor fahrenheitSensor;

    public FahrenheitSensorAdapter(FahrenheitSensor sensor){
        this.fahrenheitSensor = sensor;
    }

    @Override
    public double getTemperatureCelsius() {
        double fahrenheit = fahrenheitSensor.getTemperatureFahrenheit();
        return (fahrenheit - 32) * 5.0 / 9.0;
    }
}

public class AdapterExample{
    static void main() {
        TemperatureSensor temperatureSensor = new FahrenheitSensorAdapter(new FahrenheitSensor());
        System.out.println("Temperature: " + temperatureSensor.getTemperatureCelsius());
    }
}