#include <stdio.h>

int uklad3(double[3][3], double[3], double[3]);
double wyznacznik3x3(double[3][3]);
void sprawdzenie3x3(double[3][3], double[3], double[3]);

int trzynatrzy()
{
	double a[3][3], b[3], c[3], out[3];
	printf("Podaj kolejno trzy rownania kolejnosc x,y,z oraz wynik: \n");
	if(scanf("%lg %lg %lg %lg",&a[0][0],&a[0][1],&a[0][2],&b[0])<4)
	{
		printf("Blad Wejscia!\n");
		return -1;
	}
	if(scanf("%lg %lg %lg %lg",&a[1][0],&a[1][1],&a[1][2],&b[1])<4)
	{
		printf("Blad Wejscia!\n");
		return -1;
	}
	if(scanf("%lg %lg %lg %lg",&a[2][0],&a[2][1],&a[2][2],&b[2])<4)
	{
		printf("Blad Wejscia!\n");
		return -1;
	}
	int liczbaRozwiazan = uklad3(a,b,c);
	printf("Liczba rozwiazan rownania wynosi: %d\n", liczbaRozwiazan);
	if (liczbaRozwiazan == 1)
	{
		printf("x wynosi: %lg\ny wynosi: %lg\nz wynosi: %lg\n",c[0],c[1],c[2]);
		sprawdzenie3x3(a,c,out);
		printf("Sprawdzenie:\n%lg=%lg\n%lg=%lg\n%lg=%lg\n", out[0],b[0],out[1],b[1],out[2],b[2]); 
	}
	return 0;
}
