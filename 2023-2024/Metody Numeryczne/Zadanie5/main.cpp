// Autor: Daniel Szarek
//=====================

#include <iostream>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix_double.h>
#include <gsl/gsl_matrix.h>
#include <fstream>

const int N = 1e3; // Stala zmienna N podana w poleceniu

const double h = 1e-2; // Staka zmienna h podana w poleceniu

const int h2 = 1e4; // Zmienna h^2, w obliczaniu (D2y)n dzielimy przez 1e-4, ale dzielenie przez mala liczbe nie jest wydajne lepiej zamiast tego pomnozyc przez odwrotnosc ulamka, czyli wlasnie 1e4

// Tworzenie macierzy 3 na 3 utworzonego z 2 pierwszych wierszy oraz ostatniego wiersza układu równań

gsl_matrix * tworzenieMacierzy3na3(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f){

    // Utworzenie macierzy GSL układu 3 na 3 o nazwie A wypelniona zerami

    gsl_matrix * A = gsl_matrix_calloc(3,3);

    // Przypisanie wartości macierzy GSL A na diagonali

    for(int i = 0; i < 2; i++) { gsl_matrix_set(A, i, i, gsl_vector_get(diag, i)); }

    gsl_matrix_set(A, 2, 2, 1);

    // Przypisanie wartości macierzy GSL A na subdiagonali oraz supdiagonali
 
    gsl_matrix_set(A, 0, 1, gsl_vector_get(e, 0));
    gsl_matrix_set(A, 1, 0, gsl_vector_get(f, 0));
    gsl_matrix_set(A, 1, 2, gsl_vector_get(e, 1));
    gsl_matrix_set(A, 2, 0, -3);
    gsl_matrix_set(A, 2, 1, 4);

    // Wartosci kolejno 1, -3, oraz 4, biorą się z tego że nasza macierz tworzona jest tak jak napisałem powyżej z 2 pierwszych wierszy oraz ostatniego wiersza układu równań, dzięki czemu otrzymamy układ 3 na 3, który łatwo możemy rozwiązać i wyznaczyć wartości y1 oraz y2

    return A;
}

// Rozwiązanie układu równań 3 na 3 macierzy 3 na 3 utworzonego z 2 pierwszych wierszy oraz ostatniego wiersza układu równań

void rozwiazanieUkladuRownan3na3(gsl_matrix* A, const gsl_vector* bTemp, gsl_vector* yTemp) {

    // Utworzenie wektora permutacji GSL do funkcji gsl_linalg_LU_solve w celu rozwiązania układu równań

    gsl_permutation* p = gsl_permutation_alloc(3);

    // Zmienna przechowująca informację o parzystości liczby permutacji wykonanych podczas faktoryzacji LU macierzy A

    int signum;

    // Algorytm faktoryzacji LU

    gsl_linalg_LU_decomp(A, p, &signum);

    // Rozwiązanie układu równań, wykorzystuje w tym celu gotową funckję z biblioteki GSL gsl_linalg_LU_solve

    gsl_linalg_LU_solve(A, p, bTemp, yTemp);

    // Zwolnienie pamięci wektora permutacji GSL

    gsl_permutation_free(p);
}

// Funkcja w celu w celu rozwiazania wartosci zmiennych wektora y

