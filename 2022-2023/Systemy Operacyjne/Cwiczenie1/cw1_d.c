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

/* Funkcja main() tworzaca procesy potomne [Funkcja Fork()] oraz wypisujaca dla wszystkich procesow ich identyfikatory [Funkcja wypisanie_informacji()], kolejne pokolenia procesow beda wypisywane rownoczesnie, pierwszy proces wypisany bedzie
oryginalnym procesem macierzystym, nastepnie po 2 sekundach wypisze sie pierwszy proces potomny jako reprezentant nastepnego pokolenia, dalej jako para wypisza sie rownoczesnie kolejne procesy potomne jako reprezentanci jednego pokolenia, na koniec wypisza sie rownoczesnie
4 procesy potomne jako reprezentanci jednego pokolenia. Proces macierzysty konczy sie jako ostatni, po procesach potomnych. */

int main()
{
    int i,proces;

    wypisanie_informacji();
    sleep(2); 
    
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
            default:
                sleep(2);   
        }
    }
        
    return 0;
}

// W pliku Odpowiedzi.txt zamiescilem drzewo genealogiczne utworzonych procesow na mojej maszynie.