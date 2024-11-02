#include <math.h>
#include <stdio.h>

double lewa(double x, int n)
{
	double suma = 0.5;
	for(int k=1;k<=n;k++)
	{
		suma += cos(k*x);
	}
	return suma;
} 
double prawa(double x, int n)
{
	return (sin(((double)n+0.5)*x))/(2*sin(x/2));
}
int main()
{
	printf("Podaj wartość x oraz n do obliczeń: ");
	double x;
	int n;
	if(scanf("%lg %d",&x,&n)!=2) return -1;
	printf("Rozwiązanie Funkcji Lewej to: %lg\n", lewa(x,n));
	printf("Rozwiązanie Funkcji Prawej to: %lg\n", prawa(x,n));
	return 0;
}
