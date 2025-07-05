#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Song {
public:
    std::wstring artist;
    std::wstring title;

    Song(const std::wstring& artist, const std::wstring& title)
        : artist(artist), title(title) {
        std::wcout << L"Konstruktor: " << artist << L" - " << title << std::endl;
    }

    ~Song() {
        std::wcout << L"Destruktor: " << artist << L" - " << title << std::endl;
    }

    void play() const {
        std::wcout << L"Odtwarzanie: " << artist << L" - " << title << std::endl;
    }
};

std::unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title) {
    return std::make_unique<Song>(artist, title);
}

int main() {

    std::vector<std::unique_ptr<Song>> songs;

    songs.push_back(SongFactory(L"Michael Jackson", L"Beat It"));
    songs.push_back(SongFactory(L"Queen", L"Bohemian Rhapsody"));
    songs.push_back(SongFactory(L"AC/DC", L"Back in Black"));

    std::wcout << L"\n--- Odtwarzanie piosenek ---\n";
    
    for (const auto& song : songs) {
        song->play(); // OK
    } 
    
    //for (const auto song : songs) {
    //song->play(); // BŁĄD KOMILACJI!
    //}

    std::wcout << L"\n--- Koniec programu ---\n";

    return 0;
}
