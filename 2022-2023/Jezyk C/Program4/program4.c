#include <stdio.h>
#include <math.h>
int rkw(double a,double b,double c,double *r1, double *r2){
    double delta = b*b - 4 * a * c;
    if (delta < 0) return 0;
    else if (delta == 0) {
        *r1 = -b / 2 * a;
        return 1;
    } else {
        *r1 = (-b - sqrt(delta))/ 2 * a;
        *r2 = (-b + sqrt(delta))/ 2 * a;
        return 2;
    }
} 
