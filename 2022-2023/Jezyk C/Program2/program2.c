#include <stdio.h>
#include <math.h>
int main(){
    double a,b,c;
    printf("Proszę podać kolejne wartości a,b,c do oblicznenia funkcji kwadratowej: ");
    if (scanf("%lg %lg %lg",&a,&b,&c) < 3){
        printf("Błąd\n");
        return -1;
    }
    double delta = b*b -4*a*c;
    if (delta > 0){
        double x1 = (-1*b - sqrt(delta))/2*a, x2 = (-1*b + sqrt(delta))/2*a;
        printf("Dwa pierwiastki: %lg oraz %lg",x1,x2);
    }
    else if (delta == 0){
        double x1 = -1*b/2*a;
        printf("Jeden pierwiastek: %lg\n",x1);
    }
    else{
        printf("Brak wyniku, delta mniejsza od 0\n"); 
    }
    return 0;
}
