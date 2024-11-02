// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

void wypelnienieWektoraR(gsl_vector * r_k, const gsl_matrix * A, const gsl_vector * b, const gsl_vector * x) {
    gsl_vector * wektorWierszaMacierzyA = gsl_vector_alloc(N); // wektor przechowujacy wiersz macierzy A
    for(int i = 0; i < N; i++) {
        gsl_matrix_get_row(wektorWierszaMacierzyA, A, i);
        gsl_vector_set(r_k, i, gsl_vector_get(b, i) - (gsl_vector_get(wektorWierszaMacierzyA, i) * gsl_vector_get(x, i)));
    }

    // Zwolnienie pamięci wektora tymczasowego GSL

    gsl_vector_free(wektorWierszaMacierzyA);
}

void kolejnaIteracja(gsl_vector * a, const gsl_vector * b, const double wartoscScalarna) {
    for(int i = 0; i < N; i++) {
        gsl_vector_set(a, i, gsl_vector_get(a, i) + wartoscScalarna * gsl_vector_get(b, i));
    }
}

void iloczynSkalarnyWektoraIMacierzy(const gsl_matrix * A, const gsl_vector * p_k, gsl_vector * Ap_k) {

    // Deklaracja zmiennej ktora bedzie przechowywac wynik iloczynu skalarnego wiersza macierz A oraz wektora p_k

    double wartoscScalarna;
    gsl_vector * wektorWierszaMacierzyA = gsl_vector_alloc(N); // wektor przechowujacy wiersz macierzy A
    for (int i = 0; i < N; i++)
    {
        gsl_matrix_get_row(wektorWierszaMacierzyA, A, i);
        gsl_blas_ddot(wektorWierszaMacierzyA, p_k, &wartoscScalarna);
        gsl_vector_set(Ap_k, i, wartoscScalarna);
    }

    // Zwolnienie pamięci wektora tymczasowego GSL

    gsl_vector_free(wektorWierszaMacierzyA);
}

bool sprawdzenieDokladnosciObliczen(gsl_vector * r_k) {

    // Sprawdzenie dokladnosci poprzez porownanie normy wektora rezyduum po aktualizacji z wartoscia epsilon

    if (gsl_blas_dnrm2(r_k) < epsilon)
    {
        return false;
    }
    return true;
}

void metodaGradientowSprzezonych(const gsl_matrix * A, const gsl_vector * b, gsl_vector * x) {

    // Tworzenie wektorow tymczasowych GSL

    gsl_vector * r_k = gsl_vector_alloc(N); // wektor rezyduum
    gsl_vector * p_k = gsl_vector_alloc(N); // wektor sprzezony
    gsl_vector * Ap_k = gsl_vector_alloc(N); // wektor do przechowywania wynikow funkcji IloczynSkalarnyWektoraIMacierzy

    // Wypelnienie wektorow r_k i p_k

    wypelnienieWektoraR(r_k, A, b, x);
    gsl_vector_memcpy(p_k, r_k);

    // Deklaracja zmiennych licznika i mianownika do obliczenia alphy_k i bety_k, mianownik na obliczenie bety_k pokrywa sie z licznikiem na obliczenie alphy_k, stad tylko 3 zmienne zamiast 4

    double licznikAlpha_k;
    double mianownikAlpha_k;
    double licznikBeta_k;

    // Deklaracja zmiennych alpha_k i beta_k do wykonania algorytmu

    double alpha_k;
    double beta_k;

    while (true)
    {

        // Oblicznenie iloczynu wektorow transpozycja r_k oraz r_k, bedzie sie to sprowadzac do iloczynu skalarnego tego wektora przez siebie

        gsl_blas_ddot(r_k, r_k, &licznikAlpha_k);

        /* Obliczenie iloczynu macierzy A oraz wektora p_k.
        Wynikiem bedzie wektor Ap_k, ktory bedzie przechowywal iloczyny skalarne kolejnych wierszy macierzy A oraz wektora p_k */

        iloczynSkalarnyWektoraIMacierzy(A, p_k, Ap_k);

        // Oblicznenie iloczynu wektorow transpozycja p_k oraz Ap_k, bedzie sie to sprowadzac do iloczynu skalarnego tych wektorow

        gsl_blas_ddot(p_k, Ap_k, &mianownikAlpha_k);

        // Obliczenie alpha_k

        alpha_k = licznikAlpha_k / mianownikAlpha_k;

        // Obliczanie x oraz r_k dla kolejnej iteracji

        kolejnaIteracja(x, p_k, alpha_k);
        kolejnaIteracja(r_k, Ap_k, -alpha_k);

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(r_k)) {
            break;
        }

        // Obliczamy ponownie iloczyn skalarny r_k przez siebie, z ta roznica ze wektor r_k jest po aktualizacji

        gsl_blas_ddot(r_k, r_k, &licznikBeta_k);

        // Obliczenie beta_k

        beta_k = licznikBeta_k / licznikAlpha_k;

        // Obliczanie p_k dla kolejnej iteracji

        kolejnaIteracja(p_k, r_k, beta_k);
    }

    // Zwolnienie pamięci wektorow oraz macierzy GSL

    gsl_vector_free(r_k);
    gsl_vector_free(p_k);
    gsl_vector_free(Ap_k);
}

void wypelnienieMacierzyA(gsl_matrix *A) {
    gsl_matrix_set(A, 0, 0, 4);
    gsl_matrix_set(A, 0, 1, -1);
    gsl_matrix_set(A, 0, 2, 0);
    gsl_matrix_set(A, 1, 0, -1);
    gsl_matrix_set(A, 1, 1, 4);
    gsl_matrix_set(A, 1, 2, -1);
    gsl_matrix_set(A, 2, 0, 0);
    gsl_matrix_set(A, 2, 1, -1);
    gsl_matrix_set(A, 2, 2, 4);
}

void wypenienieWektoraB(gsl_vector *b) {
    gsl_vector_set(b, 0, 2);
    gsl_vector_set(b, 1, 6);
    gsl_vector_set(b, 2, 2);
}




