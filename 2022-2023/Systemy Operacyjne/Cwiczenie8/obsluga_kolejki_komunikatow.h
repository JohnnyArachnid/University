// Autor: Daniel Szarek,                           Krakow, 24.05.2023r.

//Pliki Naglowkowe

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//Definicje parametrow

#define NAZWAKOLEJKIKOMUNIKATOWSERWERA "/serwer"
#define POCZATEKNAZWY "/"
#define ROZMIARTRESCIKOMUNIKATUODBIERANIA 8192
#define ROZMIARTRESCIKOMUNIKATUWYSYLANIA 75
#define DLUGOSCNAZWYKOLEJKIKOMUNIKATOW 50

//Utworzenie kolejki komunikatow

mqd_t UtworzKolejkeKomunikatow(char * NazwaKolejkiKomunikatow);

//Otworzenie kolejki komunikatow

mqd_t OtworzKolejkeKomunikatow(char * NazwaKolejkiKomunikatow);

//Wyslanie komunikatu do danej kolejki komunikatow

void WyslanieKomunikatu(mqd_t DeskryptorKolejkiKomunikatow, char * TrescKomunikatu);

//Odbior komunikatu z danej kolejki komunikatow

void OdbiorKomunikatu(mqd_t DeskryptorKolejkiKomunikatow, char * TrescKomunikatu);

//Zamkniecie danej kolejki komunikatow

void ZamknijKolejeKomunikatow(mqd_t DeskryptorKolejkiKomunikatow);

//Usuniecie danej kolejki komunikatow

void UsunKolejkeKomunikatow(char * NazwaKolejkiKomunikatow);

