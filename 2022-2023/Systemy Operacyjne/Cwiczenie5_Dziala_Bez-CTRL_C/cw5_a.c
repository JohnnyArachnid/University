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

//Funkcja usuwajaca potok nazwany po zakonczeniu programu

void funkcja()
{
    unlink("./myfilo");
}

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 5a

int main()
{

//Wywolanie funkcji usuwajacej potok nazwany po zakonczeniu programu

    atexit(funkcja);

//Utworzenie potoku nazwanego o prawie dostepu do pliku 0644

    mkfifo("./myfilo", 0644);

//Utworzenie tablicy w ramach przechowania trzech deskryptorow plikow

    int plik[3];

//Obsluga bledu, sprawdzam czy plik towar1.txt zostal otwarty w prawidlowy sposob

    int plik1 = open("./towar1.txt",O_RDONLY,"rw-r--r--");
    if(plik1==-1)
    {
        perror("Blad w otwarciu pliku do czytania\n");
        exit(2);
    }

    plik[0] = plik1;

//Obsluga bledu, sprawdzam czy plik towar2.txt zostal otwarty w prawidlowy sposob

    int plik2 = open("./towar2.txt",O_WRONLY,"rw-r--r--");
    if(plik2==-1)
    {
        perror("Blad w otwarciu pliku do wypisywania\n");
        exit(3);
    }

    plik[1] = plik2;

//Obsluga bledu, sprawdzam czy potok nazwany o nazwie myfilo zostal otwarty w prawidlowy sposob

    int plik3 = open("./myfilo",O_RDWR,"rw-r--r--");
    if(plik3==-1)
    {
        perror("Blad w otwarciu pipe\n");
        exit(4);
    }

    plik[2] = plik3;

//Utworzenie tablicy w ramach przechowania dwoch deskryptorow dla potoku rozmiaru pliku1 odczytujacego

    int rozmiar[2];

//Obsluga bledu, sprawdzam czy pipe dla rozmiaru zostal utworzony w sposob prawidlowy    

    if(pipe(rozmiar)==-1)
    {
        perror("Blad w pipe\n");
        exit(5);
    }        

//Tworze proces potomny do realizacji problemu producent konsument, gdzie producentem bedzie proces potomny, a konsumentem proces macierzysty

    int proces = fork();

//Utworzenie tablicy w ramach przechowywania danych, to bedzie moj bufor

    char bufor[PIPE_BUF];

//Ustalam rozmiar bufora

    int rozmiar_bufora = 82;

    switch(proces)
        {

//Obsluga bledow, sprawdzam czy aby fork() nie zostaje zle utworzony

        case -1:
            perror("Blad w fork\n");
            exit(6);
        case 0:

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

            if(close(rozmiar[0])==-1)
            {
                perror("Blad w close\n");
                exit(7);
            }
            printf("Producent zaczyna pobieranie surowca:\n");
            int losowa1,licznik1=0;

//Ustawienie punktu startowego dla generowania liczb pseudolosowych

            srand(time(NULL));
            while(read(plik[0],&bufor,rozmiar_bufora)>0)
            {

//Ustalenie losowej liczby sekund w progu 1-6 sekund w ramach oczekiwania sleep podanego w poleceniu

                losowa1 = rand()%5+1;
                sleep(losowa1);
                printf("Surowiec nr.%d: %s\n",licznik1+1,bufor);

//Obsluga bledu, sprawdzam czy write dziala w sposob prawidlowy

                if(write(plik[2],&bufor,rozmiar_bufora)==-1)
                {
                    perror("Blad w write\n");
                    exit(8);
                }
                licznik1+=1;
            }

//Obsluga bledu, sprawdzam czy write dziala w sposob prawidlowy

            if(write(rozmiar[1],&licznik1,sizeof(int))==-1)
            {
                perror("Blad w write\n");
                exit(9);
            }

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

            if(close(rozmiar[1])==-1)
            {
                perror("Blad w close\n");
                exit(10);
            }
            if(close(plik[0])==-1)
            {
                perror("Blad w close\n");
                exit(11);
            }
        break;

        default:

//Oczekiwanie az proces potomny, producent zakonczy swoje dzialanie

            wait(NULL);

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

            if(close(rozmiar[1])==-1)
            {
                perror("Blad w close\n");
                exit(12);
            }
            printf("Konsument zaczyna pobieranie towaru:\n");
            int losowa2,licznik2;

//Obsluga bledu, sprawdzam czy read dziala w sposob prawidlowy

            if(read(rozmiar[0],&licznik2,sizeof(int))==-1)
            {
                perror("Blad w read\n");
                exit(13);
            }
            for(int i=0;i<licznik2;i++)
            {

//Obsluga bledu, sprawdzam czy read dziala w sposob prawidlowy

                if(read(plik[2],&bufor,rozmiar_bufora)==-1)
                {
                    perror("Blad w write\n");
                    exit(14);
                }

//Ustalenie losowej liczby sekund w progu 1-6 sekund w ramach oczekiwania sleep podanego w poleceniu

                losowa2 = rand()%5+1;
                sleep(losowa2);
                printf("Towar nr.%d: %s\n",i+1,bufor);

//Obsluga bledu, sprawdzam czy write dziala w sposob prawidlowy

                if(write(plik[1],&bufor,rozmiar_bufora)==-1)
                {
                    perror("Blad w write\n");
                    exit(15);
                }
            }
            
//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

            if(close(rozmiar[0])==-1)
            {
                perror("Blad w close\n");
                exit(16);
            }
            if(close(plik[1])==-1)
            {
                perror("Blad w close\n");
                exit(17);
            }
            if(close(plik[2])==-1)
            {
                perror("Blad w close\n");
                exit(18);
            }
        }
    return 0;
}
