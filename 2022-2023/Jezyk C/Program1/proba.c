#include <stdio.h>
/* to jest 1 program w C */
int main(){
	double a,b;
	printf("Podaj liczby a,b: "); // wypisanie komunikatu
	int m = scanf("%lg %lg",&a,&b); /* pobranie od uzytkownika dwoch zmiennych, przy odwolywaniu sie do zmiennych
trzeba podac adres a nie zmienna dlatego &a, a nie samo a */
	double suma = a+b;
	int n = printf("%g %+g = %g\n",a,b,suma);
	printf("%d %d\n",n,m); //printuje liczbe znakow printa powyzej oraz liczbe zmiennych z scanf
	return 0;
}
