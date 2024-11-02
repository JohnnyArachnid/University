// Autor: Daniel Szarek,                           Krakow, 26.04.2023r.


//Pliki Naglowkowe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/param.h>

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 5b

int main()
{

//Utworzenie tablicy w ramach przechowania trzech deskryptorow plikow

    int plik[3];

//Obsluga bledu, sprawdzam czy plik towar1.txt zostal otwarty w prawidlowy sposob

    int plik1 = open("./towar1.txt",O_RDONLY,"rw-r--r--");
    if(plik1==-1)
    {
        perror("Blad w otwarciu pliku do czytania\n");
        exit(1);
    }

    plik[0] = plik1;

//Obsluga bledu, sprawdzam czy potok nazwany o nazwie myfilo zostal otwarty w prawidlowy sposob

    int plik2 = open("./myfilo",O_RDWR,"rw-r--r--");
    if(plik2==-1)
    {
        perror("Blad w otwarciu pipe\n");
        exit(2);
    }

    plik[1] = plik2;

//Obsluga bledu, sprawdzam czy potok nazwany o nazwie myfilorozmiar zostal otwarty w prawidlowy sposob

    int plik3 = open("./myfilorozmiar",O_RDWR,"rw-r--r--");
    if(plik3==-1)
    {
        perror("Blad w otwarciu pipe\n");
        exit(3);
    }

    plik[2] = plik3;             

//Utworzenie tablicy w ramach przechowywania danych, to bedzie moj bufor

    char bufor[PIPE_BUF];

//Ustalam rozmiar bufora

    int rozmiar_bufora = 82;
    printf("Producent zaczyna pobieranie surowca:\n");
    int losowa1,licznik1=0,dane_odczytu;

//Ustawienie punktu startowego dla generowania liczb pseudolosowych

    srand(time(NULL));
    while((dane_odczytu=read(plik[0],&bufor,rozmiar_bufora))&&(dane_odczytu)>0)
    {

//Ustalenie losowej liczby sekund w progu 1-6 sekund w ramach oczekiwania sleep podanego w poleceniu

        losowa1 = rand()%5+1;
        sleep(losowa1);
        printf("Surowiec nr.%d: %s\n",licznik1+1,bufor);

//Obsluga bledu, sprawdzam czy write dziala w sposob prawidlowy

        if(write(plik[1],&bufor,rozmiar_bufora)==-1)
        {
            perror("Blad w write\n");
            exit(4);
        }
        licznik1+=1;
    }

//Obsluga bledu, sprawdzam czy write dziala w sposob prawidlowy

    if(write(plik[2],&licznik1,sizeof(int))==-1)
    {
        perror("Blad w write\n");
        exit(5);
    }

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

    if(close(plik[0])==-1)
    {
        perror("Blad w close\n");
        exit(6);
    }
    if(close(plik[1])==-1)
    {
        perror("Blad w close\n");
        exit(7);
    }
    if(close(plik[2])==-1)
    {
        perror("Blad w close\n");
        exit(8);
    }
    return 0;
}

