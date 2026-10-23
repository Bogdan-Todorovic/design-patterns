#include <iostream>
#include <string>
using namespace std;

class TV {
public:
    void turnOn() {
        cout << "TV is on\n";
    }

    void setInput(const string& input) {
        cout << "TV input set to " << input << '\n';
    }
};

class SoundSystem {
public:
    void turnOn() {
        cout << "Sound system is on\n";
    }

    void setVolume(int volume) {
        cout << "Volume set to " << volume << '\n';
    }
};

class MediaPlayer {
public:
    void turnOn() {
        cout << "Media player is on\n";
    }

    void play(const string& movie) {
        cout << "Playing " << movie << '\n';
    }
};

class HomeTheaterFacade {
private:
    TV& tv;
    SoundSystem& sound;
    MediaPlayer& player;

public:
    HomeTheaterFacade(TV& tv, SoundSystem& sound, MediaPlayer& player)
        : tv(tv), sound(sound), player(player) {}

    void watchMovie(const string& movie) {
        cout << "Preparing home theater...\n";

        tv.turnOn();
        tv.setInput("HDMI");

        sound.turnOn();
        sound.setVolume(20);

        player.turnOn();
        player.play(movie);
    }
};

int main() {
    TV tv;
    SoundSystem sound;
    MediaPlayer player;

    HomeTheaterFacade homeTheater(tv, sound, player);
    homeTheater.watchMovie("Inception");
}