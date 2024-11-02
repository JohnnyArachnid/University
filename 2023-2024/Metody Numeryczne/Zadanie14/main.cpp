// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

int main() {

    // Deklaracja wektora GSL z wynikami metod calkowania

    gsl_vector *wyniki = gsl_vector_alloc(3);

    // Deklaracja iteratora do zliczania iteracji metod

    int iterator;

    // Nazwy pliku z rozwiazaniami
    
    const char* sciezkaPliku = "wyniki.txt";

    // Otwórzenie pliku do zapisu rozwiazan

    std::ofstream plik(sciezkaPliku);

    // Sprawdzenie, czy udało się otworzyć plik do zapisu rozwiazan

    if (!plik.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu rozwiazan." << std::endl;
        return 1;
    }

    // Wypelnienie wektora rozwiazaniami metod

    gsl_vector_set(wyniki, 0, metodaTrapezow(&iterator));

    // Wyswietlenie danych w terminalu

    std::cout<<"Metoda Trapezow"<<std::endl;
    printf("%lf \n", gsl_vector_get(wyniki, 0));
    std::cout<<"Ilosc iteracji: "<<iterator<<std::endl;

    // Zapisanie danych do pliku do zapisu rozwiazan

    plik<<"Metoda Trapezow"<<std::endl;
    plik<<gsl_vector_get(wyniki,0)<<std::endl;
    plik<<"Ilosc iteracji: "<<iterator<<std::endl;

    // Wypelnienie wektora rozwiazaniami metod

    gsl_vector_set(wyniki, 1, metodaSimpsona(&iterator));

    // Wyswietlenie danych w terminalu

    std::cout<<"Metoda Simpsona"<<std::endl;
    printf("%lf \n", gsl_vector_get(wyniki, 1));
    std::cout<<"Ilosc iteracji: "<<iterator<<std::endl;

    // Zapisanie danych do pliku do zapisu rozwiazan

    plik<<"Metoda Simpsona"<<std::endl;
    plik<<gsl_vector_get(wyniki,1)<<std::endl;
    plik<<"Ilosc iteracji: "<<iterator<<std::endl;

    // Wypelnienie wektora rozwiazaniami metod

    gsl_vector_set(wyniki, 2, regula38(&iterator));

    // Wyswietlenie danych w terminalu

    std::cout<<"Regula 3/8"<<std::endl;
    printf("%lf \n", gsl_vector_get(wyniki, 2));
    std::cout<<"Ilosc iteracji: "<<iterator<<std::endl;    

    // Zapisanie danych do pliku do zapisu rozwiazan

    plik<<"Regula 3/8"<<std::endl;
    plik<<gsl_vector_get(wyniki,2)<<std::endl;
    plik<<"Ilosc iteracji: "<<iterator<<std::endl;

    // Zamkniecie pliku do zapisu rozwiazan

    plik.close();

    // Zwolnienie pamięci wektora GSL
    
    gsl_vector_free(wyniki);

    return 0;
}