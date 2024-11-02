#include <stdio.h>

double wyznacznik(double a[2][2])
{
	return (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
}

int uklad2(double a[2][2], double b[2], double xy[2])
{
	double wyznacznikGlowny = wyznacznik(a);

	double ab[2][2];

	ab[0][0] = b[0];
	ab[0][1] = a[0][1];
	ab[1][0] = b[1];
	ab[1][1] = ab[1][1];

	double wyznacznikX = wyznacznik(ab);

	ab[0][0] = a[0][0];
	ab[0][1] = b[0];
	ab[1][0] = a[1][0];
	ab[1][1] = b[1];

	double wyznacznikY = wyznacznik(ab);

	if(wyznacznikGlowny != 0)
	{
		xy[0] = wyznacznikX/wyznacznikGlowny;
		xy[1] = wyznacznikY/wyznacznikGlowny;
		return 1;
	}
	
	if(wyznacznikY == 0 && wyznacznikX == 0)
	{
		return 1000; //umowna kwestia nieskonczonej ilosci rozwiazan
	}

	return 0;
}
