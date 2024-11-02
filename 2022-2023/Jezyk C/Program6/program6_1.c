#include <stdio.h>

void sprawdzenie(double tab1[2][2], double tab2[2]);

int main()
{
	printf("Podaj układ w postaci:\n a11x+a12y=b1\n a21+a22=b2\n\n");
	double a[2][2], b[2];
	if((scanf("%lg %lg %lg", &a[0][0],&a[0][1],&b[0]))<3)
	{
		printf("input error\n");
		return -1;
	}
	if((scanf("%lg %lg %lg", &a[1][0], &a[1][1], &b[1]))<3)
	{
		printf("input error\n");
		return -1;
	}
	sprawdzenie(a,b); 
}
