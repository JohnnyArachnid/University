#include "szablonukladrownan.h"
#include "complex.h"
#include "rational.h"

using namespace std;

int main()
{
    /*double a[2][2] = {{1,2},{3,4}}, b[2] = {5,6};

    Uklad<double> Uklad{a,b};

    Uklad.solve();
    Uklad.print();
    Uklad.check();
    return 0;
    Wersja programu dla double
   complex a[2][2] = {{{1,2},{3,4}},{{5,6},{7,8}}}, b[2] = {{9,10},{11,12}};

   Uklad<complex> Uklad{a,b};

   Uklad.solve();
   Uklad.print();
   Uklad.check();
   */
   
   Rational a[2][2] = {{{1,2},{3,4}},{{5,6},{7,8}}};
   Rational b[2] = {{1,2},{3,4}};

   Uklad<Rational> Uklad{a,b};

   Uklad.solve();
   Uklad.print();
   Uklad.check();

   return 0;
}