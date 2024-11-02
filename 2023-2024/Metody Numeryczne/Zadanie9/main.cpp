// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

int main() {

    // Inicjalizacja wektorów GSL

    gsl_vector *diag = gsl_vector_alloc(N); // wektor diagonalny macierzy A GSL
    gsl_vector *e = gsl_vector_alloc(N - 1); // wektor supdiagonalny macierzy A GSL
    gsl_vector *f = gsl_vector_alloc(N - 1); // wektor subdiagonalny macierzy A GSL
    gsl_vector *wartosciWlasneMacierzyA = gsl_vector_calloc(iloscWartosciIWektorowWlasnych); // wektor z wartosciami wlasnymi macierzy A GSL
    gsl_vector * tablicaWektorowWlasnychMacierzyA[iloscWartosciIWektorowWlasnych]; // tablica z wektorami wlasnymi macierzy A GSL
    for (int i = 0; i < iloscWartosciIWektorowWlasnych; i++) { tablicaWektorowWlasnychMacierzyA[i] = gsl_vector_alloc(N); } // wektory wlasne macierzy A GSL

    //Wypelnienie wektorów GSL

    wypelnienieWektoraDiagonalnego(diag);
    wypenienieWektoraTrojdiagonalnego(e);
    wypenienieWektoraTrojdiagonalnego(f);

    // Znalezienie wartosci wlasnych oraz wektorow wlasnych macierzy A GSL

    odwroconaMetodaPotegowa(diag, e, f, wartosciWlasneMacierzyA, tablicaWektorowWlasnychMacierzyA);

    // Wyświetlenie wyników w terminalu

    for (int n = 0; n < iloscWartosciIWektorowWlasnych; n++) {
        std::cout << "Wartosc wlasna macierzy A:" << std::endl;
        printf("λ[%d] = %.10lf \n", n, gsl_vector_get(wartosciWlasneMacierzyA, n));
        std::cout << "Wektor wlasny macierzy A:" << std::endl;
        gsl_vector_fprintf(stdout, tablicaWektorowWlasnychMacierzyA[n], "%g");
        std::cout << std::endl;
    }

    // Nazwa plikow z rozwiazaniem
    
    const char* sciezkaPliku1 = "wyniki1.txt";
    const char* sciezkaPliku2 = "wyniki2.txt";
    const char* sciezkaPliku3 = "wyniki3.txt";
    const char* sciezkaPliku4 = "wyniki4.txt";

    // Otwórzenie plikow do zapisu wektorow wlasnych

    std::ofstream plik1(sciezkaPliku1);
    std::ofstream plik2(sciezkaPliku2);
    std::ofstream plik3(sciezkaPliku3);
    std::ofstream plik4(sciezkaPliku4);

    // Sprawdzenie, czy udało się otworzyć pliki do zapisu wektorow wlasnych

    if (!plik1.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    if (!plik2.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    if (!plik3.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    if (!plik4.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
        return 1;
    }
    
    // Zapisanie danych do pliku do zapisu wektorow wlasnych

    for (int n = 0; n < N; n++) {
        plik1 << n << " " << gsl_vector_get(tablicaWektorowWlasnychMacierzyA[0], n) << std::endl;
        plik2 << n << " " << gsl_vector_get(tablicaWektorowWlasnychMacierzyA[1], n) << std::endl;
        plik3 << n << " " << gsl_vector_get(tablicaWektorowWlasnychMacierzyA[2], n) << std::endl;
        plik4 << n << " " << gsl_vector_get(tablicaWektorowWlasnychMacierzyA[3], n) << std::endl;
    }

    // Zamkniecie plikow do zapisu wektorow wlasnych

    plik1.close();
    plik2.close();
    plik3.close();
    plik4.close();    

    // Zwolnienie pamięci wektorow GSL
    
    gsl_vector_free(diag);
    gsl_vector_free(e);
    gsl_vector_free(f);
    gsl_vector_free(wartosciWlasneMacierzyA);
    for (int i = 0; i < iloscWartosciIWektorowWlasnych; i++) { gsl_vector_free(tablicaWektorowWlasnychMacierzyA[i]); }

    return 0;
}
