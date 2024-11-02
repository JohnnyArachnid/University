// Autor: Daniel Szarek,                           Krakow, 27.05.2023r.


//Pliki Naglowkowe

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

//Watki

//Utworzenie watku

void UtworzenieWatku(pthread_t * IdentyfikatorWatku, void * (*Funkcja)(), int Numer);

//Oczekiwanie na watek przez proces ktory go utworzyl

void OczekiwanieNaWatek(pthread_t IdentyfikatorWatku);

//Mutexy

//Utworzenie mutexu

void UtworzenieMutexu(pthread_mutex_t * Mutex);

//Zamkniecie mutexu

void ZamkniecieMutexu(pthread_mutex_t * Mutex);

//Otwarcie mutexu z wlasnosci mutexu tylko przez watek ktory go zamknal

void OtwarcieMutexu(pthread_mutex_t * Mutex);

//Usuniecie mutexu

void UsuniecieMutexu(pthread_mutex_t * Mutex);
