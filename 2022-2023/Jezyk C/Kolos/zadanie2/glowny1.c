#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));

typedef struct{
	char imie[18];
	char nazwisko[18];
}Osoba;

int wczytaj(char plik[], Osoba os[])
{
	FILE *fin = fopen(plik, "r");
	if (!fin) exit(-1);
	int i =0;
	while(fscanf(fin,"%s %s",os[i].imie, os[i].nazwisko)==2) i++;
	return i;
}

void wypisz(int n, Osoba os[])
{
	for(int i=0;i<n;i++) printf("%2d. %-18s %-18s\n",i+1,os[i].imie, os[i].nazwisko);
}

int compar(const void *p1, const void *p2)
{
	Osoba *os1 = (Osoba *)p1;
	Osoba *os2 = (Osoba *)p2;

	int n = strcmp((const char *)os1->imie,(const char *)os2->imie);

	if(n) return n;

	return strcmp((const char *)os1->nazwisko,(const char*)os2->nazwisko);
}

int main()
{
	Osoba os[20];
	int n = wczytaj("osoby.txt", os);
	qsort((void *)os, n, sizeof(Osoba), compar);
	wypisz(n,os);
}
