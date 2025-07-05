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

int main() {
    {
        std::shared_ptr<Song> song1 = std::make_shared<Song>("Michael Jackson", "Billie Jean");

        std::cout << "Poczatkowy licznik referencji: " << song1.use_count() << std::endl;

        {
            std::shared_ptr<Song> song2 = song1;
            std::cout << "Licznik referencji wewnatrz drugiego bloku: " << song1.use_count() << std::endl;

            {
                std::shared_ptr<Song> song3 = song2;
                std::cout << "Licznik referencji wewnatrz trzeciego bloku: " << song1.use_count() << std::endl;
            }

            std::cout << "Licznik referencji po zakonczeniu trzeciego bloku: " << song1.use_count() << std::endl;
        }

        std::cout << "Licznik referencji po zakonczeniu drugiego bloku: " << song1.use_count() << std::endl;
    }

    std::cout << "Po zakonczeniu main() obiekt powinien byc juz usuniety.\n";

    return 0;
}
