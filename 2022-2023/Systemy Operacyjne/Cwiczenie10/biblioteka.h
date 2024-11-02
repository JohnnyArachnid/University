// Autor: Daniel Szarek,                           Krakow, 28.05.2023r.


//Pliki Naglowkowe

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

//Definicje parametrow

#define LICZBAWATKOW 4
#define LICZBASEKCJIKRYTYCZNYCH 3

//Maksymalna liczba kolumn ekranu 

#define XMAX 50

//Maksymalna liczba wierszy ekranu

#define YMAX 30

/*Ustawienie pozycji kursora w punkcie o wspolrzednych (x,y) na ekranie
Sekwencja \033[2K powoduje wymazanie poprzedniego napisu w danym wierszu.*/

void UstawienieNapisu(unsigned x, unsigned y);

//Znalezienie najwiekszej wartosci z tablicy numer

int ZnalezienieMaksimum(int numer[]);

//Watki

//Utworzenie watku

void UtworzenieWatku(pthread_t * IdentyfikatorWatku, void * (*Funkcja)(), int Numer);

//Oczekiwanie na watek przez proces ktory go utworzyl

void OczekiwanieNaWatek(pthread_t IdentyfikatorWatku);