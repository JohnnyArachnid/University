// Autor: Daniel Szarek,                           Krakow, 06.04.2023r.


//Pliki Naglowkowe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

//Funkcja PID(), wypisujaca PID danego procesu

void PID()
{
    printf("%d\n",getpid());
}

//Funkcja sighandler(int sid), bioraca numer sygnalu i wypisujaca go na ekranie, w ramach wlasnej obslugi sygnalu

void sighandler(int sid)
{
    printf("Wlasna obsluga sygnalu: %d\n",sid);
}