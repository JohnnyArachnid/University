#include <iostream>
#include <complex>

using namespace std;

int main()
{
	complex<double> a{3.5,4.6};
	complex<double> b{4.0,7.3};
	complex<double> c{8.4,2.1};
	complex<float> d,e,f;
	cin>>d>>e>>f;
	// Podajemy liczby do wczytania tak jak wypisuje czyli np. (8.8,9.1) (8.1,5.5) (3.3,2.1)
	cout<<a<<b<<c<<endl;
	cout<<d<<e<<f<<endl;
	// dziala dla zamiany tyu danych z double na float
	return 0;
}
