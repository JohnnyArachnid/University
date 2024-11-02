// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

void iloczynSkalarnyWektoraIMacierzy(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, const gsl_vector *wektor, gsl_vector *wynik) {
    gsl_vector_set(wynik, 0, (gsl_vector_get(diag, 0) * gsl_vector_get(wektor, 0) + gsl_vector_get(e, 0) * gsl_vector_get(wektor, 1)));
    for (int i = 1; i < N - 1; i++) { gsl_vector_set(wynik, i, gsl_vector_get(f, i - 1) * gsl_vector_get(wektor, i - 1) + gsl_vector_get(diag, i) * gsl_vector_get(wektor, i) + gsl_vector_get(e, i) * gsl_vector_get(wektor, i + 1)); }
    gsl_vector_set(wynik, N - 1, (gsl_vector_get(f, N - 2) * gsl_vector_get(wektor, N - 2) + gsl_vector_get(diag, N - 1) * gsl_vector_get(wektor, N - 1)));
}

bool sprawdzenieDokladnosciObliczen(double poprzedniaWartosc, double wartosc) {
    if (fabs(poprzedniaWartosc - wartosc) < epsilon)
    {
        return false;
    }
    return true;
}

void metodaRayleigha(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, gsl_vector *poprzednieV, double & wartoscWlasnaMacierzyA) {

    // Deklaracja wektorow do obliczenia wartosci wlasnych macierzy A GSL

    gsl_vector * v_k = gsl_vector_alloc(N);
    gsl_vector * w_k = gsl_vector_alloc(N);
    gsl_vector *wektorTymczasowyDoObliczen = gsl_vector_calloc(N);

    // Deklaracja zmiennych typu double do obliczenia wartosci wlasnych macierzy A GSL

    double poprzedniaWartoscWlasnaMacierzyA;
    double normaW;

    while (true)
    {

        // Przypisanie wartosci zmiennej poprzednej wartosci wlasnej macierzy A

        poprzedniaWartoscWlasnaMacierzyA = wartoscWlasnaMacierzyA;

        // Modyfikacja wektora diagonalnego macierzy A

        for (int k = 0; k < N; k++) { gsl_vector_set(wektorTymczasowyDoObliczen, k, (gsl_vector_get(diag, k) - wartoscWlasnaMacierzyA)); }

        // Obliczenie wektora w_k

        gsl_linalg_solve_tridiag(wektorTymczasowyDoObliczen, e, f, poprzednieV, w_k);

        // Obliczenie normy wektora w_k do obliczenia wartosci wlasnej macierzy A

        normaW = gsl_blas_dnrm2(w_k);

        // Obliczenie wektora poprzedniej iteracji v_k

        for (int k = 0; k < N; k++) { gsl_vector_set(poprzednieV, k, gsl_vector_get(w_k, k) / normaW); }

        // Wyzerowanie wektora tymczasowego do obliczen

        gsl_vector_set_all(wektorTymczasowyDoObliczen, 0);

        // Obliczenie iloczynu skalarnego macierzy A oraz poprzedniej iteracji v_k

        iloczynSkalarnyWektoraIMacierzy(diag, e, f, poprzednieV, wektorTymczasowyDoObliczen);

        // Zapisanie wektora wlasnego macierzy A GSL

        gsl_blas_ddot(poprzednieV, wektorTymczasowyDoObliczen, &wartoscWlasnaMacierzyA);

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(poprzedniaWartoscWlasnaMacierzyA, wartoscWlasnaMacierzyA)) {
            break;
        }
    }

    // Zwolnienie pamięci wektorow GSL

    gsl_vector_free(v_k);
    gsl_vector_free(w_k);
    gsl_vector_free(wektorTymczasowyDoObliczen);

}

