// Autor: Daniel Szarek,                           Krakow, 23.03.2023r.


//Pliki Naglowkowe

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Funkcja typu Void wypisujaca identyfikatory PID,UID,GID,PPID,PGID dla danego procesu

void wypisanie_informacji()
{
    int id_uzytkownika, id_grupy, id_procesu, id_procesu_przodka, id_grupy_procesow;
    id_uzytkownika = getuid();
    id_grupy = getgid();
    id_procesu = getpid();
    id_procesu_przodka = getppid();
    id_grupy_procesow = getpgrp();
    printf("Informacje na temat Procesu o ID (PID): %d, ID Uzytkownika (UID): %d, ID Grupy (GID): %d, ID Procesu Przodka (PPID): %d, ID Grupy Procesow (PGID): %d\n\n",id_procesu,id_uzytkownika,id_grupy,id_procesu_przodka,id_grupy_procesow);
}