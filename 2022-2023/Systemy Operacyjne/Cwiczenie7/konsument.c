// Autor: Daniel Szarek,                           Krakow, 04.05.2023r.


//Pliki Naglowkowe

#include "obsluga_pamieci_dzielonej.h"
#include "obsluga_semaforow.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 7

int main(int argc, char * argv[])
{

//Obsluga bledu, sprawdzam czy liczba przy wywolaniu sie zgadza

    if(argc!=5)
    {
	    perror("Blad, niewłaściwa ilość argumentów przy wywolaniu\n");
	    exit(1);
    }

//Otworzenie semaforow	

    sem_t * Producentsem=NULL;
    OtworzSemafor(argv[3],&Producentsem);
    sem_t * Konsumentsem=NULL;
    OtworzSemafor(argv[4],&Konsumentsem);

 //Otworzenie i odwzorowanie pamięci dzielonej

    SegmentPD * Seg=NULL;
    int DeskryptorObiektu=OtworzObiektPamieci(&Seg,argv[2],PROT_READ|PROT_WRITE,O_RDWR);

//Otworzenie pliku do wczytywania danych

    int Plik=open(argv[1],O_WRONLY|O_TRUNC,0644);

//Obsluga bledu, sprawdzam czy plik wynik.txt zostal otwarty w prawidlowy sposob

    if(Plik==-1)
    {
		perror("Blad w otwarciu pliku do czytania\n");
        exit(2);
    }

//Wczytywanie danych z pamięci dzielonej i zapisanie do pliku

    char Bufor[NELE+1];
    int LiczbaBajtow, LiczbaZnakow;
    printf("Rozpoczecie wczytywania danych i zapisywania do pliku\n");
    while(Seg->Koniec!=1)
    {

//Operacja opuszczenia dla semafora binarnego konsumenta

	    OpuszczenieSemafora(Konsumentsem);

//Uzycie opoznienia w celu ulatwienia ukazania dzialania programu

        sleep(1);

//Komunikaty dzialania programu w sekcji krytycznej

        printf("Odczytane dane: %s\n",Seg->Bufor[Seg->Uzyskaj]);
	    printf("Odczytane z bufora: %d\n",(Seg->Uzyskaj)+1);

//Wyjecie towaru z bufora NELE + 1, gdyz snprintf nie zapisuje ostatniego znaku w buforze

	    LiczbaZnakow = snprintf(Bufor,NELE+1,"%s",Seg->Bufor[Seg->Uzyskaj]);
	    if(LiczbaZnakow<0||LiczbaZnakow>NELE+1)
	    {
			perror("Blad snprintf lub nieprawidlowe rozmiary plikow\n");
			exit(3);
		}
	    Seg->Uzyskaj=(Seg->Uzyskaj+1)%NBUF;

//Operacja podniesienia dla semafora binarnego producenta

	    PodniesienieSemafora(Producentsem);


//Obsluga bledow przy zapisie    

        if((LiczbaBajtow = write(Plik,Bufor,Seg->Rozmiar))==-1)
        {
            perror("Blad write");
            exit(4);
        }
    }

    //Obsluga bledu, sprawdzam czy close dziala

    if(close(Plik)==-1)
    {
        perror("Blad close\n");
        exit(5);
    }
    ZamknijSemafor(Konsumentsem);
    ZamknijSemafor(Producentsem);
    ZamknijObiektPamieciZOdwzorowaniem(DeskryptorObiektu,Seg);
}
