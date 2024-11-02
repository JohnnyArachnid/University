#include <stdio.h>
#include <math.h>
double fL(double, double, int);
double fR(double, double, int);
int dwumian(){
	double a,b;
	int n;
	printf("Podaj a, b, n do obliczeń: ");
	if(scanf("%lg %lg %d", &a,&b,&n) != 3){
		printf("Błąd wczytywania\n");
		return -1;
	}
	double wynikL = fL(a,b,n);
	double wynikP = fR(a,b,n);
	printf("Wynik funkcji lewej: %lg\n", wynikL);
	printf("Wynik funkcji prawej: %lg\n", wynikP);
	double pomiar = wynikL-wynikP;
	if (pomiar != 0){
		double pomiar1 = (pomiar<0) ? pomiar*-1 : pomiar;
		printf("Błąd pomiarowy wynosi: %lg\n", pomiar1);
	}
	return 0;
}
