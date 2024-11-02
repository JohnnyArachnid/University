#include <iostream>

using namespace std;

template <class T>

class Uklad{
private:
    T a[2][2], b[2], c[2];
    int n;
public:
    Uklad() = default;
    Uklad(T a_[2][2], T b_[2]);
    void solve();
    void const print();
    void const check();
};

template <class T>

Uklad<T>::Uklad(T a_[][2], T b_[])
{
    a[0][0] = a_[0][0];
    a[0][1] = a_[0][1];
    a[1][0] = a_[1][0];
    a[1][1] = a_[1][1];
    b[0] = b_[0];
    b[1] = b_[1];
}

template <class T>

void Uklad<T>::solve(){

    T wg = a[0][0]*a[1][1]-a[0][1]*a[1][0],w1=b[0]*a[1][1]-b[1]*a[0][1],w2=a[0][0]*b[1]-b[0]*a[1][0];
    if(wg!=T{})
    {
        c[0]=w1/wg;c[1]=w2/wg;n=1;
    }
    else if(w1==T{} && w2==T{}) n=10000;
    else n=0;
}

template <class T>

void const Uklad<T>::print(){

    if(n==1) cout<<"Jedno Rozwiazanie: "<<c[0]<<", "<<c[1]<<endl;
    else if(n==0) cout<<"Brak rozwiazan"<<endl;
    else cout<<"Nieskonczenie wiele rozwiazan"<<endl;
}

template <class T>

void const Uklad<T>::check(){

    T reszta1 = a[0][0]*c[0] + a[0][1]*c[1] - b[0];
    T reszta2 = a[1][0]*c[0] + a[1][1]*c[1] - b[1];
    cout<<"Reszta 1: "<<reszta1<<endl;
    cout<<"Reszta 2: "<<reszta2<<endl;
}

