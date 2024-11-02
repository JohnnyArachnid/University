#include <math.h>

double fL(double a, double b, int n){
	double wynik = pow(a+b, n);
	return wynik;
}
double silnia(unsigned n){
	if (n<2){
		return 1.0;
	}
	return n*silnia(n-1);
}

double sn(unsigned n, unsigned k){
	if  (k == 0 || n == k) return 1.0;
	return silnia(n) / (silnia(k)*silnia(n-k));
}
double fR(double a, double b, int n){
	int k = 0;
	double wynik = 0;
	while (n >= k){
		//double sn = (silnia(n)/(silnia(k)*silnia(n-k));
		//wynik += pow(a,n-k)*pow(b,k)*sn;
		wynik += pow(a,n-k)*pow(b,k)*sn(n,k);
		k++;
	}
	return wynik;
}

