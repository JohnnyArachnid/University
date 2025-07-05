#include <iostream>
#include <memory>

class Song {
private:
    std::string artist_;
    std::string title_;
public:
    Song(const std::string& artist, const std::string& title)
        : artist_(artist), title_(title) {
        std::cout << "Konstruktor: " << artist_ << " - " << title_ << std::endl;
    }

    ~Song() {
        std::cout << "Destruktor: " << artist_ << " - " << title_ << std::endl;
    }

    void play() const {
        std::cout << "Odtwarzanie: " << artist_ << " - " << title_ << std::endl;
    }
};

class Playlist {
public:
    std::shared_ptr<Song> song;
    std::weak_ptr<Song> weakSong;

    Playlist(std::shared_ptr<Song> s) : song(s), weakSong(s) {}

    void showWeak() {
        if (auto locked = weakSong.lock()) {
            locked->play();
        } else {
            std::cout << "Obiekt Song już nie istnieje!" << std::endl;
        }
    }
};

int main() {
    std::shared_ptr<Song> songPtr = std::make_shared<Song>("Michael Jackson", "Thriller");

    Playlist playlist(songPtr);

    playlist.showWeak();

    songPtr.reset();

    playlist.showWeak();

    return 0;
}
