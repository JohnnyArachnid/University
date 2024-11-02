#include <stdio.h>

void sprawdzenie(double a[3][3], double c[3], double out[3])
{
	out[0] = a[0][0]*c[0] + a[0][1]*c[1] + a[0][2]*c[2];
	out[1] = a[1][0]*c[0] + a[1][1]*c[1] + a[1][2]*c[2];
	out[2] = a[2][0]*c[0] + a[2][1]*c[1] + a[2][2]*c[2];
	return;
}
