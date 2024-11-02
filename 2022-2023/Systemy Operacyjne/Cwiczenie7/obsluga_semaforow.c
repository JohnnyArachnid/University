// Autor: Daniel Szarek,                           Krakow, 04.05.2023r.


//Pliki Naglowkowe

#include "obsluga_semaforow.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

//Utworzenie semafora binarnego, wskaznik semafor wskazuje na niego

void UtworzSemafor(char nazwa[], sem_t ** semafor)
{
    *semafor = sem_open(nazwa,O_EXCL | O_CREAT,0644,1);
    if(*semafor==SEM_FAILED)
    {
	    perror("Blad utworzenia semafora\n");
	    exit(1);
    }
}

//Otworzenie semafora binarnego, wskaznik semafor wskazuje na niego

void OtworzSemafor(char nazwa[], sem_t ** semafor)
{
    *semafor = sem_open(nazwa, 0);
    if(*semafor==SEM_FAILED)
    {
	    perror("Blad otworzenia semafora\n");
	    exit(2);
    }
}

//Usuniecie semafora

void UsuniecieSemafora(char nazwa[])
{
    if(sem_unlink(nazwa)==-1)
    {
	    perror("Blad usuniecia semafora\n");
	    exit(3);
    }
}

//Zamkniecie semafora

void ZamknijSemafor(sem_t * semafor)
{
    if(sem_close(semafor)==-1)
    {
	    perror("Blad zamkniecia semafora\n");
	    exit(4);
    }
}

//Uzyskanie wartosci semafora

int UzyskajWartoscSemafora(sem_t * semafor)
{
    int wartosc;
    if(sem_getvalue(semafor, &wartosc)==-1)
    {
	    perror("Blad uzyskania wartosci semafora\n");
	    exit(5);
    }
    return wartosc;
}


//Operacja PB(S) dla semafora binarnego (opuszczenie)

void OpuszczenieSemafora(sem_t * semafor)
{
    if(sem_wait(semafor)==-1)
    {
	    perror("Blad opuszczenia wartosci semafora\n");
        exit(6);
    }
}

//Operacja VB(S) dla semafora binarnego (podniesienie)

void PodniesienieSemafora(sem_t * semafor)
{
    if(sem_post(semafor)==-1)
    {
	    perror("Blad podniesienia wartosci semafora\n");
	    exit(7);
    }
}
