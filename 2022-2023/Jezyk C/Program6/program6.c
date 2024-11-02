#include <stdio.h>
#include <math.h>

double wyznacznik(double tablica[2][2]);

int main()
{
	printf("Podaj współczynniki przy x i y i b do pierwszego równania: ");
	double x1,y1,b1;
	scanf("%lg %lg %lg",&x1,&y1,&b1);
	printf("Podaj współczynniki przy x i y i b do drugiego równiania: ");
	double x2,y2,b2;
	scanf("%lg %lg %lg",&x2,&y2,&b2);
	double tablica1[2][2] = {{x1,y1},{x2,y2}};
	double tablica2[2][2] = {{b1,y1},{b2,y2}};
	double tablica3[2][2] = {{x1,b1},{x2,b2}};
	double wyznacznikg = wyznacznik(tablica1);
	if (wyznacznikg != 0)
	{
		double wynik1 = (wyznacznik(tablica2)/wyznacznikg);
		double wynik2 = (wyznacznik(tablica3)/wyznacznikg);
		printf("Jedno Rozwiąznie dla x = %lg oraz y = %lg\n",wynik1,wynik2);
	}
	else if ((wyznacznikg == wyznacznik(tablica2)) && (wyznacznikg == wyznacznik(tablica3)))
	{
	printf("Układ Równań Nieoznacznony\n");
	}
	else
	{
	printf("Układ Sprzeczny\n");
	}
}
