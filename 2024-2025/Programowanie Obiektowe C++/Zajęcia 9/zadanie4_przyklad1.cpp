#include <iostream>
#include <string>
#include <memory>

template <class T, class... Args>
std::unique_ptr<T> make_unique(Args&&... args);

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

int main() {
    auto song = std::make_unique<Song>("Queen", "Bohemian Rhapsody");

    song->play();

    return 0;
}
