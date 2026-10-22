#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

class User;

// Mediator
class ChatMediator {
public:
    virtual void addUser(User* user) = 0;
    virtual void sendMessage(
        const std::string& message,
        User* sender
    ) = 0;

    virtual ~ChatMediator() = default;
};

// Colleague
class User {
private:
    std::string name;
    ChatMediator& mediator;

public:
    User(std::string  name, ChatMediator& mediator)
        : name(std::move(name)), mediator(mediator) {}

    [[nodiscard]] const std::string& getName() const {
        return name;
    }

    void send(const std::string& message) {
        std::cout << name << " sends: " << message << '\n';
        mediator.sendMessage(message, this);
    }

    void receive(const std::string& message, const std::string& sender) {
        std::cout << name << " receives from "
                  << sender << ": "
                  << message << '\n';
    }
};

// Concrete mediator
class ChatRoom : public ChatMediator {
private:
    std::vector<User*> users;

public:
    void addUser(User* user) override {
        users.push_back(user);
    }

    void sendMessage(const std::string& message, User* sender) override {
        for (User* user : users) {
            if (user != sender) {
                user->receive(message, sender->getName());
            }
        }
    }
};

// Client
int main() {
    ChatRoom chatRoom;

    User ana("Ana", chatRoom);
    User marko("Marko", chatRoom);
    User petar("Petar", chatRoom);

    chatRoom.addUser(&ana);
    chatRoom.addUser(&marko);
    chatRoom.addUser(&petar);

    ana.send("Zdravo svima!");

    return 0;
}
