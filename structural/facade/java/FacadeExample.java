class Television {
    public void turnOn() {
        System.out.println("TV is on");
    }

    public void setInput(String input) {
        System.out.println("TV input set to " + input);
    }
}

class SoundSystem {
    public void turnOn() {
        System.out.println("Sound system is on");
    }

    public void setVolume(int volume) {
        System.out.println("Volume set to " + volume);
    }
}

class MediaPlayer {
    public void turnOn() {
        System.out.println("Media player is on");
    }

    public void play(String movie) {
        System.out.println("Playing " + movie);
    }
}

// Facade
class HomeTheaterFacade {
    private final Television tv;
    private final SoundSystem sound;
    private final MediaPlayer player;

    public HomeTheaterFacade(
            Television tv, SoundSystem sound, MediaPlayer player) {
        this.tv = tv;
        this.sound = sound;
        this.player = player;
    }

    public void watchMovie(String movie) {
        System.out.println("Preparing home theater...");

        tv.turnOn();
        tv.setInput("HDMI");

        sound.turnOn();
        sound.setVolume(20);

        player.turnOn();
        player.play(movie);
    }
}

public class FacadeExample {
    static void main(String[] args) {
        Television tv = new Television();
        SoundSystem sound = new SoundSystem();
        MediaPlayer player = new MediaPlayer();

        HomeTheaterFacade homeTheater =
                new HomeTheaterFacade(tv, sound, player);

        homeTheater.watchMovie("Inception");
    }
}
