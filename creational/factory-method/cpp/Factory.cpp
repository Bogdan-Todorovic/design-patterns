#include <iostream>
#include <string>

// Interface of a product
class Notification {
public:
    virtual void send(std::string message) = 0;
    virtual ~Notification() = default;
};

// Concrete product
class EmailNotification : public Notification {
public:
    void send(const std::string message) override {
        std::cout << "Email notification: " << message << "\n";
    }
};

// Concrete product
class SmsNotification : public Notification {
public:
    void send(const std::string message) override {
        std::cout << "SMS notification: " << message << "\n";
    }
};

// Factory
class NotificationFactory {
protected:
    // Factory method for creating distinct Factories
    virtual std::unique_ptr<Notification> createNotification() = 0;
public:
    void sentNotification (const std::string &message) {
        auto notification = createNotification();
        notification->send(message);
    }

    virtual ~NotificationFactory() = default;
};

// Concrete Factory
class EmailNotificationFactory : public NotificationFactory {
protected:
    // Producing their corresponding product
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<EmailNotification>();
    }
};

// Concrete Factory
class SmsNotificationFactory : public NotificationFactory {
protected:
    // Producing their corresponding product
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<SmsNotification>();
    }
};

// Client's code
int main() {
    auto emailFactory = new EmailNotificationFactory();
    auto smsFactory = new SmsNotificationFactory();

    emailFactory->sentNotification("Your shipment arrived at location!");
    smsFactory->sentNotification("Your shipment arrived at location!");
}