#include <stdio.h>
#include <math.h>

double wyznacznik(double tablica[2][2])
{
	long double wynik = tablica[0][0] * tablica[1][1] - (tablica[0][1] * tablica[1][0]);
	return wynik;
}
