#include <stdio.h>
#include <stdlib.h>

char menu();
int kwadrat();
int dwumian();
int dwanadwa();
int trzynatrzy();

int main(){
	char znak = menu();
	while (1)
	{
		switch(znak)
		{
			case '0':
				exit(0);
			case '1':
				printf("Wybrano Równanie Kwadratowe\n");
				kwadrat();
				znak = menu();
				break;
			case '2':
				printf("Wybrano Dwumian Newtona\n");
				dwumian();
				znak = menu();
				break;
			case '3':
				printf("Wybrano Układ 2x2\n");
				dwanadwa();
				znak = menu();
				break;
			case '4':
				printf("Wybrano Układ 3x3\n");
				trzynatrzy();
				znak = menu();
				break;
			default  :
				printf("Nie ma takiej opcji w menu\n");
				znak = menu();
		}
	}
}