void rozwiazanieOstateczne(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, const gsl_vector *b, const gsl_vector *yTemp, gsl_vector *y){

    // Wyluskanie wartosci y z rozwiazania ukladu 3 na 3

    double wartoscYTemp1 = gsl_vector_get(yTemp, 1);
    double wartoscYTemp2 = gsl_vector_get(yTemp, 2);

    // Przypisanie wartosci z rozwiazania ukladu 3 na 3 do glownego rozwiazania

    gsl_vector_set(y, 0, gsl_vector_get(yTemp, 0));
    gsl_vector_set(y, 1, wartoscYTemp1);
    gsl_vector_set(y, 2, wartoscYTemp2);

    // Utworzenie zmiennych pomocniczych w celu rozwiazania rekurencyjnego

    double zmienna1, zmienna2, zmienna3, wynik;

    for(int i = 2; i < N; i++){
        zmienna1 = gsl_vector_get(e, i - 1);
        zmienna2 = gsl_vector_get(diag, i);
        zmienna3 = gsl_vector_get(f, i - 1);
        wynik = (gsl_vector_get(b, i) - zmienna1 * wartoscYTemp1 - zmienna2 * wartoscYTemp2) / zmienna3;
        gsl_vector_set(y, i + 1, wynik);
        wartoscYTemp1 = wartoscYTemp2;
        wartoscYTemp2 = wynik;
    }

}

// Wpisanie danych do wektorów GSL

void wypenienieWektoraB(gsl_vector *b){
    gsl_vector_set_all(b, 0);
    gsl_vector_set(b, 0, 1);
}

void wypenienieWektorabTemp(gsl_vector *bTemp, gsl_vector *b){
    gsl_vector_set(bTemp, 0, gsl_vector_get(b, 0));
    gsl_vector_set(bTemp, 1, gsl_vector_get(b, 1));
    gsl_vector_set(bTemp, 2, gsl_vector_get(b, N));
}

void wypelnienieWektoraDiagonalnegoDiag(gsl_vector *diag){
    gsl_vector_set_all(diag, (-2 * h2) + 1);
    gsl_vector_set(diag, 0, 1);
    gsl_vector_set(diag, N, 0);
}

void wypenienieWektoraTrojdiagonalnegoGornegoE(gsl_vector *e){
    gsl_vector_set_all(e, h2);
    gsl_vector_set(e, 0, 0);
}

void wypenienieWektoraTrojdiagonalnegoDolnegoF(gsl_vector *f){
    gsl_vector_set_all(f, h2);
    gsl_vector_set(f, N - 1, 0);
}

int main() {

    // Inicjalizacja wektorów GSL

    gsl_vector *diag = gsl_vector_alloc(N + 1); // wektor diagonalny
    gsl_vector *e = gsl_vector_alloc(N); // wektor subdiagonalny
    gsl_vector *f = gsl_vector_alloc(N); // wektor supdiagonalny
    gsl_vector *b = gsl_vector_alloc(N + 1); // wektor z wynikami rownan liniowych
    gsl_vector *bTemp = gsl_vector_alloc(3); // wektor z wynikami rownan liniowych ukladu 3 na 3
    gsl_vector *y = gsl_vector_alloc(N + 1); // wektor niewiadomych
    gsl_vector *yTemp = gsl_vector_alloc(3); // wektor niewiadomych ukladu 3 na 3

    //Wypelnienie wektor GSL

    wypenienieWektoraB(b);
    wypelnienieWektoraDiagonalnegoDiag(diag);
    wypenienieWektoraTrojdiagonalnegoGornegoE(e);
    wypenienieWektoraTrojdiagonalnegoDolnegoF(f);
    wypenienieWektorabTemp(bTemp, b);

    // Rozwiązanie układu równań 3 na 3

    gsl_matrix * A =  tworzenieMacierzy3na3(diag, e, f);
    rozwiazanieUkladuRownan3na3(A, bTemp, yTemp);
    rozwiazanieOstateczne(diag, e, f, b, yTemp, y);

    // Wyświetlenie wyników

    // std::cout << "Rozwiązanie układu równań:" << std::endl;
    // for (int n = 0; n < N + 1; n++) {
    //     std::cout << "y[" << n << "] = " << gsl_vector_get(y, n) << " dla nh = " << n * h << std::endl;
    // }

    // Zwolnienie pamięci wektorow i macierzy A GSL

    gsl_vector_free(diag);
    gsl_vector_free(e);
    gsl_vector_free(f);
    gsl_vector_free(b);
    gsl_matrix_free(A);
    gsl_vector_free(yTemp);

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