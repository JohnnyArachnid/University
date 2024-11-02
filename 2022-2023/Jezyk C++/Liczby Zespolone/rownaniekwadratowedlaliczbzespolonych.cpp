#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main()
{
	complex<float> a,b,c,delta,deltap,x1,x2,s1,s2;
	cout<<"Podaj liczby zespolone jako (a,b), aby obliczyc pierwiastki kwadratowe z rowniania kwadratowego: ";
	cin>>a>>b>>c;
	delta = b*b - 4.0f*a*c;
	deltap = sqrt(delta);
	x1 = (-1.0f*b - deltap)/(2.0f*a);
	x2 = (-1.0f*b + deltap)/(2.0f*a);
	cout<<"Delta tego rownania wynosi: "<<delta<<endl;
	cout<<"Pierwiastki rownania kwadratowego to: "<<x1<<", "<<x2<<endl;
	s1 = a*x1*x1 + b*x1 + c;
	s2 = a*x2*x2 + b*x2 + c;
	cout<<"Sprawdzenie dla x1: "<<s1<<endl;
	cout<<"Sprawdzenie dla x2: "<<s2<<endl;
	return 0; 
}