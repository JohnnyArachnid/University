// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

int main() {

    // Przypisanie wspolczynnikow wielomianu do tablicy

    double wspolczynnikiWielomianuWielomianu[] = {-1, 12, -46, 56};

    // Obliczenie wielkosci tablicy

    size_t rozmiarTablicyZWspolczynnikamiWielomianu = (sizeof(wspolczynnikiWielomianuWielomianu) / sizeof(wspolczynnikiWielomianuWielomianu[0])) - 1;

    // Inicjacja wielomianu 

    Wielomian a(wspolczynnikiWielomianuWielomianu, rozmiarTablicyZWspolczynnikamiWielomianu);

    // Inicjacja wektora z pierwiastkami wielomianu

    gsl_vector * pierwiastkiWielomianu = gsl_vector_alloc(rozmiarTablicyZWspolczynnikamiWielomianu);

    // Inicjacja wektora przedzialow poszukiwania pierwiastkow wielomianu

    gsl_vector * przedzialyPierwiastkowWielomianu = gsl_vector_alloc(rozmiarTablicyZWspolczynnikamiWielomianu * 2);

    // Wypelnienie wektora przedzialow

    gsl_vector_set(przedzialyPierwiastkowWielomianu, 0, 0);
    gsl_vector_set(przedzialyPierwiastkowWielomianu, 1, 3);
    gsl_vector_set(przedzialyPierwiastkowWielomianu, 2, 3.01);
    gsl_vector_set(przedzialyPierwiastkowWielomianu, 3, 5);
    gsl_vector_set(przedzialyPierwiastkowWielomianu, 4, 5.01);
    gsl_vector_set(przedzialyPierwiastkowWielomianu, 5, 6);

    // Nazwa pliku z rozwiazaniem zadania
    
    const char* sciezkaPliku = "wyniki.txt";

    // Otwórzenie pliku do zapisu miejsc zerowych wielomianu

    std::ofstream plik(sciezkaPliku);

    // Sprawdzenie, czy udało się otworzyć plik do zapisu miejsc zerowych wielomianu

    if (!plik.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    // Inicjacja licznika iteracji

    int iterator[rozmiarTablicyZWspolczynnikamiWielomianu];

    // Mierzenie czasu dla pierwszej metody

    auto poczatek = std::chrono::high_resolution_clock::now();

    // Obliczenie pierwiastkow wielomianu metoda Newtona

    metodaNewtona(a, przedzialyPierwiastkowWielomianu, pierwiastkiWielomianu, iterator);

    // Mierzenie czasu dla pierwszego wzoru

    auto koniec = std::chrono::high_resolution_clock::now(); 
    auto roznicaCzasow = std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - poczatek);

    // Wypisanie rozwiazan wielomianu w terminalu

    std::cout << "Pierwiastki wielomianu uzyskane dzieki metodzie Newtona:" << std::endl;
    for (size_t i = 0; i < rozmiarTablicyZWspolczynnikamiWielomianu; i++) {
        printf("%lf \n", gsl_vector_get(pierwiastkiWielomianu, i));
        std::cout << "Liczba iteracji: " << iterator[i] << std::endl;
    }
    printf("Czas wykonywania metody: %.9f sekund.", roznicaCzasow.count() * 1e-9);
    std::cout << std::endl;

    // Zapisanie rozwiazan wielomianu do pliku

    plik << "Pierwiastki wielomianu uzyskane dzieki metodzie Newtona:" << std::endl;
    for (size_t i = 0; i < rozmiarTablicyZWspolczynnikamiWielomianu; i++) {
        plik << gsl_vector_get(pierwiastkiWielomianu, i) << std::endl;
        plik << "Liczba iteracji: " << iterator[i] << std::endl;
    }
    plik << "Czas wykonywania metody: "<< roznicaCzasow.count() * 1e-9 << " sekund.";
    plik << std::endl;

    // Mierzenie czasu dla drugiej metody

    poczatek = std::chrono::high_resolution_clock::now();

    // Obliczenie pierwiastkow wielomianu metoda bisekcji

    metodaBisekcji(a, przedzialyPierwiastkowWielomianu, pierwiastkiWielomianu, iterator);

    // Mierzenie czasu dla drugiego wzoru

    koniec = std::chrono::high_resolution_clock::now(); 
    roznicaCzasow = std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - poczatek);

    // Wypisanie rozwiazan wielomianu w terminalu

    std::cout << "Pierwiastki wielomianu uzyskane dzieki metodzie Bisekcji:" << std::endl;
    for (size_t i = 0; i < rozmiarTablicyZWspolczynnikamiWielomianu; i++) {
        printf("%lf \n", gsl_vector_get(pierwiastkiWielomianu, i));
        std::cout << "Liczba iteracji: " << iterator[i] << std::endl;
    }
    printf("Czas wykonywania metody: %.9f sekund.", roznicaCzasow.count() * 1e-9);
    std::cout << std::endl;

    // Zapisanie rozwiazan wielomianu do pliku

    plik << "Pierwiastki wielomianu uzyskane dzieki metodzie Bisekcji:" << std::endl;
    for (size_t i = 0; i < rozmiarTablicyZWspolczynnikamiWielomianu; i++) {
        plik << gsl_vector_get(pierwiastkiWielomianu, i) << std::endl;
        plik << "Liczba iteracji: " << iterator[i] << std::endl;
    }
    plik << "Czas wykonywania metody: "<< roznicaCzasow.count() * 1e-9 << " sekund.";
    plik << std::endl;

    // Mierzenie czasu dla trzeciej metody

    poczatek = std::chrono::high_resolution_clock::now();

    // Obliczenie pierwiastkow wielomianu metoda siecznych

    metodaSiecznych(a, przedzialyPierwiastkowWielomianu, pierwiastkiWielomianu, iterator);

    // Mierzenie czasu dla trzeciego wzoru

    koniec = std::chrono::high_resolution_clock::now(); 
    roznicaCzasow = std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - poczatek);

    // Wypisanie rozwiazan wielomianu w terminalu

    std::cout << "Pierwiastki wielomianu uzyskane dzieki metodzie Siecznych:" << std::endl;
    for (size_t i = 0; i < rozmiarTablicyZWspolczynnikamiWielomianu; i++) {
        printf("%lf \n", gsl_vector_get(pierwiastkiWielomianu, i));
        std::cout << "Liczba iteracji: " << iterator[i] << std::endl;
    }
    printf("Czas wykonywania metody: %.9f sekund.", roznicaCzasow.count() * 1e-9);
    std::cout << std::endl;

    // Zapisanie rozwiazan wielomianu do pliku

    plik << "Pierwiastki wielomianu uzyskane dzieki metodzie Siecznych:" << std::endl;
    for (size_t i = 0; i < rozmiarTablicyZWspolczynnikamiWielomianu; i++) {
        plik << gsl_vector_get(pierwiastkiWielomianu, i) << std::endl;
        plik << "Liczba iteracji: " << iterator[i] << std::endl;
    }
    plik << "Czas wykonywania metody: "<< roznicaCzasow.count() * 1e-9 << " sekund.";

    // Zwolnienie pamięci wektorow GSL
    
    gsl_vector_free(pierwiastkiWielomianu);
    gsl_vector_free(przedzialyPierwiastkowWielomianu);

    return 0;
}