// Autor: Daniel Szarek
//=====================

#include <iostream>
#include <fstream>
#include <gsl/gsl_blas.h>

// Rozmiar wektorow oraz macierzy GSL

const int N = 3;

// Dokladnosc obliczen z poprzedniego zadania

const double epsilon = 10e-10;

// Funkcja wypelniajaca wektor rezyduum

void wypelnienieWektoraR(gsl_vector * r_k, const gsl_matrix * A, const gsl_vector * b, const gsl_vector * x);

// Funkcja obliczajaca kolejna iteracje dla wektorow x i r_k oraz p_k

void kolejnaIteracja(gsl_vector * a, const gsl_vector * b, const double wartoscScalarna);

// Funkcja obliczajaca iloczyn skalarny macierzy A i wektora p_k

void iloczynSkalarnyWektoraIMacierzy(const gsl_matrix * A, const gsl_vector * p_k, gsl_vector * Ap_k);

// Funkcja sprawdzajaca dokladnosc obliczen w metodzie gradientow sprzezonych

bool sprawdzenieDokladnosciObliczen(gsl_vector * r_k);

// Funkcja realizaujaca metode gradientow sprzezonych

void metodaGradientowSprzezonych(const gsl_matrix * A, const gsl_vector * b, gsl_vector * x);

// Funkcja wypelniajaca macierz A

void wypelnienieMacierzyA(gsl_matrix *A);

// Funkcja wypelniajaca wektor z wynikami rownan liniowych

void wypenienieWektoraB(gsl_vector *b);


