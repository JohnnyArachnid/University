#include "szablon.h"
//#include <complex>

int main()
{
    /*Rkw<::complex> rkw{{1,2},{3,4},{5,6}};
    Rkw<std::complex<long double>> rkw{{1,2},{3,4},{5,6}};*/
    complex a{}, b{}, c{};
    std::cin>>a>>b>>c;
    Rkw<complex> rkw(a,b,c);
    rkw.solve();
    rkw.print();
    rkw.check();
    return 0;
}
/* Dziala dla obu przypadkow*/