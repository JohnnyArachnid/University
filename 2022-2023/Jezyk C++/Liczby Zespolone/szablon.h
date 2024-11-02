#include "complex.h"

using namespace std;

template <class T>

class Rkw{
private:
    T a,b,c,x1,x2,s1,s2;
public:
    Rkw(T a_, T b_= T{}, T c_ = T{}): a{a_}, b{b_}, c{c_} {}
        void solve();
        void print() const;
        void check() const;
};

template <class T>

void Rkw<T>::solve()
{
    T delta,deltap;
    delta = b*b - T{4}*(a*c);
    deltap = sqrt(delta);
    x1 = (-b+deltap)/(T{2}*a);
    x2 = (-b-deltap)/(T{2}*a);
}

template <class T>

void Rkw<T>::print() const{
    cout<<"Rozwiazanie x1: "<<x1<<'\n'<<"Rozwiazanie x2: "<<x1<<'\n';
}

template <class T>

void Rkw<T>::check() const{
    cout<<"Sprawdzenie 1: "<<a*x1*x1+b*x1+c<<'\n'<<"Sprawdzenie 2: "<<a*x2*x2+b*x2+c<<'\n';
}