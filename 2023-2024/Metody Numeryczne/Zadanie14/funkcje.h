// Autor: Daniel Szarek
//=====================

#include <iostream>
#include <cmath>
#include <fstream>
#include <gsl/gsl_blas.h>

// Dokladnosc obliczen podana w poleceniu

const double epsilon = 10e-6;

// Zmodyfikowane granice calkowania

const double poczatekGranicyCalkowania = 0;
const double koniecGranicyCalkowania = M_PI;

// Funkcja zwracajaca wynik funkcji podcalkowej dla danej wartosci x

double wynikFunkcjiPodCalkowej(double x);

// Funkcja sprawdzajaca dokladnosc obliczen

bool sprawdzenieDokladnosciObliczen(double wynik, double poprzedniWynik);

// Funkcja realizujaca metode Trapezow numerycznego obliczania wartosci calek 

double metodaTrapezow(int * liczbaIteracji);

// Funkcja realizujaca metode Simpsona numerycznego obliczania wartosci calek

double metodaSimpsona(int * liczbaIteracji);

// Funkcja realizujaca regule 3/8 numerycznego obliczania wartosci calek

double regula38(int * liczbaIteracji);

