// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

int main() {

    // Inicjalizacja wektorów oraz macierzy GSL

    gsl_matrix *A = gsl_matrix_alloc(N, N); // macierz ukladu rownan
    gsl_vector *x = gsl_vector_calloc(N); // wektor niewiadomych
    gsl_vector *b = gsl_vector_alloc(N); // wektor z wynikami rownan liniowych

    //Wypelnienie wektorow oraz macierzy GSL

    wypelnienieMacierzyA(A);
    wypenienieWektoraB(b);

    // Rozwiązanie układu równań metoda Gradientow Sprzezonych

    metodaGradientowSprzezonych(A, b, x);

    // Nazwa pliku z rozwiazaniem
    
    const char* sciezkaPliku = "wyniki.txt";

    // Otwórzenie pliku do zapisu danych rozwiazan ukladu rownan

    std::ofstream plik(sciezkaPliku);

    // Sprawdzenie, czy udało się otworzyć plik z danymi do wykresow

    if (!plik.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    // Zapisanie danych do pliku z danymi do wykresow

    for (int n = 0; n < N; n++) {
        plik <<"x["<< n <<"] = " << gsl_vector_get(x, n) << std::endl;
    }

    // Wyswietlenie danych w terminalu

    for (int n = 0; n < N; n++) {
        std::cout <<"x["<< n <<"] = " << gsl_vector_get(x, n) << std::endl;
    }

    // Zamkniecie pliku z danymi do wykresow

    plik.close();

    // Zwolnienie pamięci wektorow oraz macierzy GSL
    
    gsl_matrix_free(A);
    gsl_vector_free(x);
    gsl_vector_free(b);

    return 0;
}
