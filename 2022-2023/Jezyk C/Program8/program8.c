#include <stdio.h>
#include <stdlib.h>
#include "osoba.h"

int wczytaj(char [], Osoba []);

void wypisz(Osoba [], int);

void sortowanie(Osoba [], int, int(*)(Osoba os1, Osoba os2));

int porownanie(Osoba os1, Osoba os2);

int main()
{
	Osoba lista[50];
	int n = wczytaj("in.dat",lista);
	printf("Osoby przed sortowaniem: \n");
	wypisz(lista, n);
	sortowanie(lista, n, &porownanie);
	printf("Osoby po sortowaniu: \n"); 
	wypisz(lista, n);
	printf("Wczytano: %d osob\n",n);
	return 0;
}
