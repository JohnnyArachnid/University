// Autor: Daniel Szarek,                           Krakow, 03.05.2023r.


//Pliki Naglowkowe

#include "obsluga_semaforow.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define NAZWA_SEMAFORA "Semafor"
#define ROZMIAR_SCIEZKI 50
#define POCZATEK_SCIEZKA "./"

//Funkcje do usuwania semafora

void CzyszczenieSemaforaAtexit(void)
{
    UsuniecieSemafora(NAZWA_SEMAFORA);
}

void CzyszczenieSemaforaSygnal(int sig)
{
    CzyszczenieSemaforaAtexit();
    _exit(1);
}

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 6

int main(int argc, char* argv[])
{

//Obsluga bledu, sprawdzam czy liczba przy wywolaniu sie zgadza

    if(argc!=5)
    {
	    perror("Blad, niewłaściwa ilość argumentów przy wywolaniu\n");
	    exit(2);
    }

    sem_t * Semafor = NULL;

//Utworzenie i zainicjowanie semafora

    UtworzSemafor(NAZWA_SEMAFORA, &Semafor);

//Obsluga bledu, sprawdzam czy inicjacja funkcji usuwajacej semafor wykonywanej przed zakonczeniem programu dziala

    if(atexit(CzyszczenieSemaforaAtexit)!= 0)
    {
	    perror("Blad atexit\n");
	    exit(3);
    }

//Wlasna obsluga sygnalu podanego w poleceniu, usuwanie semafora

    if(signal(SIGINT,CzyszczenieSemaforaSygnal)==SIG_ERR)
    {
	    perror("Blad signal\n");
	    exit(4);
    }

//Konkatenacja nazwy programow do wywołania w procesie potomnym z poczatkiem sciezki

    char TablicaPlikow[2][ROZMIAR_SCIEZKI];    
    int RozmiarPliku1 = snprintf(TablicaPlikow[0], ROZMIAR_SCIEZKI, "%s%s", POCZATEK_SCIEZKA, argv[1]);
    int RozmiarPliku2 = snprintf(TablicaPlikow[1], ROZMIAR_SCIEZKI, "%s%s", POCZATEK_SCIEZKA, argv[4]);

//Obsluga bledu, sprawdzam czy nazwy programow zostaly utworzone prawidlowo
    
    if( RozmiarPliku1 < 0 || RozmiarPliku2 < 0 || RozmiarPliku1 >= ROZMIAR_SCIEZKI || RozmiarPliku2 >= ROZMIAR_SCIEZKI)
    {
	    perror("Blad snprintf lub nieprawidlowe rozmiary plikow\n");
	    exit(5);
    }

//Zamiana string na int

    int LiczbaProcesow = atoi(argv[2]);

//Obsluga bledu, sprawdzam czy liczba procesow jest prawidlowa

    if(LiczbaProcesow==0)
    {
	    perror("Blad atoi lub liczba procesow rowna 0\n");
	    exit(6);
    }
    int LiczbaSekcjiKrytycznych = atoi(argv[3]);

//Obsluga bledu, sprawdzam czy liczba sekcji krytycznych jest prawidlowa

    if(LiczbaSekcjiKrytycznych==0)
    {
	    perror("Blad atoi lub liczba sekcji krytycznych rowna 0\n");
	    exit(7);
    }

//Otworzenie pliku numer.txt i wpisanie do niego wartosci 0

    int Plik = open(TablicaPlikow[1],O_WRONLY | O_CREAT | O_TRUNC,"rw-r--r--");

//Obsluga bledu, sprawdzam czy plik numer.txt zostal otwarty w prawidlowy sposob

    if(Plik==-1)
    {
        perror("Blad w otwarciu pliku do czytania\n");
        exit(8);
    }

//Deklaracja zmiennej przechowujacej 0, potem liczbe zmodyfikowana przez procesy w ramach pracy w semaforze

    char Numer[4];
    Numer[0] = '0';

//Obsluga bledu, sprawdzam czy write dziala w prawidlowy sposob

    if(write(Plik,&Numer,sizeof(char))==-1)
    {
        perror("Blad write\n");
        exit(9);
    }

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

    if(close(Plik)==-1)
    {
	    perror("Blad close\n");
	    exit(10);
    }

//Tworzenie tablicy do przechowywania pid procesow potomnych

    int Procesy[LiczbaProcesow];
    int i,Proces,StatusProcesu;
    for(i=0;i<LiczbaProcesow;i++)
    {
        Proces = fork();
        switch(Proces)
        {
            case -1:
                perror("Blad fork\n");
                exit(11);
            case 0:
                execlp(TablicaPlikow[0], argv[1], argv[3], NAZWA_SEMAFORA, TablicaPlikow[1], (void*)NULL);
                CzyszczenieSemaforaAtexit();
                perror("Blad execlp\n");
                _exit(12);
            default:

//Przyporzadkowanie pid procesow potomnych do miejsc w tablicy odpowiadajacych ich utworzeniu

            Procesy[i] = Proces;
	    }
    }

//Utworzenie petli analogicznej w zadaniu 3, oczekiwanie aż wszystkie procesy się zakończą

    for(i=0;i<LiczbaProcesow;i++)
    {

//Obsluga bledu, sprawdzam czy waitpid dziala w prawidlowy sposob

        if(waitpid(Procesy[i],&StatusProcesu,0)==-1)
	    {
	        perror("Blad waitpid\n");
	        exit(13);
	    }
    }

//Sprawdzenie czy numer w pliku numer.txt, zgadza się z oczekiwanym numerem ktory wynosi iloczyn ilości procesów i ilości sekcji krytycznych

    Plik = open(TablicaPlikow[1],O_RDONLY,"rw-r--r--");

//Obsluga bledu, sprawdzam czy read dziala w prawidlowy sposob

    if(read(Plik,Numer,sizeof(Numer))==-1)
    {
	    perror("Blad read\n");
	    exit(14);
    }

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

    if(close(Plik)==-1)
    {
	    perror("Blad close\n");
	    exit(15);
    }
    printf("Liczba Oczekiwana w pliku: %d\nLiczba Otrzymana z pliku: %s\n", LiczbaProcesow*LiczbaSekcjiKrytycznych,Numer);
    ZamknijSemafor(Semafor);
}
