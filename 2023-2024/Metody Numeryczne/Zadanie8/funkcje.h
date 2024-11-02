// Autor: Daniel Szarek
//=====================

#include <iostream>
#include <limits>
#include <cmath>
#include <fstream>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>

// Rozmiar wektorow oraz macierzy GSL

const int N = 3;

// Dokladnosc obliczen podanych w poleceniu

const double epsilon = 1.0e-8;

// Funkcja obliczajaca iloczyn skalarny macierzy A i wektora GSL

void iloczynSkalarnyWektoraIMacierzy(const gsl_matrix * A, const gsl_vector * wektor, gsl_vector * wynik);

// Funkcja sprawdzajaca dokladnosc obliczen porownujac ja z naszym kryterium podanym w poleceniu

bool sprawdzenieDokladnosciObliczen(double poprzedniaWartosc, double wartosc);

// Metoda Potegowa w celu obliczenia wartosci wlasnych macierzy A GSL

void metodaPotegowa(const gsl_matrix * A, gsl_vector *wartosciWlasneMacierzyA);

// Metoda Rayleigha w celu obliczenia wartosci wlasnych macierzy A GSL

void metodaRayleigha(const gsl_matrix * A, gsl_vector *wartosciWlasneMacierzyA);

// Metoda Iteracyjna QR w celu obliczenia wartosci wlasnych macierzy A GSL

void metodaIteracyjnaQR(const gsl_matrix * A, gsl_vector *wartosciWlasneMacierzyA);

// Funkcja wypelniajaca macierz A

void wypelnienieMacierzyA(gsl_matrix * A);



