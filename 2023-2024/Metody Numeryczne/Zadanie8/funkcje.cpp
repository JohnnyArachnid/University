// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

void iloczynSkalarnyWektoraIMacierzy(const gsl_matrix * A, const gsl_vector * wektor, gsl_vector * wynik) {

    // Deklaracja zmiennej ktora bedzie przechowywac wynik iloczynu skalarnego wiersza macierz A oraz wektra

    double wartoscScalarna;
    gsl_vector * wektorWierszaMacierzyA = gsl_vector_alloc(N); // wektor przechowujacy wiersz macierzy A
    for (int i = 0; i < N; i++)
    {
        gsl_matrix_get_row(wektorWierszaMacierzyA, A, i);
        gsl_blas_ddot(wektorWierszaMacierzyA, wektor, &wartoscScalarna);
        gsl_vector_set(wynik, i, wartoscScalarna);
    }

    // Zwolnienie pamięci wektora tymczasowego GSL

    gsl_vector_free(wektorWierszaMacierzyA);
}

bool sprawdzenieDokladnosciObliczen(double poprzedniaWartosc, double wartosc) {
    if (fabs(poprzedniaWartosc - wartosc) < epsilon)
    {
        return false;
    }
    return true;
}

void metodaPotegowa(const gsl_matrix * A, gsl_vector *wartosciWlasneMacierzyA) {

    // Deklaracja tablicy przechowujacej wektory wlasne macierzy A GSL

    gsl_vector * tablicaWektorowWlasnychMacierzyA[N];
    for (int i = 0; i < N; i++) { tablicaWektorowWlasnychMacierzyA[i] = gsl_vector_calloc(N); }

    // Deklaracja wektorow do obliczenia wartosci wlasnych macierzy A GSL

    gsl_vector * v_k = gsl_vector_alloc(N);
    gsl_vector * w_k = gsl_vector_alloc(N);
    gsl_vector * poprzednieV = gsl_vector_alloc(N);
    gsl_vector * wektorTymczasowyDoObliczen = gsl_vector_alloc(N);

    // Deklaracja zmiennych typu double do obliczenia wartosci wlasnych macierzy A GSL

    double wartoscWlasnaMacierzyA;
    double poprzedniaWartoscWlasnaMacierzyA;
    double iloczynSkalarny;
    double normaW;

    for (int i = 0; i < N; i++)
    {

        // Wypelnienie wektora v_k-1 tak aby jego norma wynosila 1

        gsl_vector_set(poprzednieV, 0, 1);
        gsl_vector_set(poprzednieV, 1, 0);
        gsl_vector_set(poprzednieV, 2, 0);

        // Wyzerowanie zmiennej wartosci wlasnej macierzy A wraz z kolejna iteracja

        wartoscWlasnaMacierzyA = 0;

        while (true)
        {
            // Przypisanie wartosci zmiennej poprzednej wartosci wlasnej macierzy A

            poprzedniaWartoscWlasnaMacierzyA = wartoscWlasnaMacierzyA;

            // Obliczenie wektora w_k

            iloczynSkalarnyWektoraIMacierzy(A, poprzednieV, w_k);

            // Obliczenie normy wektora w_k do obliczenia wartosci wlasnej macierzy A

            normaW = gsl_blas_dnrm2(w_k);

            // Obliczenie wektora v_k

            for (int k = 0; k < N; k++)
            {
                gsl_vector_set(v_k, k, gsl_vector_get(w_k, k) / normaW);
            }

            // Obliczenie wartosci wlasnej macierzy A

            wartoscWlasnaMacierzyA = normaW / gsl_blas_dnrm2(poprzednieV);

            // Wyzerowanie wektora tymczasowego do obliczen

            gsl_vector_set_all(wektorTymczasowyDoObliczen, 0);

            // Deflacja w celu obliczenia kolejnych wartosci wlasnych macierzy A

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

        // Zapisanie wektora wlasnego macierzy A GSL

        gsl_vector_set(wartosciWlasneMacierzyA,i,wartoscWlasnaMacierzyA);
        gsl_vector_memcpy(tablicaWektorowWlasnychMacierzyA[i], poprzednieV);
    }

    // Zwolnienie pamięci wektorow GSL

    for (int i = 0; i < N; i++) { gsl_vector_free(tablicaWektorowWlasnychMacierzyA[i]); }
    gsl_vector_free(v_k);
    gsl_vector_free(w_k);
    gsl_vector_free(poprzednieV);
    gsl_vector_free(wektorTymczasowyDoObliczen);
}

void metodaRayleigha(const gsl_matrix * A, gsl_vector *wartosciWlasneMacierzyA) {
    
    // Deklaracja wektorow oraz macierzy do obliczenia wartosci wlasnych macierzy A GSL

    gsl_vector * v_k = gsl_vector_alloc(N);
    gsl_vector * w_k = gsl_vector_alloc(N);
    gsl_vector * poprzednieV = gsl_vector_alloc(N);
    gsl_matrix * tymczasoweA = gsl_matrix_alloc(N, N);

    // Deklaracja zmiennych do skutecznego obliczenia kolejnych wartosci wlasnych deflacyjnie

    gsl_matrix * macierzDeflacja = gsl_matrix_alloc(N, N);
    gsl_matrix * deflacjaA = gsl_matrix_alloc(N, N);
    gsl_matrix * wierszDeflacja = gsl_matrix_alloc(1, N);
    gsl_matrix * kolumnaDeflacja = gsl_matrix_alloc(N, 1);

    // Deklaracja zmiennych typu double do obliczenia wartosci wlasnych macierzy A GSL

    double wartoscWlasnaMacierzyA = std::numeric_limits<double>::max();
    double poprzedniaWartoscWlasnaMacierzyA;
    double normaW;
    double iloczynSkalarny;

    // Skopiowanie macierzy A GSL w celu obliczenia kolejnych wartosci wlasnych

    gsl_matrix_memcpy(deflacjaA, A);

    for (int i = 0; i < N; i++)
    {
        /* Wypelnienie wektora v_k-1 tak aby jego norma wynosila 1.
        Metoda jest wrazliwa na dobor wektora v poczatkowego stad specjalnie dobralem wektora aby metoda byla skuteczna */ 

        if (i == 0){
            gsl_vector_set(poprzednieV, 0, 0);
            gsl_vector_set(poprzednieV, 1, 1);
            gsl_vector_set(poprzednieV, 2, 0);
        } else if (i == 1) {
            gsl_vector_set(poprzednieV, 0, 0);
            gsl_vector_set(poprzednieV, 1, 0);
            gsl_vector_set(poprzednieV, 2, 1);
        } else if (i == 2) {
            gsl_vector_set(poprzednieV, 0, 1);
            gsl_vector_set(poprzednieV, 1, 0);
            gsl_vector_set(poprzednieV, 2, 0);
        }
        
        while (true)
        {
            // Przypisanie wartosci zmiennej poprzednej wartosci wlasnej macierzy A

            poprzedniaWartoscWlasnaMacierzyA = wartoscWlasnaMacierzyA;

            // Skopiowanie macierzy A zmienionej podczas deflacji do macierzy tymczasowej wykorzystywanej podczas obliczen

            gsl_matrix_memcpy(tymczasoweA, deflacjaA);

            for (int k = 0; k < N; k++) { gsl_matrix_set(tymczasoweA, k, k, gsl_matrix_get(tymczasoweA, k, k) - wartoscWlasnaMacierzyA); }

            // Rozwiazanie ukladu rownan metoda LU z wykorzystaniem funkcji wbudowanych GSL

            int signum;
            gsl_permutation * permutacje =  gsl_permutation_alloc(N);
            gsl_linalg_LU_decomp(tymczasoweA, permutacje, &signum);
            gsl_linalg_LU_solve(tymczasoweA, permutacje, poprzednieV, w_k);

            // Obliczenie normy wektora w_k do obliczenia wartosci wlasnej macierzy A

            normaW = gsl_blas_dnrm2(w_k);

            // Obliczenie wektora poprzedniej iteracji v_k

            for (int k = 0; k < N; k++) { gsl_vector_set(poprzednieV, k, gsl_vector_get(w_k, k) / normaW); }

            // Obliczenie wektora v_k

            iloczynSkalarnyWektoraIMacierzy(deflacjaA, poprzednieV, v_k);

            // Obliczenie wartosci wlasnej macierzy A 

            gsl_blas_ddot(poprzednieV, v_k, &wartoscWlasnaMacierzyA);

            // Sprawdzenie dokladnosci obliczen

            if (!sprawdzenieDokladnosciObliczen(poprzedniaWartoscWlasnaMacierzyA, wartoscWlasnaMacierzyA)) {
                break;
            }
        }

        // Zapisanie wartosci wlasnej macierzy A GSL

        gsl_vector_set(wartosciWlasneMacierzyA, i, wartoscWlasnaMacierzyA);

        // Deflacja w celu obliczenia kolejnych wartosci wlasnych macierzy A

        // Oblicznenie iloczynu skalarnego

        gsl_blas_ddot(poprzednieV, poprzednieV, &iloczynSkalarny);

        // Wypelnienie pierwszego wiersza i kolumny wartosciom poprzedniego wektora v_k

        gsl_matrix_set_row(wierszDeflacja, 0, poprzednieV);
        gsl_matrix_set_col(kolumnaDeflacja, 0, poprzednieV);

        // Wykonanie mnozenia macierzowego i wyniku zapisanie do macierzDeflacja

        gsl_blas_dgemm (CblasNoTrans, CblasNoTrans, 1.0, kolumnaDeflacja, wierszDeflacja, 0.0, macierzDeflacja);

        // Aktualizacja wartosci iloczynu skalarnego poprzez podzielenie go przez wartosc wlasna macierzy A GSL

        iloczynSkalarny = wartoscWlasnaMacierzyA / iloczynSkalarny;

        // Wykorzystanie iloczynu skalarnego w celu wypelnienia macierzy deflacji

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                gsl_matrix_set(macierzDeflacja, j, k, gsl_matrix_get(macierzDeflacja, j, k) * iloczynSkalarny);
            }
        }

        // Finalizacja procesu deflacji

        gsl_matrix_sub(deflacjaA, macierzDeflacja);
    }

    // Zwolnienie pamięci wektorow oraz macierzy GSL

    gsl_vector_free(v_k);
    gsl_vector_free(w_k);
    gsl_vector_free(poprzednieV);
    gsl_matrix_free(tymczasoweA);
    gsl_matrix_free(macierzDeflacja);
    gsl_matrix_free(deflacjaA);
    gsl_matrix_free(wierszDeflacja);
    gsl_matrix_free(kolumnaDeflacja);
}

