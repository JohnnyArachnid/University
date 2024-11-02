#include <stdio.h>

char menu(){
	printf("1. Równanie Kwadratowe\n");
	printf("2. Dwumian Newtona\n");
	printf("3. Układ 2x2\n");
	printf("4. Układ 3x3\n");
	printf("0. Zakończenie Programu\n");
	char znak;
	if(scanf("%s",&znak)!=1)
	{
		return -1;
	}
	return znak;
}

