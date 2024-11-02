// Autor: Daniel Szarek,                           Krakow, 06.04.2023r.


//Plik Naglowkowy

#include "funkcje.h"

//Funkcja glowna pobierajaca tablice oraz liczbe danych przy wywolaniu w terminalu, wykonujaca zadanie podane w poleceniu cwiczenie 3b)

int main(int argc, char* argv[])
{
//Obsluga bledow, sprawdzam czy liczba argumentow podana przy wywolaniu jest rowna tej potrzebnej do prawidlowego dzialania programu

    if(argc != 4)
    {
        printf("Liczba argumentow przy wywolaniu %d jest rozna od 4\n",argc);
        exit(1);
    }

//Przeksztalcenie stringa na wejsciu w sciezke poprzez konkatenacje

    char sciezka[100] = "./";
    strcat(sciezka, argv[3]);
    int proces = fork();
    switch(proces)
    {

//Obsluga bledow, sprawdzam czy aby fork() nie zostaje zle utworzony

        case -1:
            perror("Blad fork\n");
            exit(2);
        case 0:

//Wykorzystanie funkcji execlp dla procesu potomnego w ramach otwarcia programu z cwiczenie 3a)

            execlp(sciezka, argv[3], argv[1], argv[2], (char*) NULL);
            perror("Blad execlp\n");
            exit(3);
        default:

//Usypiam proces macierzysty na 2 sekundy, dla pewnosci aby utworzyl sie proces potomny

            sleep(2);
    
//Obsluga bledow, sprawdzam czy proces potomny istnieje zanim podesle do niego sygnal

            if(kill(proces,0)==-1)
            {
                printf("Proces potomny nie istnieje\n");
                exit(4);
            }
            else
            {
                printf("Proces potomny istnieje oraz posiada PID: %d\n",proces);

//Obsluga bledow, sprawdzam czy aby sygnal zostal wyslany w sposob prawidlowy

                if(kill(proces,atoi(argv[2]))==-1)
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

//Wykorzystanie makr podanych w poleceniu w ramach sprawdzenia czy proces zostal zakonczony przez sygnal oraz zwraca jego numer, funkcja strsignal(numersygnalu) na podstawie tego numeru zwraca jego slowna nazwe

                        printf("Status proceu potomnego: %d\n",statuspotomka);
                        if(WIFSIGNALED(statuspotomka) == true)
                        {
                            int numersygnalu = WTERMSIG(statuspotomka);
                            printf("Proces potomny zostal zakonczony przez sygnal o numerze: %d oraz nazwie %s\n",numersygnalu,strsignal(numersygnalu));
                        }
                        else
                        {
                            printf("Proces potomny zostal zakonczony bez uzycia sygnalu\n");
                        }
                    }
                }
            }
    }
    return 0;
}