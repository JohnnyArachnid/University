#include <cmath>
#include <iostream>

class complex
{
	double re,im;
public:
	complex(double r, double i) :re{r}, im{i} {}
	complex(double r) :re{r}, im{0} {}
	complex(): re{0}, im{0} {}

	double real() const { return re; }
	void real(double d) { re=d; }
	double imag() const { return im; }
	void imag(double d) { im=d; }

	complex& operator+=(complex z) { re+=z.re, im+=z.im; return *this; }

	complex& operator-=(complex z) { re-=z.re, im-=z.im; return *this; }

	complex& operator*=(complex);
 
	complex& operator/=(complex);

}; 

complex& complex::operator*=(complex z)
{
	double a,b;
	a = (re*z.re)-(im*z.im);
	b = (re*z.im)+(im*z.re);
	re = a; im=b;
	return *this;
}
complex& complex::operator/=(complex z)
{
	double a,b;
	a = (re*z.re+im*z.im)/(z.re*z.re+z.im*z.im);
	b = (im*z.re-(re*z.im))/(z.re*z.re+z.im*z.im);
	re = a; im = b;
	return *this;
}

complex operator+(complex a, complex b){return a+=b;}
complex operator-(complex a, complex b){return a-=b;}
complex operator-(complex a) {return {-a.real(), -a.imag()};}
complex operator*(complex a, complex b){return a*=b;}
complex operator/(complex a, complex b){return a/=b;}

complex sqrt(complex z)
{
	double a,b,u,v;
	a = z.real();
	b = z.imag();
	u = sqrt((a+sqrt(pow(a,2)+pow(b,2)))/2);
	if(u==0) v = sqrt(-a);
	else v = b/(2*u);
	return complex{u,v};
}

std::ostream& operator<<(std::ostream& os, complex z)
{
	os<<'('<<z.real()<<','<<z.imag()<<')';
	return os;
}
std::istream& operator>>(std::istream& is, complex &z)
{
	double a,b;
	char znak[3];
	is>>znak[0]>>a>>znak[1]>>b>>znak[2];
	z.real(a); z.imag(b);
	if(znak[0] != '(' || znak[1] != ',' || znak[2] != ')') std::cerr<<"Blad wejscia\n";
	return is;
}

bool operator==(complex z, complex y)
{
	return z.imag()==y.imag() && z.real()==y.real();
}
bool operator!=(complex z, complex y)
{
	return !(z==y);
}
