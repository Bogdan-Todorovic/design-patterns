import java.util.ArrayList;
import java.util.List;

interface Observer{
    void update(double temperature);
}

class WeatherStation{
    private final List<Observer> observers = new ArrayList<>();
    private double temperature;

    public void subscribe(Observer observer){
        observers.add(observer);
    }

    public void unsubscribe(Observer observer){
        observers.remove(observer);
    }

    private void notifyObservers(){
        for (Observer o : observers)
            o.update(temperature);
    }

    public void setTemperature(double temperature){
        this.temperature = temperature;
        notifyObservers();
    }
}

class PhoneObserver implements Observer{
    @Override
    public void update(double temperature) {
        System.out.println("Phone observer: " + temperature);
    }
}

class TabletObserver implements Observer{
    @Override
    public void update(double temperature) {
        System.out.println("Tablet observer: " + temperature);
    }
}

public class ObserverExample{
    static void main() {
        WeatherStation weatherStation = new WeatherStation();

        Observer phoneObserver = new PhoneObserver();
        Observer tabletObserver = new TabletObserver();

        weatherStation.subscribe(phoneObserver);
        weatherStation.subscribe(tabletObserver);

        weatherStation.setTemperature(25.4);
        weatherStation.unsubscribe(phoneObserver);
        weatherStation.setTemperature(22.7);
    }
}