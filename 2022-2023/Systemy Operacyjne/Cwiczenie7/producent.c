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
	    perror("Blad, niewłasciwa ilosc argumentow przy wywolaniu\n");
	    exit(1);
    }

//Otworzenie semaforow	

    sem_t * Producentsem=NULL;
    OtworzSemafor(argv[3],&Producentsem);
    // otworzenie semafora konsumenta
    sem_t * Konsumentsem=NULL;
    OtworzSemafor(argv[4],&Konsumentsem);

//Otworzenie i odwzorowanie pamięci dzielonej

    SegmentPD * Seg=NULL;
    int DeskryptorObiektu = OtworzObiektPamieci(&Seg,argv[2],PROT_READ|PROT_WRITE,O_RDWR);

//Otworzenie pliku do wczytywania danych

    int Plik=open(argv[1],O_RDONLY,0644);

//Obsluga bledu, sprawdzam czy plik dane.txt zostal otwarty w prawidlowy sposob

    if(Plik==-1)
    {
		perror("Blad w otwarciu pliku do czytania\n");
        exit(2);
    }

/*Wczytanie danych z pliku i zapis do pamięci dzielonej
Operacja opuszczenia dla semafora binarnego konsumenta*/

    OpuszczenieSemafora(Konsumentsem);
	char Bufor[NELE+1];
    int LicznikBajtow,LiczbaZnakow,TempDodaj=Seg->Dodaj;
    printf("Rozpoczecie wczytywania danych i zapisywania do pamieci podrecznej\n");

//Tworzenie Towaru
	while((LicznikBajtow=read(Plik,Bufor,NELE))>0)
    {

	//Operacja opuszczenia dla semafora binarnego producenta

		OpuszczenieSemafora(Producentsem);

//Uzycie opoznienia w celu ulatwienia ukazania dzialania programu

        sleep(1);

//Komunikaty dzialania programu w sekcji krytycznej

		printf("Zapisane dane: %s\n",Bufor);
		Seg->Rozmiar = LicznikBajtow;
		printf("Zapisane w buforze: %d\n",(Seg->Dodaj)+1);
		TempDodaj=Seg->Dodaj;
		
//Wsadzanie towaru do bufora NELE + 1, gdyz snprintf nie zapisuje ostatniego znaku w buforze

		LiczbaZnakow=snprintf(Seg->Bufor[Seg->Dodaj],NELE+1,"%s",Bufor);
		if(LiczbaZnakow<0||LiczbaZnakow>NELE+1)
		{
			perror("Blad snprintf lub nieprawidlowe rozmiary plikow\n");
			exit(3);
		}
	
//Zabezpieczenie przy konczeniu cyklu

		if(TempDodaj!=Seg->Dodaj)
		{
			Seg->Dodaj = TempDodaj;
		}
	    Seg->Dodaj=(Seg->Dodaj+1)%NBUF;

//Operacja podniesienia dla semafora binarnego konsumenta

	    PodniesienieSemafora(Konsumentsem);

//Obsluga bledow przy odczycie

        if(LicznikBajtow==-1)
        {
	        perror("read error");
	        exit(4);
        }
    }

//Zakończono produkowanie towaru

    Seg->Koniec=1;

//Obsluga bledu, sprawdzam czy close dziala w sposob prawidlowy	

    if(close(Plik)==-1)
    {
		perror("Blad close\n");
		exit(5);
    }
    ZamknijSemafor(Producentsem);
    ZamknijSemafor(Konsumentsem);
    ZamknijObiektPamieciZOdwzorowaniem(DeskryptorObiektu,Seg);
}
