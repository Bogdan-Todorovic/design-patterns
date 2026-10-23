// Strategy
interface RouteStrategy {
    void buildRoute(String start, String destination);
}

// Concrete Strategy
class CarStrategy implements RouteStrategy {
    @Override
    public void buildRoute(String start, String destination) {
        System.out.println(
                "Building car route from " + start + " to " + destination
        );
    }
}

// Concrete Strategy
class WalkingStrategy implements RouteStrategy {
    @Override
    public void buildRoute(String start, String destination) {
        System.out.println(
                "Building walking route from " + start + " to " + destination
        );
    }
}

// Concrete Strategy
class BikeStrategy implements RouteStrategy {
    @Override
    public void buildRoute(String start, String destination) {
        System.out.println(
                "Building bike route from " + start + " to " + destination
        );
    }
}

// Context
class Navigator {
    private RouteStrategy strategy;

    public Navigator(RouteStrategy strategy) {
        this.strategy = strategy;
    }

    public void setStrategy(RouteStrategy strategy) {
        this.strategy = strategy;
    }

    public void navigate(String start, String destination) {
        strategy.buildRoute(start, destination);
    }
}

// Client
public class StrategyExample {
    static void main(String[] args) {
        Navigator navigator = new Navigator(new CarStrategy());

        navigator.navigate("Belgrade", "Novi Sad");

        navigator.setStrategy(new WalkingStrategy());
        navigator.navigate("Belgrade", "Novi Sad");

        navigator.setStrategy(new BikeStrategy());
        navigator.navigate("Belgrade", "Novi Sad");
    }
}
