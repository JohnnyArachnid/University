#include <stdio.h>

double wyznacznik(double[2][2]);
int uklad2(double[2][2], double[2], double[2]);
void sprawdzenie(double[2][2], double[2], double[2]);
int dwanadwa(){

	double a[2][2], b[2], xy[2], out[2];

	printf("Podaj dwa uklady rownan x,y oraz wynik:\n");
	if(scanf("%lg %lg %lg",&a[0][0], &a[0][1], &b[0])<3)
	{
		printf("Błąd Wejścia!\n");
		return -1;
	}
	if(scanf("%lg %lg %lg",&a[1][0], &a[1][1], &b[1])<3)
	{
		printf("Błąd Wejścia!\n");
		return -1;
	}
	int n = uklad2(a,b,xy);
	printf("Ilość rozwiązań wynosi: %d\n",n);
	if(n==1)
	{
		printf("Wartość x: %lg\nWartość y: %lg\n",xy[0],xy[1]);
		sprawdzenie(a,xy,out);
		printf("Sprawdzenie:\n%lg=%lg\n%lg=%lg\n",out[0],b[0],out[1],b[1]);
	}
	return 0;
}
