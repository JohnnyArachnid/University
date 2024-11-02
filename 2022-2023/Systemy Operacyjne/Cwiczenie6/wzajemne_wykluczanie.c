// Autor: Daniel Szarek,                           Krakow, 03.05.2023r.


//Pliki Naglowkowe

#include "obsluga_semaforow.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 6

int main(int argc, char * argv[])
{

//Obsluga bledu, sprawdzam czy liczba przy wywolaniu sie zgadza

    if(argc!=4)
    {
		perror("Blad, niewłaściwa ilość argumentów przy wywolaniu\n");
		exit(1);
    }

    int LiczbaSekcjiKrytycznych = atoi(argv[1]);

//Obsluga bledu, sprawdzam czy liczba sekcji krytycznych jest prawidlowa

    if(LiczbaSekcjiKrytycznych==0)
    {
	    perror("Blad atoi lub liczba sekcji krytycznych rowna 0\n");
	    exit(2);
    }

    sem_t * Semafor = NULL;

//Ustawienie punktu startowego dla generowania liczb pseudolosowych

    srand(time(NULL));

//Otworzenie semafora

    OtworzSemafor(argv[2], &Semafor);

    int Plik, NumerZPliku, Czas, LiczbaKoncowa;
    char Bufor[4];
    int i = 0;
    do
    {

//Ustalenie losowej liczby sekund w progu 1-4 sekund w ramach oczekiwania sleep

		Czas = rand()%3 + 1;
        sleep(Czas);
        printf("Proces o PID: %d jest przed sekcja krytyczna\nWartosc semafora wynosi: %d\n",getpid(),UzyskajWartoscSemafora(Semafor));

//Operacja opuszczenia dla semafora binarnego

	OpuszczenieSemafora(Semafor);
	printf("Proces o PID: %d jest w sekcji krytycznej\nWartosc semafora wynosi: %d\n",getpid(),UzyskajWartoscSemafora(Semafor));
	Plik = open(argv[3],O_RDONLY,"rw-r--r--");

//Obsluga bledu, sprawdzam czy plik numer.txt zostal otwarty w prawidlowy sposob

	if(Plik==-1)
	{
	    perror("Blad open\n");
	    exit(3);
	}

//Obsluga bledu, sprawdzam czy read dziala w prawidlowy sposob

	if(read(Plik,Bufor,sizeof(Bufor))==-1)
	{
	    perror("Blad read\n");
	    exit(4);
	}

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

	if(close(Plik)==-1)
	{
	    perror("Blad close\n");
	    exit(5);
	}

//Zamiana string na int

	NumerZPliku = strtol(Bufor, NULL, 10);

//Obsluga bledu, sprawdzam czy strtol dziala w prawidlowy sposob

	if(errno == ERANGE)
	{
	    perror("Blad strtol\n");
	    exit(6);
	}
	printf("Liczba przeczytana z pliku: %d\n", NumerZPliku);
	NumerZPliku++;

//Ustalenie losowej liczby sekund w progu 1-4 sekund w ramach oczekiwania sleep

	Czas = rand()%3 + 1;
	sleep(Czas);

//Zamiana int na string

	LiczbaKoncowa = snprintf(Bufor, 4, "%d", NumerZPliku);

//Obsluga bledu, sprawdzam czy liczba zapisywana do pliku zostala utworzona w prawidlowy sposob oraz czy ma odpowiedni zakres

	if(LiczbaKoncowa < 0 || LiczbaKoncowa >= 4)
	{
		perror("Blad zamiany int na str\n");
		exit(7);
	}
	Plik = open(argv[3],O_WRONLY,"rw-r--r--");

//Obsluga bledu, sprawdzam czy plik numer.txt zostal otwarty w prawidlowy sposob

    if(Plik==-1)
    {
        perror("Blad open\n");
        exit(8);
    }

//Obsluga bledu, sprawdzam czy write dziala w prawidlowy sposob

    if(write(Plik,Bufor,sizeof(Bufor))==-1)
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

	i++;

//Operacja podniesienia dla semafora binarnego

	PodniesienieSemafora(Semafor);
	printf("Proces o PID: %d jest po sekcji krytycznej\nWartosc semafora wynosi: %d\n",getpid(),UzyskajWartoscSemafora(Semafor));
    }while(i < LiczbaSekcjiKrytycznych);
    ZamknijSemafor(Semafor);
}