void odwroconaMetodaPotegowa(const gsl_vector *diag, const gsl_vector *e, const gsl_vector *f, gsl_vector * wartosciWlasneMacierzyA, gsl_vector *tablicaWektorowWlasnychMacierzyA[]) {

    // Deklaracja wektorow do obliczenia najmniejszych wartosci wlasnych macierzy A GSL oraz odpowiadajacym im wektorom wlasnym GSL

    gsl_vector * v_k = gsl_vector_alloc(N);
    gsl_vector * w_k = gsl_vector_alloc(N);
    gsl_vector * poprzednieV = gsl_vector_alloc(N);
    gsl_vector * wektorTymczasowyDoObliczen = gsl_vector_alloc(N);

    // Deklaracja zmiennych typu double do obliczenia najmniejszych wartosci wlasnych macierzy A GSL oraz odpowiadajacym im wektorom wlasnym GSL

    double wartoscWlasnaMacierzyA;
    double poprzedniaWartoscWlasnaMacierzyA;
    double iloczynSkalarny;
    double normaW;

    for (int i = 0; i < iloscWartosciIWektorowWlasnych; i++)
    {

        // Dobranie wektora v0 poczatkowego, metoda jest wrażliwa na dobór wektora początkowego, stad dopieram optymalną wartosc

        if (i == 0) {
            gsl_vector_memcpy(poprzednieV, diag);
        } else {
            gsl_vector_set_all(poprzednieV, 0);
            gsl_vector_set(poprzednieV, 0, 1);
        }

        // Wyzerowanie zmiennej wartosci wlasnej macierzy A wraz z kolejna iteracja

        wartoscWlasnaMacierzyA = 0;

        while (true)
        {

            // Przypisanie wartosci zmiennej poprzednej wartosci wlasnej macierzy A GSL

            poprzedniaWartoscWlasnaMacierzyA = wartoscWlasnaMacierzyA;

            // Obliczenie wektora w_k

            gsl_linalg_solve_tridiag(diag, e, f, poprzednieV, w_k);

            // Obliczenie normy wektora w_k do obliczenia najmniejszych wartosci wlasnych macierzy A GSL oraz odpowiadajacym im wektorom wlasnym GSL

            normaW = gsl_blas_dnrm2(w_k);

            // Obliczenie wektora v_k

            for (int k = 0; k < N; k++)
            {
                gsl_vector_set(v_k, k, gsl_vector_get(w_k, k) / normaW);
            }

            // Obliczenie wartosci wlasnej macierzy A GSL odwrocona metoda potegowa

            gsl_blas_ddot(poprzednieV, w_k, &iloczynSkalarny);
            wartoscWlasnaMacierzyA = 1 / iloczynSkalarny;

            // Wyzerowanie wektora tymczasowego do obliczen

            gsl_vector_set_all(wektorTymczasowyDoObliczen, 0);

            // Deflacja w celu obliczenia kolejnych najmniejszych wartosci wlasnych macierzy A GSL oraz odpowiadajacym im wektorom wlasnym GSL

            for (int j = 0; j < i + 1; j++) {
                gsl_blas_ddot(tablicaWektorowWlasnychMacierzyA[j], v_k, &iloczynSkalarny);
                for (int k = 0; k < N; k++) {
                    gsl_vector_set(wektorTymczasowyDoObliczen, k, gsl_vector_get(wektorTymczasowyDoObliczen, k) + gsl_vector_get(tablicaWektorowWlasnychMacierzyA[j], k) * iloczynSkalarny);
                }
            }

            // Zapisanie wartosci v_k dla kolejnych iteracji metody

            gsl_vector_sub(v_k, wektorTymczasowyDoObliczen);
            gsl_vector_memcpy(poprzednieV, v_k);

            // Sprawdzenie dokladnosci obliczen

            if (!sprawdzenieDokladnosciObliczen(poprzedniaWartoscWlasnaMacierzyA, wartoscWlasnaMacierzyA)) {
                break;
            }
        }

        // Uzyskanie szybszej zbieznosci

        metodaRayleigha(diag, e, f, poprzednieV, wartoscWlasnaMacierzyA);

        // Zapisanie wektora wlasnego macierzy A GSL

        gsl_vector_set(wartosciWlasneMacierzyA,i,wartoscWlasnaMacierzyA);
        gsl_vector_memcpy(tablicaWektorowWlasnychMacierzyA[i], poprzednieV);
    }

    // Zwolnienie pamięci wektorow GSL

    gsl_vector_free(v_k);
    gsl_vector_free(w_k);
    gsl_vector_free(poprzednieV);
    gsl_vector_free(wektorTymczasowyDoObliczen);
}

void wypelnienieWektoraDiagonalnego(gsl_vector *diag) {
    double x = 0;
    for (int i = 0; i < N; i++) {
        x = -L + i * h;
        gsl_vector_set(diag, i, ((2 / (h * h)) + 4 - (6 / (cosh(x) * cosh(x)))));
    }
}

void wypenienieWektoraTrojdiagonalnego(gsl_vector *wektor) { 
    gsl_vector_set_all(wektor, -1 / (h * h));
}