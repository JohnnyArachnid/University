// Autor: Daniel Szarek
//=====================

#include <iostream>
#include <gsl/gsl_linalg.h>
#include <fstream>

const int N = 1e3; // Stala zmienna N podana w poleceniu

const double h = 1e-2; // Staka zmienna h podana w poleceniu

const int h2 = 1e4; // Zmienna h^2, w obliczaniu (D2y)n dzielimy przez 1e-4, ale dzielenie przez mala liczbe nie jest wydajne lepiej zamiast tego pomnozyc przez odwrotnosc ulamka, czyli wlasnie 1e4

// Algorytm Thomasa w celu rozwiazania wartosci zmiennych wektora y

void algorytmThomasa(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, const gsl_vector *b, gsl_vector *y) {

    // Tworzenie wektorow tymczasowych

    gsl_vector *e_temp = gsl_vector_alloc(N);
    gsl_vector *b_temp  = gsl_vector_alloc(N + 1);

    // Inicjacja współczynnikow w pierwszym wierszu wektorow tymczasowych GSL

    gsl_vector_set(e_temp, 0, gsl_vector_get(e, 0) / gsl_vector_get(diag, 0));
    gsl_vector_set(b_temp, 0, gsl_vector_get(b, 0) / gsl_vector_get(diag, 0));

    // Wypelnienie współczynnikow od 1 do konca rozmiaru wektorow tymczasowych GSL

    for (int i = 1; i < N; i++) {
        double m = 1.0 / (gsl_vector_get(diag, i) - gsl_vector_get(f, i - 1) * gsl_vector_get(e_temp, i - 1));
        gsl_vector_set(e_temp, i, gsl_vector_get(e, i) * m);
    }

    for (int i = 1; i < N + 1; i++) {
        double m = 1.0 / (gsl_vector_get(diag, i) - gsl_vector_get(f, i - 1) * gsl_vector_get(e_temp, i - 1));
        gsl_vector_set(b_temp, i, (gsl_vector_get(b, i) - gsl_vector_get(f, i - 1) * gsl_vector_get(b_temp, i - 1)) * m);
    }

    // Operacja back substitution, aby zaktualizować wektor rozwiązania y

    gsl_vector_set(y, N, gsl_vector_get(b_temp, N));

    for (int i = N - 1; i >= 0; i--) {
        gsl_vector_set(y, i, gsl_vector_get(b_temp, i) - gsl_vector_get(e_temp, i) * gsl_vector_get(y, i + 1));
    }

    // Zwolnienie pamięci wektorow tymczasowych GSL

    gsl_vector_free(e_temp);
    gsl_vector_free(b_temp);
}

// Wpisanie danych do wektorów GSL

void wypenienieWektoraB(gsl_vector *b){
    gsl_vector_set_all(b, 0);
    gsl_vector_set(b, 0, 1);
}

void wypelnienieWektoraDiagonalnegoDiag(gsl_vector *diag){
    gsl_vector_set_all(diag, (-2 * h2) + 1);
    gsl_vector_set(diag, 0, 1);
    gsl_vector_set(diag, N, 1);
}

void wypenienieWektoraTrojdiagonalnegoGornegoE(gsl_vector *e){
    gsl_vector_set_all(e, h2);
    gsl_vector_set(e, 0, 0);
}

void wypenienieWektoraTrojdiagonalnegoDolnegoF(gsl_vector *f){
    gsl_vector_set_all(f, h2);
    gsl_vector_set(f, N-1, 0);
}

int main() {

    // Inicjalizacja wektorów GSL

    gsl_vector *diag = gsl_vector_alloc(N + 1); // wektor diagonalny
    gsl_vector *e = gsl_vector_alloc(N); // wektor subdiagonalny
    gsl_vector *f = gsl_vector_alloc(N); // wektor supdiagonalny
    gsl_vector *b = gsl_vector_alloc(N + 1); // wektor z wynikami rownan liniowych
    gsl_vector *y = gsl_vector_alloc(N + 1); // wektor niewiadomych

    //Wypelnienie wektor GSL

    wypenienieWektoraB(b);
    wypelnienieWektoraDiagonalnegoDiag(diag);
    wypenienieWektoraTrojdiagonalnegoGornegoE(e);
    wypenienieWektoraTrojdiagonalnegoDolnegoF(f);

    // Rozwiązanie układu równań

    // Gotowa funkcja z biblioteki GSL

    //gsl_linalg_solve_tridiag(diag, e, f, b, y);

    algorytmThomasa(diag, e, f, b, y);

    // Wyświetlenie wyników

    // std::cout << "Rozwiązanie układu równań:" << std::endl;
    // for (int n = 0; n < N + 1; n++) {
    //     std::cout << "y[" << n << "] = " << gsl_vector_get(y, n) << " dla nh = " << n * h << std::endl;
    // }

    // Zwolnienie pamięci wektorow GSL
    
    gsl_vector_free(diag);
    gsl_vector_free(e);
    gsl_vector_free(f);
    gsl_vector_free(b);

    // Nazwa pliku
    
    const char* sciezkaPliku = "wyniki.txt";

    // Otwórzenie pliku do zapisu danych do wykresu

    std::ofstream plik(sciezkaPliku);

    // Sprawdzenie, czy udało się otworzyć plik z danymi do wykresu

    if (!plik.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    for (int n = 0; n < N + 1; n++) {
        plik << n * h << "   " << gsl_vector_get(y, n) << std::endl;
    }

    // Zamkniecie wektora y

    gsl_vector_free(y);

    // Zamkniecie pliku

    plik.close();

    return 0;
}
