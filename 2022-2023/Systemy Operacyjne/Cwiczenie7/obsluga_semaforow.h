// Autor: Daniel Szarek,                           Krakow, 04.05.2023r.


//Pliki Naglowkowe

#include <semaphore.h>

//Utworzenie semafora binarnego, wskaznik semafor wskazuje na niego

void UtworzSemafor(char nazwa[], sem_t ** semafor);

//Otworzenie semafora binarnego, wskaznik semafor wskazuje na niego

void OtworzSemafor(char nazwa[], sem_t ** semafor);

//Usuniecie semafora

void UsuniecieSemafora(char nazwa[]);

//Zamkniecie semafora

void ZamknijSemafor(sem_t * semafor);

//Uzyskanie wartoscie semafora

int UzyskajWartoscSemafora(sem_t * semafor);

//Opuszczenie semafora

void OpuszczenieSemafora(sem_t * semafor);

//Podniesienie semafora

void PodniesienieSemafora(sem_t * semafor);