void metodaIteracyjnaQR(const gsl_matrix * A, gsl_vector *wartosciWlasneMacierzyA) {
    
    // Deklaracja wektorow oraz macierzy do obliczenia wartosci wlasnych macierzy A GSL

    gsl_matrix * QR = gsl_matrix_alloc(N, N);
    gsl_matrix * Q = gsl_matrix_alloc(N, N);
    gsl_matrix * R = gsl_matrix_alloc(N, N);
    gsl_vector * theta = gsl_vector_alloc(N);
    gsl_vector *wektorDiagonalny = gsl_vector_alloc(N);
    gsl_vector_view widokWektoraDiagonalnego;

    // Deklaracja zmiennych typu double do obliczenia wartosci wlasnych macierzy A GSL

    double poprzedniaNormaDiagonaliQR;
    double normaDiagonali = 0;

    // Skopiowanie macierzy A GSL w celu obliczenia kolejnych wartosci wlasnych

    gsl_matrix_memcpy(QR, A);

    while (true)
    {

        // Skorzystanie z rozkladu QR w celu utworzenia macierzy pomocniczych Q i R

        gsl_linalg_QR_decomp(QR, theta);
        gsl_linalg_QR_unpack(QR, theta, Q, R);

        // Pomnozenie macierzy R i Q w celu otrzymania wartosci wlasnych macierzy A na diagonali QR

        gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, R, Q, 0.0, QR);

        // Uzyskanie widoku wektora diagonalnego w celu skopiowania diagonali macierzy QR GSL

        widokWektoraDiagonalnego = gsl_matrix_diagonal(QR);

        // Przypisanie diagonali macierzy QR GSL do wektora

        gsl_vector_memcpy(wektorDiagonalny, &widokWektoraDiagonalnego.vector);

        // Zapisanie normy diagonali poprzedniej iteracji

        poprzedniaNormaDiagonaliQR = normaDiagonali;

        // Obliczenie normy diagonali obecnej iteracji

        normaDiagonali = gsl_blas_dnrm2(wektorDiagonalny);

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(poprzedniaNormaDiagonaliQR, normaDiagonali)) {
            break;
        }
    }

    // Zapisanie wartosci wlasnej macierzy A GSL

    for (int i = 0; i < N; i++) { gsl_vector_set(wartosciWlasneMacierzyA,i, gsl_matrix_get(QR, i, i)); }

    // Zwolnienie pamięci wektorow oraz macierzy GSL

    gsl_matrix_free(Q);
    gsl_matrix_free(R);
    gsl_matrix_free(QR);
    gsl_vector_free(theta);
    gsl_vector_free(wektorDiagonalny);
}

void wypelnienieMacierzyA(gsl_matrix * A) {
    for (int i = 0; i < N; i++) { gsl_matrix_set(A, 0, i, i + 1); }
    gsl_matrix_set(A, 1, 0, 2);
    gsl_matrix_set(A, 1, 1, 4);
    gsl_matrix_set(A, 1, 2, 5);
    gsl_matrix_set(A, 2, 0, 3);
    gsl_matrix_set(A, 2, 1, 5);
    gsl_matrix_set(A, 2, 2, -1);
}


