// Autor: Daniel Szarek,                           Krakow, 17.03.2023r.


//Pliki Naglowkowe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Funkcja typu Void wypisujaca identyfikatory PID,UID,GID,PPID,PGID dla danego procesu

void wypisanie_informacji()
{
    int id_uzytkownika, id_grupy, id_procesu, id_procesu_przodka, id_grupy_procesow;
    id_uzytkownika = getuid();
    id_grupy = getgid();
    id_procesu = getpid();
    id_procesu_przodka = getppid();
    id_grupy_procesow = getpgrp();
    printf("Informacje na temat Procesu o ID (PID): %d, ID Uzytkownika (UID): %d, ID Grupy (GID): %d, ID Procesu Przodka (PPID): %d, ID Grupy Procesow (PGID): %d\n",id_procesu,id_uzytkownika,id_grupy,id_procesu_przodka,id_grupy_procesow);
}

// Funkcja main() tworzaca procesy potomne [Funkcja Fork()] oraz wypisujaca dla wszystkich procesow ich identyfikatory [Funkcja wypisanie_informacji()], funkcja sleep(5) sprawi ze powstaja procesy 'zombie' przez uspienie procesu na 5 sekund.

int main()
{
    int i,proces;

    wypisanie_informacji();
    
    for(i=0;i<3;i++)
    {
        proces = fork();
        switch(proces)
        {
            case -1:
                perror("Blad fork\n");
                exit(1);
            case 0:
                wypisanie_informacji();
                sleep(5);
            default:
                continue;   
        }
    }
        
    return 0;
}

// W pliku Odpowiedzi.txt zamiescilem dowod dzialania programu na mojej maszynie, zindentyfikowalem proces adoptujacy procesy 'zombie' jako systemmd o PID: 1660.