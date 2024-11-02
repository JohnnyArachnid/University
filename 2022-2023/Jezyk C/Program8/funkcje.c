#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "osoba.h"

int porownanie(Osoba os1, Osoba os2)
{
	int n = strcmp(os1.nazwisko, os2.nazwisko);
	if(n) return n;
	int i = strcmp(os1.imie, os2.imie);
	if(i) return i;
	n = os1.wiek - os2.wiek;
	if(n!=0) return n;
	double m;
	m = os1.pensja - os2.pensja;
	if(n>0)
	{
			return 1;
	}else if(m<0)
	{
			return -1;
	}
	return 0;
}

void sortowanie(Osoba lista[], int n, int (*porownanie)(Osoba, Osoba))
{
	Osoba tmp;
	for(int k=n-1;k>0;k--)
	{
		for(int i=0;i<k;i++)
		{
			if(porownanie(lista[i],lista[i+1])>0)
			{
				tmp = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = tmp;
			}
		}
	}
}

void wypisz(Osoba lista[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%s %s %d %10.2f\n",lista[i].imie, lista[i].nazwisko, lista[i].wiek, lista[i].pensja);
	}
}

int wczytaj(char plik[], Osoba lista[])
{
	FILE *fin = fopen(plik,"r");

	if(!fin)
	{
		printf("Blad otwarcia pliku, plik nie istnieje\n");
		exit(-1);
	}
	else
	{
		int licznik = 0;

		while(fscanf(fin, "%s %s %d %lg", lista[licznik].imie,lista[licznik].nazwisko,&lista[licznik].wiek,&lista[licznik].pensja) == 4)
		{
			/* printf("Osoba nr. %d o Imieniu: %s, Nazwisku: %s, Wieku: %d, Pensji: %lg\n",(licznik+1),lista[licznik].imie,lista[licznik].nazwisko,lista[licznik].wiek,lista[licznik].pensja);
			 Wypisywanie kolejnych elementow struktury ktore zamieszczone sa w tablicy */
			licznik++;
		}
		return licznik;
	}
}

