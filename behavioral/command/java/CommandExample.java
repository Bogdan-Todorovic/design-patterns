interface Command {
    void execute();
}

class Light {
    public void turnOn(){
        System.out.println("Turn On");
    }

    public void turnOff(){
        System.out.println("Turn Off");
    }
}

class TurnOnCommand implements Command{
    private final Light light;

    public TurnOnCommand(Light light){
        this.light = light;
    }

    @Override
    public void execute() {
        light.turnOn();
    }
}

class TurnOffCommand implements Command{
    private final Light light;

    public TurnOffCommand(Light light){
        this.light = light;
    }

    @Override
    public void execute() {
        light.turnOff();
    }
}

class RemoteControl {
    private Command command;

    public void setCommand(Command command){
        this.command = command;
    }
    public void pressButton(){
        if (command != null)
            command.execute();
    }
}

public class CommandExample{
    static void main() {
        Light light = new Light();
        RemoteControl remoteControl = new RemoteControl();

        remoteControl.setCommand(new TurnOnCommand(light));
        remoteControl.pressButton();

        remoteControl.setCommand(new TurnOffCommand(light));
        remoteControl.pressButton();
    }
}
