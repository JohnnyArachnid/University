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

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 5

int main()
{    

//Utworzenie tablicy w ramach przechowania dwoch deskryptorow plikow

    int plik[2];

//Obsluga bledu, sprawdzam czy plik towar1.txt zostal otwarty w prawidlowy sposob

    int plik1 = open("./towar2.txt",O_WRONLY,"rw-r--r--");
    if(plik1==-1)
    {
        perror("Blad w otwarciu pliku do czytania\n");
        exit(1);
    }

    plik[0] = plik1;

//Obsluga bledu, sprawdzam czy plik towar2.txt zostal otwarty w prawidlowy sposob

    int plik2 = open("./myfilo",O_RDWR,"rw-r--r--");
    if(plik2==-1)
    {
        perror("Blad w otwarciu pipe\n");
        exit(2);
    }

    plik[1] = plik2;

//Utworzenie tablicy w ramach przechowywania danych, to bedzie moj bufor

    char bufor[PIPE_BUF];

//Ustalam rozmiar bufora

    int rozmiar_bufora = 82;
    printf("Konsument zaczyna pobieranie towaru:\n");
    int losowa1,licznik1=0,dane_zapisu;

//Ustawienie punktu startowego dla generowania liczb pseudolosowych

    srand(time(NULL));
    while((dane_zapisu=read(plik[1],&bufor,rozmiar_bufora))&&(dane_zapisu)>0)
    {
    
//Ustalenie losowej liczby sekund w progu 1-6 sekund w ramach oczekiwania sleep podanego w poleceniu

        losowa1 = rand()%5+1;
        sleep(losowa1);
        printf("Towar nr.%d: %s\n",licznik1+1,bufor);

//Obsluga bledu, sprawdzam czy write dziala w sposob prawidlowy

        if(write(plik[0],&bufor,rozmiar_bufora)==-1)
        {
            perror("Blad w write\n");
            exit(3);
        }
        licznik1+=1;
    }

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

    if(close(plik[0])==-1)
    {
        perror("Blad w close\n");
        exit(4);
    }
    if(close(plik[1])==-1)
    {
        perror("Blad w close\n");
        exit(5);
    }
    return 0;
}
