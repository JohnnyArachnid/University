#include <stdio.h>
#include <stdlib.h>

// det(a*b) = det(a) * det (b)

double Determinant(int n, double a[][n]);

void iloczyn(int n, double a[][n], double b[][n], double c[][n]);

int main()
{
	int n;
	printf("Proszę podaj wartość n, długość macierzy n na n: \n");
	scanf("%d",&n);
	int nr;
	printf("Proszę podaj wartość nr, numer serii losowej: \n");
	scanf("%d",&nr);

	double a[n][n],b[n][n],c[n][n],d[n];

	srand(nr);

	for(int i=0;i<n;i++)
	{
		d[i] = (double)rand()/RAND_MAX;
		for(int j=0;j<n;j++)
		{
			a[i][j] = (double)rand()/RAND_MAX;
			b[i][j] = (double)rand()/RAND_MAX;
		}
	}

	iloczyn(n,a,b,c);

	double detA = Determinant(n,a);
	double detB = Determinant(n,b);
	double detC = Determinant(n,c);

	double wg = Determinant(n,a);
	double jd[n][n],e[n],f[n];
	int k = n-1;
	int licznik = 0;
	while(k>=0)
	{
		for(int g=0; g<n;g++)
		{
			for(int f=0;f<n;f++)
			{
				jd[g][f] = a[g][f];
			}
		}
		for(int h=0;h<n;h++)
		{
			jd[h][licznik] = d[h];
		}
		f[licznik] = Determinant(n,jd);
		licznik++;
		k--;
	} 
	for(int y=0;y<n;y++)
	{
		printf("%lg\n",f[licznik]/wg);
	}

	printf("det(a*b) : %lg, det(a) * det(b) : %lg, det(a*c) - det(a) * det(b) : %lg\n", detC, detA * detB, detC - detA * detB);
	return 0;
}
