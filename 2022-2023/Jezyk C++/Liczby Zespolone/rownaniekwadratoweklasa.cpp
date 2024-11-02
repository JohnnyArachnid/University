#include "complex.h"

using namespace std;

class Rkw{
private:
    complex a,b,c,x1,x2,s1,s2;
public:
    Rkw(complex a_, complex b_= 0, complex c_ = 0): a{a_}, b{b_}, c{c_} {}
        void solve();
        void print();
        void check();
};

void Rkw::solve()
{
    complex delta,deltap;
    delta = b*b - 4.0*(a*c);
    deltap = sqrt(delta);
    x1 = (-b+deltap)/(2.0*a);
    x2 = (-b-deltap)/(2.0*a);
}

void Rkw::print()
{
    cout<<"Rozwiazanie x1: "<<x1<<'\n'<<"Rozwiazanie x2: "<<x1<<'\n';
}

void Rkw::check()
{
    s1 = a*x1*x1+b*x1+c;
    s2 = a*x2*x2+b*x2+c;
    cout<<"Sprawdzenie 1: "<<s1<<'\n'<<"Sprawdzenie 2: "<<s2<<'\n';
}

int main()
{
    Rkw KYS({1,2},{3,4},{5,6});
    KYS.solve();
    KYS.check();
    KYS.print();
    return 0;
}