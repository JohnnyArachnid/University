// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

int main() {

    // Inicjalizacja macierzy A i wektora z wartosciami wlasnymi tej macierzy GSL

    gsl_vector *wartosciWlasneMacierzyA = gsl_vector_alloc(N);
    gsl_matrix *A = gsl_matrix_alloc(N, N);

    // Wypelnienie macierzy A GSL

    wypelnienieMacierzyA(A);

    // Nazwa pliku z rozwiazaniem zadania
    
    const char* sciezkaPliku = "wyniki.txt";

    // Otwórzenie pliku do zapisu danych rozwiazan ukladu rownan

    std::ofstream plik(sciezkaPliku);

    // Sprawdzenie, czy udało się otworzyć plik do zapisu danych rozwiazan ukladu rownan

    if (!plik.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    // Znalezienie wartosci wlasnych macierzy A GSL

    // Metoda Potegowa

    metodaPotegowa(A, wartosciWlasneMacierzyA);

    // Wyświetlenie wyników w terminalu dla metody potegowej

    std::cout << "Wartosci wlasne macierzy A uzyskane dzieki metodzie potegowej:" << std::endl;
    for (int n = 0; n < N; n++) {
        printf("λ[%d] = %.10lf \n", n, gsl_vector_get(wartosciWlasneMacierzyA, n));
    }

    // Zapisanie danych do pliku do zapisu danych rozwiazan ukladu rownan

    plik << "Metoda Potegowa:"<< std::endl;
    for (int n = 0; n < N; n++) {
        plik << "λ["<< n <<"] = " << gsl_vector_get(wartosciWlasneMacierzyA, n) << std::endl;
    }

    // Metoda Rayleigha

    metodaRayleigha(A, wartosciWlasneMacierzyA);

    // Wyświetlenie wyników w terminalu dla metody Rayleigha

    std::cout << "Wartosci wlasne macierzy A uzyskane dzieki metodzie Rayleigha:" << std::endl;
    for (int n = 0; n < N; n++) {
        printf("λ[%d] = %.10lf \n", n, gsl_vector_get(wartosciWlasneMacierzyA, n));
    }

    // Zapisanie danych do pliku do zapisu danych rozwiazan ukladu rownan

    plik << "Metoda Potegowa:"<< std::endl;
    for (int n = 0; n < N; n++) {
        plik << "λ["<< n <<"] = " << gsl_vector_get(wartosciWlasneMacierzyA, n) << std::endl;
    }

    // Metoda Iteracyjna QR

    metodaIteracyjnaQR(A, wartosciWlasneMacierzyA);

    // Wyświetlenie wyników w terminalu dla metody Iteracyjnej QR

    std::cout << "Wartosci wlasne macierzy A uzyskane dzieki metodzie iteracyjnej QR:" << std::endl;
    for (int n = 0; n < N; n++) {
        printf("λ[%d] = %.10lf \n", n, gsl_vector_get(wartosciWlasneMacierzyA, n));
    }

    // Zapisanie danych do pliku

    plik << "Metoda Iteracyjna QR:"<< std::endl;
    for (int n = 0; n < N; n++) {
        plik << "λ["<< n <<"] = " << gsl_vector_get(wartosciWlasneMacierzyA, n) << std::endl;
    }

    // Zamkniecie pliku

    plik.close();

    // Zwolnienie pamięci macierzy A i wektora z wartosciami wlasnymi tej macierzy GSL
    
    gsl_vector_free(wartosciWlasneMacierzyA);
    gsl_matrix_free(A);

    return 0;
}
