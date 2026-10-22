
interface Notification {
    void send(String message);
}

class EmailNotification implements Notification {
    @Override
    public void send(String message) {
        System.out.println("Sending Email: " + message);
    }
}

class SmsNotification implements  Notification {
    @Override
    public void send(String message) {
        System.out.println("Sending SMS: " + message);
    }
}

abstract class NotificationFactory {
    protected abstract Notification createNotification();
    public void sendNotification(String message){
        Notification notification = createNotification();
        notification.send(message);
    }
}

class EmailNotificationFactory extends NotificationFactory{
    @Override
    protected Notification createNotification() {
        return new EmailNotification();
    }
}

class SmsNotificationFactory extends NotificationFactory{
    @Override
    protected Notification createNotification() {
        return new SmsNotification();
    }
}

public class Factory {
    static void main() {
        NotificationFactory emailFactory = new EmailNotificationFactory();
        NotificationFactory smsFactory = new SmsNotificationFactory();

        emailFactory.sendNotification("Your shipment has been sent!");
        smsFactory.sendNotification("Your shipment has been sent!");
    }
}

