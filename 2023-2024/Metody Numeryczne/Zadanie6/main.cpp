// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

int main() {

    // Inicjalizacja wektorów GSL

    gsl_vector *diag = gsl_vector_alloc(N + 1); // wektor diagonalny
    gsl_vector *e = gsl_vector_alloc(N); // wektor supdiagonalny
    gsl_vector *f = gsl_vector_alloc(N); // wektor subdiagonalny
    gsl_vector *b = gsl_vector_alloc(N + 1); // wektor z wynikami rownan liniowych
    gsl_vector *y = gsl_vector_alloc(N + 1); // wektor niewiadomych

    //Wypelnienie wektor GSL

    wypenienieWektoraB(b);
    wypelnienieWektoraDiagonalnegoDiag(diag);
    wypenienieWektoraTrojdiagonalnegoGornegoE(e);
    wypenienieWektoraTrojdiagonalnegoDolnegoF(f);

    // Nazwy plikow
    
    const char* sciezkaPliku1 = "wynikiR.txt";
    const char* sciezkaPliku2 = "wynikiJ.txt";
    const char* sciezkaPliku3 = "wynikiGS.txt";
    const char* sciezkaPliku4 = "wynikiS.txt";

    // Otwórzenie plikow do zapisu danych do wykresow

    std::ofstream plik1(sciezkaPliku1);
    std::ofstream plik2(sciezkaPliku2);
    std::ofstream plik3(sciezkaPliku3);
    std::ofstream plik4(sciezkaPliku4);

    // Sprawdzenie, czy udało się otworzyć pliki z danymi do wykresow

    if (!plik1.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu danych do wykresow." << std::endl;
        return 1;
    }

    if (!plik2.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu danych do wykresow." << std::endl;
        return 2;
    }

    if (!plik3.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu danych do wykresow." << std::endl;
        return 3;
    }

    if (!plik4.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu danych do wykresow." << std::endl;
        return 4;
    }

    // Zmienna zliczajaca ilosc iteracji dla metod

    int iloscIteracji = 0;

    // Mierzenie czasu dla pierwszej metody

    auto poczatek = std::chrono::high_resolution_clock::now(); 

    // Rozwiązanie układu równań metoda Relaksacyjna Richardsona

    metodaRelaksacyjnaRichardsona(diag, e, f, b, y, &iloscIteracji);

    // Mierzenie czasu dla pierwotnego wzoru

    auto koniec = std::chrono::high_resolution_clock::now(); 
    auto roznicaCzasow = std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - poczatek);

    // Wypisanie informacji do konsoli

    std::cout<<"Metoda Relaksacyjna Richardsona: "<<std::endl<<"Ilosc iteracji: "<<iloscIteracji<<std::endl;
    printf("Czas wykonywania metody: %.3f sekund.\n\n", roznicaCzasow.count() * 1e-9);

    // Wyzerowanie ilosci iteracji dla kolejnej metody

    iloscIteracji = 0;

    // Zapisanie danych do pliku

    for (int n = 0; n < N + 1; n++) {
        plik1 << n * h << "   " << gsl_vector_get(y, n) << std::endl;
    }

    // Zamkniecie pliku

    plik1.close();

    // Wyzerowanie wektora y dla kolejnej metody

    gsl_vector_set_zero(y);

    // Mierzenie czasu dla drugiej metody

    poczatek = std::chrono::high_resolution_clock::now(); 

    // Rozwiązanie układu równań metoda Jacobiego

    metodaJacobiego(diag, e, f, b, y, &iloscIteracji);

    // Mierzenie czasu dla drugiego wzoru

    koniec = std::chrono::high_resolution_clock::now(); 
    roznicaCzasow = std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - poczatek);

    // Wypisanie informacji do konsoli

    std::cout<<"Metoda Jacobiego: "<<std::endl<<"Ilosc iteracji: "<<iloscIteracji<<std::endl;
    printf("Czas wykonywania metody: %.3f sekund.\n\n", roznicaCzasow.count() * 1e-9);

    // Wyzerowanie ilosci iteracji dla kolejnej metody

    iloscIteracji = 0;

    for (int n = 0; n < N + 1; n++) {
        plik2 << n * h << "   " << gsl_vector_get(y, n) << std::endl;
    }

    // Zamkniecie pliku

    plik2.close();

    // Wyzerowanie wektora y dla kolejnej metody

    gsl_vector_set_zero(y);

    // Mierzenie czasu dla trzeciej metody

    poczatek = std::chrono::high_resolution_clock::now(); 

    // Rozwiązanie układu równań metoda Gausa-Seidla

    metodaGausaSeidla(diag, e, f, b, y, &iloscIteracji);

    // Mierzenie czasu dla trzeciego wzoru

    koniec = std::chrono::high_resolution_clock::now(); 
    roznicaCzasow = std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - poczatek);

    // Wypisanie informacji do konsoli

    std::cout<<"Metoda Gausa-Seidla: "<<std::endl<<"Ilosc iteracji: "<<iloscIteracji<<std::endl;
    printf("Czas wykonywania metody: %.3f sekund.\n\n", roznicaCzasow.count() * 1e-9);

    // Wyzerowanie ilosci iteracji dla kolejnej metody

    iloscIteracji = 0;

    for (int n = 0; n < N + 1; n++) {
        plik3 << n * h << "   " << gsl_vector_get(y, n) << std::endl;
    }

    // Wyzerowanie wektora y dla kolejnej metody

    gsl_vector_set_zero(y);

    // Zamkniecie pliku

    plik3.close();

    // Mierzenie czasu dla czwartej metody

    poczatek = std::chrono::high_resolution_clock::now(); 

    // Rozwiązanie układu równań Successive OverRelaxation

    successiveOverRelayation(diag, e, f, b, y, &iloscIteracji);

    // Mierzenie czasu dla czwartego wzoru

    koniec = std::chrono::high_resolution_clock::now(); 
    roznicaCzasow = std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - poczatek);

    // Wypisanie informacji do konsoli

    std::cout<<"Successive OverRelaxation: "<<std::endl<<"Ilosc iteracji: "<<iloscIteracji<<std::endl;
    printf("Czas wykonywania metody: %.3f sekund.\n\n", roznicaCzasow.count() * 1e-9);

    for (int n = 0; n < N + 1; n++) {
        plik4 << n * h << "   " << gsl_vector_get(y, n) << std::endl;
    }

    // Zamkniecie pliku

    plik4.close();

    // Zwolnienie pamięci wektorow GSL
    
    gsl_vector_free(diag);
    gsl_vector_free(e);
    gsl_vector_free(f);
    gsl_vector_free(b);
    gsl_vector_free(y);

    return 0;
}
