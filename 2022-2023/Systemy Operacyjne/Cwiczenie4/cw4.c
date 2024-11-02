// Autor: Daniel Szarek,                           Krakow, 12.04.2023r.


//Pliki Naglowkowe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

//Funkcja glowna pliku, realizujaca zadania podane w poleceniu cwiczenia 4

int main()
{

//Utworzenie tablicy w ramach przechowania dwoch deskryptorow plikow

    int plik[2];

//Obsluga bledu, sprawdzam czy plik towar1.txt zostal otwarty w prawidlowy sposob

    int plik1 = open("./towar1.txt",O_RDONLY,"rw-r--r--");
    if(plik1==-1)
    {
        perror("Blad w otwarciu pliku do czytania\n");
        exit(1);
    }

    plik[0] = plik1;

//Obsluga bledu, sprawdzam czy plik towar2.txt zostal otwarty w prawidlowy sposob

    int plik2 = open("./towar2.txt",O_WRONLY,"rw-r--r--");
    if(plik2==-1)
    {
        perror("Blad w otwarciu pliku do wypisywania\n");
        exit(2);
    }

    plik[1] = plik2;


//Utworzenie tablicy w ramach przechowania dwoch deskryptorow dla potoku

    int potok[2];

//Obsluga bledu, sprawdzam czy pipe zostal utworzony w sposob prawidlowy

    if(pipe(potok)==-1)
    {
        perror("Blad w pipe\n");
        exit(3);
    }

    int proces = fork();

//Rozmiar pliku z ktorego bedziemy sczytywac dane

    int rozmiar = 5;
    switch(proces)
        {

//Obsluga bledow, sprawdzam czy aby fork() nie zostaje zle utworzony

        case -1:
            perror("Blad w fork\n");
            exit(4);
        case 0:

//Obsluga Producenta w potoku

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

            if(close(potok[0])==-1)
            {
                perror("Blad w close\n");
                exit(5);
            }
            printf("Producent zaczyna pobieranie surowca:\n");
            int losowa1,towar1,i;

//Ustawienie punktu startowego dla generowania liczb pseudolosowych

            srand(time(NULL));
            for(i=0;i<rozmiar;i++)
            {
//Obsluga bledu, sprawdzam czy read dziala w prawidlowy sposob, Wczytanie zmiennej typu Char z pliku

                if(read(plik[0],&towar1,sizeof(char))==-1)
                {
                    perror("Blad w read\n");
                    exit(6);
                }

//Ustalenie losowej liczby sekund w progu 1-6 sekund w ramach oczekiwania sleep podanego w poleceniu

                losowa1 = rand()%5+1;
                sleep(losowa1);
                printf("Surowiec nr.%d: %c\n",i+1,(char)towar1);

//Obsluga bledu sprawdzam czy write dziala w sposob prawidlowy

                if(write(potok[1],&towar1,sizeof(char))==-1)
                {
                    perror("Blad w write\n");
                    exit(7);
                }

/*Operacja dodania znaku konca lini do potoku, moj program dziala dla typu char stad taki zabieg jest konieczny
Obsluga bledow, sprawdzam czy read oraz write dziala w prawidlowy sposob*/

                if(read(plik[0],&towar1,sizeof(char))==-1)
                {
                    perror("Blad w read\n");
                    exit(8);
                }
                if(write(potok[1],&towar1,sizeof(char))==-1)
                {
                    perror("Blad w write\n");
                    exit(9);
                }
            }

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

            if(close(potok[1])==-1)
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

//Obsluga Konsumenta w potoku

//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob

            if(close(potok[1])==-1)
            {
                perror("Blad w close\n");
                exit(12);
            }
            printf("Konsument zaczyna pobieranie towaru:\n");
            int losowa2,towar2,j; 
            for(j=0;j<rozmiar;j++)
            {

//Obsluga bledu, sprawdzam czy read dziala w prawidlowy sposob

                if(read(potok[0],&towar2,sizeof(char))==-1)
                {
                    perror("Blad w read\n");
                    exit(13);
                }

//Ustalenie losowej liczby sekund w progu 1-6 sekund w ramach oczekiwania sleep podanego w poleceniu

                losowa2 = rand()%5+1;
                sleep(losowa2);
                printf("Towar nr.%d: %c\n",j+1,(char)towar2);

//Obsluga bledu, sprawdzam czy write dziala w prawidlowy sposob, Wypisanie zmiennej typu Char do pliku

                if(write(plik[1],&towar2,sizeof(char))==-1)
                {
                    perror("Blad w write\n");
                    exit(14);
                }

/*Operacja dodania znaku konca lini do pliku, moj program dziala dla typu char stad taki zabieg jest konieczny
Obsluga bledow, sprawdzam czy read oraz write dziala w prawidlowy sposob*/

                if(read(potok[0],&towar2,sizeof(char))==-1)
                {
                    perror("Blad w read\n");
                    exit(15);
                }
                if(write(plik[1],&towar2,sizeof(char))==-1)
                {
                    perror("Blad w write\n");
                    exit(16);
                }
            }
            
//Obsluga bledu, sprawdzam czy close dziala w prawidlowy sposob
            
            if(close(potok[0])==-1)
            {
                perror("Blad w close\n");
                exit(17);
            }
            if(close(plik[1])==-1)
            {
                perror("Blad w close\n");
                exit(18);
            }
        break;
    }

    return 0;
}
