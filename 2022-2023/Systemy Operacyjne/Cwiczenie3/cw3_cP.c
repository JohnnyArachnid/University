// Autor: Daniel Szarek,                           Krakow, 06.04.2023r.


//Plik Naglowkowy

#include "funkcje.h"

//Funkcja glowna pobierajaca tablice oraz liczbe danych przez funkcje execlp w pliku glownym cw3_cP.c, wykonujaca zadanie podane w poleceniu cwiczenie 3c)

int main(int argc, char* argv[])
{

//Obsluga bledow, sprawdzam czy liczba argumentow podana przy wywolaniu jest rowna tej potrzebnej do prawidlowego dzialania programu

    if(argc != 4)
    {
        printf("Liczba argumentow przy wywolaniu %d jest rozna od 4\n",argc);
        exit(1);
    }
    int i,j,proces,status_procesu;

//Przeksztalcenie stringa na wejsciu w sciezke poprzez konkatenacje

    char sciezka[100] = "./";
    strcat(sciezka, argv[3]);

//Wykorzystanie funkcji signal w celu sprawienia ze pierwszy proces potomny utworzony w pliku cw3_cP.c zignoruje nadchodzacy sygnal rownie z glownego pliku.

    signal(atoi(argv[2]),SIG_IGN);

//Utworzenie tablicy pomocniczej majacej na celu przechowanie kolejnych numerow PID procesow potomnych

    int PID[3];
    for(i=0;i<3;i++)
    {
        proces = fork();
        switch(proces)
        {
            case -1:

//Obsluga bledow, sprawdzam czy aby fork() nie zostaje zle utworzony

                perror("Blad fork\n");
                exit(2);
            case 0:

//Wykorzystanie funkcji execlp dla procesu potomnego w ramach otwarcia programu z cwiczenie 3a)

                execlp(sciezka, argv[3], argv[1], argv[2], (char*) NULL);
                perror("Blad execlp\n");
                exit(3);
            default:
                sleep(1);
                PID[i] = proces;
        }
    }
    for(j=0;j<3;j++)
    {

//Obsluga bledow, sprawdzam czy aby nie doszlo do zawiesza wykonywania bieżącego procesu dopóki potomek określony przez pid nie zakończy działania lub dopóki nie zostanie dostarczony sygnał

        if(waitpid(PID[j],&status_procesu,0) ==-1)
        {
            printf("Blad waitpid\n");
        }
        else
        {
            printf("Status procesu potomnego: %d\n",status_procesu);

//Wykorzystanie makr podanych w poleceniu w ramach sprawdzenia czy proces zostal zakonczony przez sygnal oraz zwraca jego numer, funkcja strsignal na podstawie tego numeru zwraca jego slowna nazwe

            if(WIFSIGNALED(status_procesu) == true)
            {
                int numersygnalu = WTERMSIG(status_procesu);
                printf("Proces potomny zostal zakonczony przez sygnal o numerze: %d oraz nazwie %s\n",numersygnalu,strsignal(numersygnalu));
            }
            else
            {
                printf("Proces potomny zostal zakonczony bez uzycia sygnalu\n");
            }
        }
    }
    return 0;
}