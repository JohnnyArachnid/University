// Autor: Daniel Szarek,                           Krakow, 27.05.2023r.


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

//Utworzenie mutexu

void UtworzenieMutexu(pthread_mutex_t * Mutex)
{
    if((Blad = pthread_mutex_init(Mutex, NULL)) && (Blad != 0))
    {
        printf("Blad pthread_mutex_init: %s\n",strerror(Blad));
        exit(3);
    }
}

//Zamkniecie mutexu

void ZamkniecieMutexu(pthread_mutex_t * Mutex)
{
    if((Blad = pthread_mutex_lock(Mutex)) && (Blad != 0))
    {
        printf("Blad pthread_mutex_lock: %s\n",strerror(Blad));
        exit(4);
    }
}

//Otwarcie mutexu z wlasnosci mutexu tylko przez watek ktory go zamknal

void OtwarcieMutexu(pthread_mutex_t * Mutex)
{
    if((Blad = pthread_mutex_unlock(Mutex)) && (Blad != 0))
    {
        printf("Blad pthread_mutex_unlock: %s\n",strerror(Blad));
        exit(5);
    }
}

//Usuniecie mutexu

void UsuniecieMutexu(pthread_mutex_t * Mutex)
{
    if((Blad = pthread_mutex_destroy(Mutex)) && (Blad != 0))
    {
        printf("Blad pthread_mutex_destroy: %s\n",strerror(Blad));;
        exit(6);
    }
}