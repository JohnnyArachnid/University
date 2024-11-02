#include <stdio.h>
#include <stdlib.h>

double Determinant(int n, double a[n][n]);

void replaceTab(int n,int in,double a[n][n], double b[n])
{
	for(int i=0;i<n;i++)
	{
		a[i][in] = b[i];
	}
}

void copyTab(int n, double a[n][n], double b[n][n])
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

int main()
{
	int n,nr,i,j;
	printf("Podaj n, nr serii losowej: \n");
	scanf("%d %d",&n,&nr);

	srand(nr);

	double macierz[n][n], wyniki[n];

	for(i=0;i<n;i++)
	{
		wyniki[i] = (double)rand()/RAND_MAX;
		// printf("%lg xd\n",wyniki[i]);
		for(j=0;j<n;j++)
		{
			macierz[i][j] = (double)rand()/RAND_MAX;
			// printf("%lg\n",macierz[i][j]);
		}
	}

	double wyz[n], cpMacierz[n][n], wsp[n], kolumnaTemp[n];

	for(i=0;i<n;i++)
	{
		copyTab(n,macierz,cpMacierz);
		for(j=0;j<n;j++)
		{
			kolumnaTemp[j] = cpMacierz[j][i];
			//printf("%lg \n", kolumnaTemp[j]);
		}

	replaceTab(n,i,cpMacierz,wyniki);
	wyz[i] = Determinant(n, cpMacierz);

	}

	double wyzG = Determinant(n, macierz);

	printf("Wyznacznik Glowny: %lg\n",wyzG);

	for(i=0;i<n;i++)
	{
		wsp[i] = wyz[i]/wyzG;
		printf("nr.%d x = %lg\n", i, wsp[i]);
	}

	double check;

	printf("Sprawdzenie dzialania Macierzy: \n");

	for(i=0;i<n;i++)
	{
		check = 0.0;
		for(j=0; j<n;j++)
		{
			check+=macierz[i][j]*wsp[j];
		}
	printf("L: %lg, P: %lg, D: %lg\n",check, wyniki[i], check-wyniki[i]);
	}
}
