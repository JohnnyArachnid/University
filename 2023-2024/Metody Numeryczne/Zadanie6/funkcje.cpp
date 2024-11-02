// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

bool sprawdzenieDokladnosciObliczen(gsl_vector * sprawdzenieDokladnosci, gsl_vector * poprzedniY, gsl_vector * y) {

    // Skopiowanie zawartosci obecnego y do wektora tymczasowego sprawdzenieDokladnosci GSL

    gsl_vector_memcpy(sprawdzenieDokladnosci, y);

    // Sprawdzenie dokladnosci poprzez porownanie normy roznicy obecnego i poprzedniYego y z wartosciom epsilon

    gsl_vector_sub(sprawdzenieDokladnosci, poprzedniY);
    if (gsl_blas_dnrm2(sprawdzenieDokladnosci) < epsilon)
    {
        return false;
    }
    return true;
}

void metodaRelaksacyjnaRichardsona(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji) {

    // Tworzenie wektorow tymczasowych GSL

    gsl_vector * poprzedniY = gsl_vector_calloc(N+1);
    gsl_vector * sprawdzenieDokladnosci = gsl_vector_alloc(N+1);

    double sum;

    // Przypisanie wartosci wektora y[0] z wektora b[0] na podstawie naszego ukladu rownan i wiersza pierwszego dla i = 0

    gsl_vector_set(y, 0, gsl_vector_get(b, 0));

    while (true)
    {

        // Zwiekszenie ilosci iteracji metody

        *iloscIteracji += 1;

        // Skopiowanie wartosci wektora y do wektora tymczasowego GSL

        gsl_vector_memcpy(poprzedniY, y);

        // Obliczanie wartosci dla wektora y do indeksu N-1

        for (int i = 1; i < N; i++)
        {
            sum = gsl_vector_get(e, i) * gsl_vector_get(poprzedniY, i+1);
            sum += gsl_vector_get(diag, i) * gsl_vector_get(poprzedniY, i);
            sum += gsl_vector_get(f, i-1) * gsl_vector_get(poprzedniY, i-1);
            gsl_vector_set(y, i, gsl_vector_get(poprzedniY, i) + tau * (gsl_vector_get(b, i) - sum));
        }

        // Obliczanie wartosci dla wektora y[N]

        sum = lewyDolnyRogMacierzyA * gsl_vector_get(poprzedniY, 0);
        sum += gsl_vector_get(diag, N) * gsl_vector_get(poprzedniY, N);
        sum += gsl_vector_get(f, N-1) * gsl_vector_get(poprzedniY, N-1);
        gsl_vector_set(y, N, gsl_vector_get(poprzedniY, N) + tau * (gsl_vector_get(b, N) - sum));

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(sprawdzenieDokladnosci, poprzedniY, y)) {
            break;
        }
    }

    // Zwolnienie pamięci wektorow tymczasowych GSL

    gsl_vector_free(poprzedniY);
    gsl_vector_free(sprawdzenieDokladnosci);
}

void metodaJacobiego(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji) {

    // Tworzenie wektorow tymczasowych GSL

    gsl_vector * poprzedniY = gsl_vector_calloc(N+1);
    gsl_vector * sprawdzenieDokladnosci = gsl_vector_alloc(N+1);

    double sum;

    // Przypisanie wartosci wektora y[0] z wektora b[0] na podstawie naszego ukladu rownan i wiersza pierwszego dla i = 0

    gsl_vector_set(y, 0, gsl_vector_get(b, 0));

    while (true)
    {

        // Zwiekszenie ilosci iteracji metody

        *iloscIteracji += 1;

        // Skopiowanie wartosci wektora y do wektora tymczasowego GSL

        gsl_vector_memcpy(poprzedniY, y);

        // Obliczanie wartosci dla wektora y do indeksu N-1

        for (int i = 1; i < N; i++)
        {
            sum = gsl_vector_get(e, i) * gsl_vector_get(poprzedniY, i+1);
            sum += gsl_vector_get(f, i-1) * gsl_vector_get(poprzedniY, i-1);
            gsl_vector_set(y, i, ((gsl_vector_get(b, i) - sum)/(gsl_vector_get(diag, i))));
        }

        // Obliczanie wartosci dla wektora y[N]

        sum = lewyDolnyRogMacierzyA * gsl_vector_get(poprzedniY, 0);
        sum += gsl_vector_get(f, N-1) * gsl_vector_get(poprzedniY, N-1);
        gsl_vector_set(y, N, ((gsl_vector_get(b, N) - sum)/(gsl_vector_get(diag, N))));

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(sprawdzenieDokladnosci, poprzedniY, y)) {
            break;
        }
    }

    // Zwolnienie pamięci wektorow tymczasowych GSL

    gsl_vector_free(poprzedniY);
    gsl_vector_free(sprawdzenieDokladnosci);
}

