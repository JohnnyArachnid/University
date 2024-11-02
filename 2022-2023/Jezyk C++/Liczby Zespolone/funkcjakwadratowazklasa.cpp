#include "complex.h"

using namespace std;

int main()
{
	complex a{1,2},b{3,4},c{5,6},delta{},x1{},x2{};
	delta = b*b - 4.0*a*c;
	x1 = (-b+sqrt(delta))/(2.0*a);
	x2 = (-b-sqrt(delta))/(2.0*a);
	cout<<x1<<x2<<'\n';
	cout<<"Sprawdzenie dla x1: "<<x1*x1*a+x1*b+c<<endl;
	cout<<"Sprawdzenie dla x2: "<<x2*x2*a+x2*b+c<<endl;
	return 0;
}
