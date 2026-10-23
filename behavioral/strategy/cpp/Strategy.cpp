#include <iostream>
#include <memory>
#include <string>
#include <utility>

// Strategy
class RouteStrategy {
public:
    virtual void buildRoute(
        const std::string& start,
        const std::string& destination
    ) const = 0;

    virtual ~RouteStrategy() = default;
};

// Concrete Strategy
class CarStrategy : public RouteStrategy {
public:
    void buildRoute(
        const std::string& start,
        const std::string& destination
    ) const override {
        std::cout << "Building car route from "
                  << start << " to " << destination << '\n';
    }
};

// Concrete Strategy
class WalkingStrategy : public RouteStrategy {
public:
    void buildRoute(
        const std::string& start,
        const std::string& destination
    ) const override {
        std::cout << "Building walking route from "
                  << start << " to " << destination << '\n';
    }
};

// Concrete Strategy
class BikeStrategy : public RouteStrategy {
public:
    void buildRoute(
        const std::string& start,
        const std::string& destination
    ) const override {
        std::cout << "Building bike route from "
                  << start << " to " << destination << '\n';
    }
};

// Context
class Navigator {
private:
    std::unique_ptr<RouteStrategy> strategy;

public:
    explicit Navigator(std::unique_ptr<RouteStrategy> strategy)
        : strategy(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<RouteStrategy> strategy) {
        this->strategy = std::move(strategy);
    }

    void navigate(
        const std::string& start,
        const std::string& destination
    ) const {
        strategy->buildRoute(start, destination);
    }
};

// Client
int main() {
    Navigator navigator(std::make_unique<CarStrategy>());

    navigator.navigate("Belgrade", "Novi Sad");

    navigator.setStrategy(std::make_unique<WalkingStrategy>());
    navigator.navigate("Belgrade", "Novi Sad");

    navigator.setStrategy(std::make_unique<BikeStrategy>());
    navigator.navigate("Belgrade", "Novi Sad");

    return 0;
}
