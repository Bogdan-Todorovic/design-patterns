interface Device{
    void turnOn();
    void turnOff();
    void setVolume(int volume);
}

class TV implements Device {
    @Override
    public void turnOn() {
        System.out.println("TV turned on");
    }

    @Override
    public void turnOff() {
        System.out.println("TV turned off");
    }

    @Override
    public void setVolume(int volume) {
        System.out.println("Volume set " + volume);
    }
}

class Radio implements Device{
    @Override
    public void turnOn() {
        System.out.println("Radio turned on");

    }
    @Override
    public void turnOff() {
        System.out.println("Radio turned off");
    }

    @Override
    public void setVolume(int volume) {
        System.out.println("Volume set " + volume);
    }
}

class RemoteControler{
    protected final Device device;

    public RemoteControler(Device device){
        this.device = device;
    }

    public void turnOn(){
        device.turnOn();
    }

    public void turnOff(){
        device.turnOff();
    }

    public void setVolume(int volume){
        device.setVolume(volume);
    }
}

class AdvancedRemoteControler extends RemoteControler{
    public AdvancedRemoteControler(Device device){
        super(device);
    }

    public void mute(){
        setVolume(0);
    }
}

public class BridgeExample{
    static void main() {
        Device tv = new TV();
        Device radio = new Radio();

        RemoteControler basicRemote = new RemoteControler(tv);
        AdvancedRemoteControler advancedRemote = new AdvancedRemoteControler(radio);

        basicRemote.turnOn();
        basicRemote.setVolume(30);

        advancedRemote.turnOn();
        advancedRemote.setVolume(20);
        advancedRemote.mute();
    }
}