// Autor: Daniel Szarek,                           Krakow, 06.04.2023r.


//Plik Naglowkowy

#include "funkcje.h"

//Funkcja glowna pobierajaca tablice oraz liczbe danych przy wywolaniu w terminalu, wykonujaca zadanie podane w poleceniu cwiczenie 3c)

int main(int argc, char* argv[])
{

//Obsluga bledow, sprawdzam czy liczba argumentow podana przy wywolaniu jest rowna tej potrzebnej do prawidlowego dzialania programu

    if(argc != 5)
    {
        printf("Liczba argumentow przy wywolaniu %d jest rozna od 4\n",argc);
        exit(1);
    }

//Przeksztalcenie stringa na wejsciu w sciezke poprzez konkatenacje

    char sciezka[100] = "./";
    strcat(sciezka, argv[4]);
    int proces = fork();
    switch(proces)
    {

//Obsluga bledow, sprawdzam czy aby fork() nie zostaje zle utworzony

        case -1:
            perror("Blad fork\n");
            exit(2);
        case 0:

//Ustalenie przez funkcje serpgid jako lidera nowej grupy procesow pierwszego procesu potomnego

            setpgid(0,proces);

//Wykorzystanie funkcji execlp dla procesu potomnego w ramach otwarcia programu cw3_cP.c

            execlp(sciezka, argv[4], argv[1], argv[2], argv[3], (char*) NULL);
            perror("Blad execlp\n");
            exit(3);
        default:

//Usypiam proces macierzysty na 5 sekundy, dla pewnosci aby utworzyly sie procesy potomne

            sleep(5);

//Pobranie numeru nowej grupy procesow, tak jak to jest podane w poleceniu

            int numergrupy = getpgid(proces);

//Obsluga bledow, sprawdzam czy grupa procesow potomnych istnieje zanim podesle do nich sygnal

            if(kill(-(numergrupy),0)==-1)
            {
                printf("Grupa procesow potomnych nie istnieje\n");
                exit(4);
            }
            else
            {   
                printf("Grupa procesow potomny istnieje oraz posiada PGID: %d\n",numergrupy);

//Obsluga bledow, sprawdzam czy aby sygnal zostal wyslany w sposob prawidlowy

                if(kill(-(numergrupy),atoi(argv[2]))==-1)
                {
                    printf("Blad przeslania sygnalu\n");
                    exit(5);
                }
                else
                {
                    int statuspotomka;

//Obsluga bledow, sprawdzam czy aby wait dziala w sposob prawidlowy

                    if(wait(&statuspotomka)==-1)
                    {
                        printf("Blad wait\n");
                        exit(6);
                    }
                    else
                    {
                        printf("Status lidera grupy procesow: %d\n",statuspotomka);

//Wykorzystanie makr podanych w poleceniu cwiczenie 3b) w ramach sprawdzenia czy lider grupy procesow potomnych zostal zakonczony przez sygnal oraz zwraca jego numer, funkcja strsignal na podstawie tego numeru zwraca jego slowna nazwe

                        if(WIFSIGNALED(statuspotomka) == true)
                        {
                            int numersygnalu = WTERMSIG(statuspotomka);
                            printf("Lider grupy procesow potomnych zostal zakonczony przez sygnal o numerze: %d oraz nazwie %s\n",numersygnalu,strsignal(numersygnalu));
                        }
                        else
                        {
                            printf("Lider grupy procesow potomnych zostal zakonczony bez uzycia sygnalu\n");
                        }
                    }
                }
            }
    }
    return 0;
}