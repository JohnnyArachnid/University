// Autor: Daniel Szarek
//=====================

#include <iostream>
#include <fstream>
#include <chrono>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_blas.h>

const int N = 1e3; // Stala zmienna N podana w poleceniu N3

const double h = 1e-2; // Stala zmienna h podana w poleceniu N3

const double epsilon = 10e-10; // Dokladnosc obliczen podana w poleceniu

const double tau = 0.499; // Stala relaksacji wykorzystywana w metodzie Relaksacyjnej Richardsona
    
const double omega = 1.993; // Stala relaksacji wykorzystywana w Successive OverRelayation

const double lewyDolnyRogMacierzyA = -1; // Element macierzy A znajdujacy sie w lewym dolnym rogu opisany przez rownanie dla wiersza N

/* W odroznieniu od mojego zadania N3, tutaj dokonalem pewnych zmian w konstrukcji macierzy A, np. zamiast wartosci diagonalnych (-2 * h2) + 1) , tutaj mamy (h*h + 2).
Zmiana wynika z faktu, ze owczesna implementacja macierzy bardzo dlugo wykonywala dzialania, stad przemnozylem wiersze przez h*h i program dziala szybciej nie wykonujac obliczen na problematycznych liczbach.
Operacja ta przyspiesza dzialania programu oraz nie wplywa na wynik, pomocne jest to ze macierz b w wiekszosci jest wypelniona 0, stad jej iloczym przez h*h nie zmienia wyniku, nadal to bedzie 0. */

// Funkcja sprawdzajaca dokladnosc obliczen w ponizszych metodach

bool sprawdzenieDokladnosciObliczen(gsl_vector * sprawdzenieDokladnosci, gsl_vector * poprzedniY, gsl_vector * y);

// Metoda Relaksacyjna Richardsona w celu rozwiazania wartosci zmiennych wektora y iteracyjnie

void metodaRelaksacyjnaRichardsona(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji);

// Metoda Jacobiego w celu rozwiazania wartosci zmiennych wektora y iteracyjnie

void metodaJacobiego(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji);

// Metoda Gausa-Seidla w celu rozwiazania wartosci zmiennych wektora y iteracyjnie

void metodaGausaSeidla(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji);

// Successive OverRelayation w celu rozwiazania wartosci zmiennych wektora y iteracyjnie

void successiveOverRelayation(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji);

// Wpisanie danych do wektorów GSL

void wypenienieWektoraB(gsl_vector *b);
void wypelnienieWektoraDiagonalnegoDiag(gsl_vector *diag);
void wypenienieWektoraTrojdiagonalnegoGornegoE(gsl_vector *e);
void wypenienieWektoraTrojdiagonalnegoDolnegoF(gsl_vector *f);
