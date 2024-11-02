// Autor: Daniel Szarek,                           Krakow, 04.05.2023r.


//Pliki Naglowkowe

#include "obsluga_pamieci_dzielonej.h"
#include "obsluga_semaforow.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define ROZMIARSCIEZKI 50
#define POCZATEKSCIEZKA "./"

char NazwaSemaforaProducenta[ROZMIARSCIEZKI],NazwaSemaforaKonsumenta[ROZMIARSCIEZKI],NazwaPamieciDzielonej[ROZMIARSCIEZKI];

//Funkcje do usuwania semaforow oraz obiektu pamieci dzielonej

void CzyszczenieAtexit(void)
{
    UsuniecieSemafora(NazwaSemaforaProducenta);
    UsuniecieSemafora(NazwaSemaforaKonsumenta);
    UsunObiektPamieci(NazwaPamieciDzielonej);
}

void CzyszczenieAtexitSygnal(int sig)
{
    CzyszczenieAtexit();
    _exit(1);
}

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 7

int main(int argc, char * argv[])
{

//Obsluga bledu, sprawdzam czy liczba argumentow przy wywolaniu sie zgadza

    if(argc!=8)
    {
	    perror("Blad, niewłaściwa ilość argumentów przy wywolaniu\n");
	    exit(2);
    }

//Kopia do tablicy nazwy semaforow oraz obiektu pamieci dzielonej

    int i,RozmiarNazwy[3];
    RozmiarNazwy[0]=snprintf(NazwaPamieciDzielonej,ROZMIARSCIEZKI,"%s",argv[5]);
    RozmiarNazwy[1]=snprintf(NazwaSemaforaProducenta,ROZMIARSCIEZKI,"%s",argv[6]);
    RozmiarNazwy[2]=snprintf(NazwaSemaforaKonsumenta,ROZMIARSCIEZKI,"%s",argv[7]);
for(i=0;i<3;i++)
    {

//Obsluga bledu, sprawdzam czy nazwy programow zostaly utworzone prawidlowo

        if(RozmiarNazwy[i]<0||RozmiarNazwy[i]>=ROZMIARSCIEZKI)
	    {
            perror("Blad snprintf lub nieprawidlowe rozmiary plikow\n");
            exit(3);
	    }
    }

//Zainicjowanie semaforow    

    sem_t * Producentsem=NULL;
    UtworzSemafor(NazwaSemaforaProducenta,&Producentsem);
    sem_t * Konsumentsem= NULL;
    UtworzSemafor(NazwaSemaforaKonsumenta,&Konsumentsem);

//Obsluga bledu, sprawdzam czy inicjacja funkcji usuwajacej semafor oraz obiekt pamieci dzielonej wykonywanej przed zakonczeniem programu dziala

    if(atexit(CzyszczenieAtexit)!=0)
    {
	    perror("Blad atexit\n");
	    exit(4);
    }

//Wlasna obsluga sygnalu podanego w poleceniu, usuwanie semafora oraz obiektu pamieci dzielonej

    if(signal(SIGINT,CzyszczenieAtexitSygnal)==SIG_ERR)
    {
	    perror("Blad signal\n");
	    exit(5);
    }

//Konkatenacja nazwy programow z poczatkiem sciezki

    char TablicaSciezek[4][ROZMIARSCIEZKI];
    int RozmiarPliku[4];
    for(i=0;i<4;i++)
    {
        RozmiarPliku[i]=snprintf(TablicaSciezek[i],ROZMIARSCIEZKI,"%s%s",POCZATEKSCIEZKA,argv[i+1]);

//Obsluga bledu, sprawdzam czy nazwy programow zostaly utworzone prawidlowo

        if(RozmiarPliku[i]<0 || RozmiarPliku[i]>=ROZMIARSCIEZKI)
	    {
            perror("Blad snprintf lub nieprawidlowe rozmiary plikow\n");
            exit(6);
	    }
    }

//Utworzenie obiektu pamieci dzielonej
    
    int DeskryptorObiektu=UtworzObiektPamieci(NazwaPamieciDzielonej);
    ZamknijObiektPamieci(DeskryptorObiektu);

//Przypisanie wartosci poczatkowych dla Dodaj i Uzyskaj, Ustawienie wartosci Koniec na 0 w pamięci dzielonej

    SegmentPD * Seg=NULL;
    DeskryptorObiektu=OtworzObiektPamieci(&Seg,NazwaPamieciDzielonej,PROT_READ | PROT_WRITE,O_RDWR);
    Seg->Dodaj=0;
    Seg->Uzyskaj=0;
    Seg->Koniec=0;
    ZamknijObiektPamieciZOdwzorowaniem(DeskryptorObiektu,Seg);

//Tworzenie tablicy do przechowywania pid procesow potomnych

    int Procesy[2];
    int Proces,StatusProcesu;
    for(i=0;i<2;i++)
    {
	    Proces=fork();
	    switch(Proces)
	    {

//Obsluga bledu, sprawdzam czy proces potomny zostal utworzony prawidlowo

            case -1:
                perror("Blad fork\n");
                exit(7);
            case 0:
                execlp(TablicaSciezek[i],argv[i+1],TablicaSciezek[i+2],NazwaPamieciDzielonej,NazwaSemaforaProducenta,NazwaSemaforaKonsumenta,(char *)NULL);
                perror("Blad execlp\n");
                CzyszczenieAtexit();
                _exit(8);
            default:
                Procesy[i]=Proces;
	    }
    }
    for(i=0;i<2;i++)
    {
        if(waitpid(Procesy[i],&StatusProcesu,0)==-1)
        {
            perror("Blad waitpid\n");
            exit(9);
        }
    }
    ZamknijSemafor(Producentsem);
    ZamknijSemafor(Konsumentsem);
}