void metodaGausaSeidla(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji) {

    // Tworzenie wektorow tymczasowych GSL

    gsl_vector * poprzedniY = gsl_vector_calloc(N+1);
    gsl_vector * sprawdzenieDokladnosci = gsl_vector_alloc(N+1);

    double sum;

    // Przypisanie wartosci wektora y[0] z wektora b[0] na podstawie naszego ukladu rownan i wiersza pierwszego dla i = 0

    gsl_vector_set(y, 0, gsl_vector_get(b, 0));

    while (true)
    {

        // Zwiekszenie ilosci iteracji metody

        *iloscIteracji += 1;

        // Skopiowanie wartosci pierwotnego wektora y do wektora tymczasowego GSL

        gsl_vector_memcpy(poprzedniY, y);

        // Obliczanie wartosci dla wektora y do indeksu N-1

        for (int i = 1; i < N; i++)
        {
            sum = gsl_vector_get(e, i) * gsl_vector_get(y, i+1);
            sum += gsl_vector_get(f, i-1) * gsl_vector_get(y, i-1);
            gsl_vector_set(y, i, ((gsl_vector_get(b, i) - sum)/(gsl_vector_get(diag, i))));
        }

        // Obliczanie wartosci dla wektora y[N]

        sum = lewyDolnyRogMacierzyA * gsl_vector_get(y, 0);
        sum += gsl_vector_get(f, N-1) * gsl_vector_get(y, N-1);
        gsl_vector_set(y, N, ((gsl_vector_get(b, N) - sum)/(gsl_vector_get(diag, N))));

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(sprawdzenieDokladnosci, poprzedniY, y)) {
            break;
        }
    }

    // Zwolnienie pamięci wektorow tymczasowych GSL

    gsl_vector_free(poprzedniY);
    gsl_vector_free(sprawdzenieDokladnosci);
}

void successiveOverRelayation(const gsl_vector * diag, const gsl_vector * e, const gsl_vector * f, const gsl_vector * b, gsl_vector * y, int* iloscIteracji) {

    // Tworzenie wektorow tymczasowych GSL

    gsl_vector * poprzedniY = gsl_vector_calloc(N+1);
    gsl_vector * sprawdzenieDokladnosci = gsl_vector_alloc(N+1);

    double sum;

    // Przypisanie wartosci wektora y[0] z wektora b[0] na podstawie naszego ukladu rownan i wiersza pierwszego dla i = 0

    gsl_vector_set(y, 0, gsl_vector_get(b, 0));

    while (true)
    {

        // Zwiekszenie ilosci iteracji metody

        *iloscIteracji += 1;

        // Skopiowanie wartosci pierwotnego wektora y do wektora tymczasowego GSL

        gsl_vector_memcpy(poprzedniY, y);

        // Obliczanie wartosci dla wektora y do indeksu N-1

        for (int i = 1; i < N; i++)
        {
            sum = gsl_vector_get(e, i) * gsl_vector_get(y, i+1);
            sum += gsl_vector_get(f, i-1) * gsl_vector_get(y, i-1);
            gsl_vector_set(y, i, gsl_vector_get(y, i) + omega * ((gsl_vector_get(b, i) - sum) / gsl_vector_get(diag, i) - gsl_vector_get(y, i)));
        }

        // Obliczanie wartosci dla wektora y[N]

        sum = lewyDolnyRogMacierzyA * gsl_vector_get(y, 0);
        sum += gsl_vector_get(f, N-1) * gsl_vector_get(y, N-1);
        gsl_vector_set(y, N, gsl_vector_get(y, N) + omega * ((gsl_vector_get(b, N) - sum) / gsl_vector_get(diag, N) - gsl_vector_get(y, N)));

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(sprawdzenieDokladnosci, poprzedniY, y)) {
            break;
        }
    }

    // Zwolnienie pamięci wektorow tymczasowych GSL

    gsl_vector_free(poprzedniY);
    gsl_vector_free(sprawdzenieDokladnosci);
}

void wypenienieWektoraB(gsl_vector *b){
    gsl_vector_set_all(b, 0);
    gsl_vector_set(b, 0, 1);
}

void wypelnienieWektoraDiagonalnegoDiag(gsl_vector *diag){
    gsl_vector_set_all(diag, h*h + 2);
    gsl_vector_set(diag, 0, 1);
    gsl_vector_set(diag, N, 2);
}

void wypenienieWektoraTrojdiagonalnegoGornegoE(gsl_vector *e){
    gsl_vector_set_all(e, -1);
    gsl_vector_set(e, 0, 0);
}

void wypenienieWektoraTrojdiagonalnegoDolnegoF(gsl_vector *f){
    gsl_vector_set_all(f, -1);
}


