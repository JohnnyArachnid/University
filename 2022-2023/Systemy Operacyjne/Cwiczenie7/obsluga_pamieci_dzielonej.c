// Autor: Daniel Szarek,                           Krakow, 04.05.2023r.


//Pliki Naglowkowe

#include "obsluga_pamieci_dzielonej.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

//Sprawienie ze funkcja ftruncate przestaje byc nie zadeklarowana, wykorzystanie makr podanych w manual funkcji ftruncate w terminalu

#define _BSD_SOURCE || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED || _POSIX_C_SOURCE >= 200112L

//Utworzenie obiektu pamieci dzielonej

int UtworzObiektPamieci(char * nazwa)
{
    int deskryptor = shm_open(nazwa,O_RDWR | O_EXCL | O_CREAT,0644);
    if(deskryptor==-1)
    {
	    perror("Blad utworzenia obiektu pamieci dzielonej\n");
	    exit(1);
    }
    if(ftruncate(deskryptor,sizeof(SegmentPD))==-1)
    {
	    perror("Blad nadania dlugosci obiektowi pamieci dzielonej\n");
	    exit(2);
    }
    return deskryptor;
}

//Otworzenie obiektu pamieci dzielonej z odwzorowaniem pamieci

int OtworzObiektPamieci(SegmentPD ** adres, char * nazwa, int prot, int flagi)
{
    int deskryptor = shm_open(nazwa,flagi,0644);
    if(deskryptor==-1)
    {
	    perror("Blad otworzenia obiektu pamieci dzielonej, Blad shm_open\n");
	    exit(3);
    }
    *adres = (SegmentPD *)mmap(NULL,sizeof(SegmentPD),prot,MAP_SHARED,deskryptor,0);
    if(*adres==(void *)-1)
    {
	    perror("Blad otworzenia obiektu pamieci dzielonej, Blad mmap\n");
	    exit(4);
    }
    return deskryptor;
}

//Zamknięcie obiektu pamieci dzielonej bez odwzorowania pamieci

void ZamknijObiektPamieci(int deskryptor)
{
    if(close(deskryptor)==-1)
    {
        perror("Blad zamknienia obiektu pamieci dzielonej\n");
        exit(5);
    }
}

//Zamknięcie obiektu pamieci dzielonej z odwzorowaniem pamieci

void ZamknijObiektPamieciZOdwzorowaniem(int deskryptor, SegmentPD * adres)
{
    if(munmap((void *)adres,sizeof(SegmentPD))==-1)
    {
        perror("Blad zamknienia obiektu pamieci dzielonej z odwzorowaniem, Blad munmap\n");
        exit(6);
    }
    if(close(deskryptor)==-1)
    {
        perror("Blad zamknienia obiektu pamieci dzielonej z odwzorowaniem, Blad close\n");
        exit(7);
    }

}

//Usuniecie obiektu pamieci dzielonej

void UsunObiektPamieci(char * nazwa)
{
    if(shm_unlink(nazwa)==-1)
    {
        perror("Blad usuniecia obiektu pamieci dzielonej\n");
        exit(8);
    }
}
