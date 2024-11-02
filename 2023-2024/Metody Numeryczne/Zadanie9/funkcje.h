// Autor: Daniel Szarek
//=====================

#include <iostream>
#include <limits>
#include <cmath>
#include <fstream>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>

// Rozmiar wektorow GSL wybrany przeze mnie z przedzialu [100,1000] podanego w poleceniu

const int N = 100;

// Deklaracja zmiennych podanych w poleceniu do wypelnienia macierzy A

const double L = 10;
const double h = 2 * L / (N - 1);

// Dokladnosc obliczen podanych w poleceniu

const double epsilon = 1.0e-8;

// Pozadana ilosc wektorow oraz najmniejszych wartosci wlasnych macierzy A GSL

const int iloscWartosciIWektorowWlasnych = 4;

// Funkcja wypelniajaca wektor diagonalny macierzy A GSL

void wypelnienieWektoraDiagonalnego(gsl_vector *diag);

// Funkcja obliczajaca iloczyn skalarny macierzy A i wektora GSL

void iloczynSkalarnyWektoraIMacierzy(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, const gsl_vector *wektor, gsl_vector *wynik);

// Funkcja sprawdzajaca dokladnosc obliczen

bool sprawdzenieDokladnosciObliczen(double poprzedniaWartosc, double wartosc);

// Metoda Rayleigha w celu zapewnienie szybszej zbieznosci

void metodaRayleigha(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, gsl_vector *poprzednieV, double & wartoscWlasnaMacierzyA);

// Funkcja wypelniajaca wektor supdiagonalny oraz subdiagonalny macierzy A GSL

void wypenienieWektoraTrojdiagonalnego(gsl_vector *wektor);

// Funkcja znajdujaca najmniejsze wartosci wlasne oraz odpowiadajace im wektory wlasne macierzy A GSL, dzieki wykorzystaniu deflacji wektorowej liczymy pozadana ich ilosc podana w poleceniu

void odwroconaMetodaPotegowa(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, gsl_vector * wartosciWlasneMacierzyA, gsl_vector *tablicaWektorowWlasnychMacierzyA[]);