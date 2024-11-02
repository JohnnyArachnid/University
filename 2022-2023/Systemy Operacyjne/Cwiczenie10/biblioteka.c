// Autor: Daniel Szarek,                           Krakow, 28.05.2023r.


//Plik Naglowkowy

#include "biblioteka.h"

//Zmienna globalna Blad do obslugi bledow w ramach strerror

int Blad;

/*Ustawienie pozycji kursora w punkcie o wspolrzednych (x,y) na ekranie
Sekwencja \033[2K powoduje wymazanie poprzedniego napisu w danym wierszu.*/

void UstawienieNapisu(unsigned x, unsigned y)
{
    printf("\033[%d;%dH\033[2K", y, x);
}

//Znalezienie najwiekszej wartosci z tablicy numer

int ZnalezienieMaksimum(int numer[])
{
    int Max = 0;
    for(int i = 0; i < LICZBAWATKOW; i++)
    {
        if(numer[i] > Max)
        {
            Max = numer[i];
        }
    }
    return Max;
}

//Watki

//Utworzenie watku

void UtworzenieWatku(pthread_t * IdentyfikatorWatku, void * (*Funkcja)(), int Numer)
{

//Przydzielenie pamieci

    int *Index = malloc(sizeof(int));
    *Index = Numer;
    if((Blad = pthread_create(IdentyfikatorWatku, NULL, Funkcja, Index)) && (Blad != 0))
    {
        printf("Blad pthread_create: %s\n",strerror(Blad));
        exit(1);
    }
}

//Oczekiwanie na watek przez proces ktory go utworzyl

void OczekiwanieNaWatek(pthread_t IdentyfikatorWatku)
{
    if((Blad = pthread_join(IdentyfikatorWatku, NULL)) && (Blad != 0))
    {
        printf("Blad pthread_join: %s\n",strerror(Blad));
        exit(2);
    }
}