import java.util.ArrayList;
import java.util.List;

// Mediator
interface ChatMediator {
    void addUser(User user);
    void sendMessage(String message, User sender);
}

// Concrete mediator
class ChatRoom implements ChatMediator {
    private List<User> users = new ArrayList<>();

    @Override
    public void addUser(User user) {
        users.add(user);
    }

    @Override
    public void sendMessage(String message, User sender) {
        for (User user : users){
            if (user != sender)
                user.receive(message, sender.getName());
        }
    }
}

// Colleague
class User {
    private String name;
    private ChatMediator chatMediator;

    public User(String name, ChatMediator mediator){
        this.name = name;
        this.chatMediator = mediator;
    }

    public String getName(){
        return name;
    }

    public void send (String message){
        System.out.println(name + " sends: " + message);
        chatMediator.sendMessage(message, this);
    }

    public void receive(String message, String sender){
        System.out.println(name + " receives from " + sender + ": " + message);
    }
}

// Client
public class Mediator {
    static void main() {
        ChatMediator chatRoom = new ChatRoom();
        User ana = new User("Ana", chatRoom);
        User marko = new User("Marko", chatRoom);
        User petar = new User("Petar", chatRoom);

        chatRoom.addUser(ana);
        chatRoom.addUser(marko);
        chatRoom.addUser(petar);

        ana.send("Zdravo Svima!");
    }
}
