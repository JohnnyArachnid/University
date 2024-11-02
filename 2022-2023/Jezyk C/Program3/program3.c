#include <stdio.h>
#include <math.h>
int rkw(double, double, double, double *, double *);
int main(){
    double a,b,c,r1,r2;
    printf("Podaj wartości a,b,c: ");
    if(scanf("%lg %lg %lg",&a,&b,&c)!=3){
        return -1;
    }
    else{
        int n = rkw(a,b,c,&r1,&r2);
        if (n==0) printf("Brak\n");
        else if (n == 1) printf("Jedno rozwiązanie: %g\n", r1);
        else printf("Dwa rozwiązania: %g, %g\n",r1,r2);
    }
    return 0;
}
