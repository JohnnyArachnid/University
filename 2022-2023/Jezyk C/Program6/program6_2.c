#include <stdio.h>

void sprawdzenie(double tab1[2][2],double tab2[2])
{
	double pomocnicza[2];
	pomocnicza[0] = tab1[0][0] * tab2[0] + tab1[0][1] * tab2[1];
	pomocnicza[1] = tab1[1][0] * tab2[0] + tab1[1][1] * tab2[1];
	double n = tab1[0][0] * tab1[1][1] - (tab1[0][1] * tab1[1][0]);
	if(n==1)
	{
		printf("Rozwiązania x = %lg oraz y = %lg\n",tab2[0] * tab1[1][1] - (tab1[0][1] * tab2[1]),tab1[0][0] * tab1[1][1] - (tab2[0] * tab2[1]));

	}
	else
	{
		printf("Układ nieoznaczony lub błędny\n");
	}
}
