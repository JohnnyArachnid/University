// Autor: Daniel Szarek,                           Krakow, 23.03.2023r.


//Pliki Naglowkowe

#include "wypisywanie.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/* Funkcja main() tworzaca procesy potomne [Funkcja Fork()] oraz wypisujaca dla wszystkich procesow ich identyfikatory [Funkcja wypisanie_informacji() w pliku naglowkowym wypisywanie.h].
Procesy potomne otwieraja zewnetrzny program dzieki wykorzystaniu funkcji execlp z uzyciem argumentow przekazywanych przez program macierzysty [int argc, char* argv[]]
Proces macierzysty czeka na zakonczenie dzialania procesow potomnych [Funkcja wait(NULL)]
*/

int main(int argc, char* argv[])
{
    int i,proces;

    char sciezka[100] = "./";

    strcat(sciezka, argv[1]);

    printf("Wypisanie Informacji dla Procesu Macierzystego:\n\n");

    wypisanie_informacji();

    printf("Wypisanie Informacji dla Procesow Potomnych:\n\n");

    for(i=0;i<3;i++)
    {
        proces = fork();

        switch(proces)
        {
            case -1:
                perror("Blad fork\n");
                exit(1);
            case 0:
                execlp(sciezka, argv[1], (char*) NULL);
                perror("Blad execlp\n");
                exit(2);
            default:
                wait(NULL);
        }
    }
    return 0;
}