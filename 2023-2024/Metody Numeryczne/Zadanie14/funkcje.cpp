// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

double wynikFunkcjiPodCalkowej(double x) {
    return exp(cos(x) * cos(x));
}

bool sprawdzenieDokladnosciObliczen(double wynik, double poprzedniWynik) {
    if (fabs(wynik-poprzedniWynik) < epsilon)
    {
        return false;
    }
    return true;
}

double metodaTrapezow(int * liczbaIteracji) {

    // Deklaracja zmiennych

    int n = 1;
    double wynik;
    double poprzedniWynik;
    double szereg = (wynikFunkcjiPodCalkowej(poczatekGranicyCalkowania) + wynikFunkcjiPodCalkowej(koniecGranicyCalkowania)) / 2;
    double x = poczatekGranicyCalkowania;
    double h;

    // Wyzerowanie iteratora

    *liczbaIteracji = 0;

    while (true)
    {

        // Zwiekszenie iteratora

        *liczbaIteracji += 1;

        // Aktualizacja wartosci kolejnej iteracji

        poprzedniWynik = wynik;
        h = (koniecGranicyCalkowania - poczatekGranicyCalkowania) / n;
        x += h / 2;

        // Obliczenie wartosci szeregu

        for (int j = 0; j < n; j++)
        {
            szereg += wynikFunkcjiPodCalkowej(x);
            x += h;
        }

        // Aktualizacja wyniku

        wynik = h / 2 * szereg;

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(wynik, poprzedniWynik))
        {
            break;
        }

        // Zwiekszenie n

        n *= 2;
    }

    // Zwrocenie wyniku

    return wynik;
}

double metodaSimpsona(int * liczbaIteracji) {

    // Deklaracja zmiennych

    int n = 2;
    double wynik = 0;
    double poprzedniWynik;
    double szeregGranica = wynikFunkcjiPodCalkowej(poczatekGranicyCalkowania) + wynikFunkcjiPodCalkowej(koniecGranicyCalkowania);
    double szereg4 = 0;
    double szereg2 = 0;
    double h;

    // Wyzerowanie iteratora

    *liczbaIteracji = 0;

    while (true)
    {

        // Zwiekszenie iteratora

        *liczbaIteracji += 1;

        // Aktualizacja wartosci kolejnej iteracji

        poprzedniWynik = wynik;
        h = (koniecGranicyCalkowania - poczatekGranicyCalkowania ) / n;

        // Obliczenie wartosci szeregu

        szereg2 += szereg4;

        // Wyzerowanie szeregu we wzorze dla kolejnej iteracji

        szereg4 = 0;

        // Kolejna iteracja

        for (int j = 1; j <= n; j += 2)
        { 
            szereg4 += wynikFunkcjiPodCalkowej(poczatekGranicyCalkowania + j * h);
        }

        // Aktualizacja wyniku

        wynik = (h / 3) * (szeregGranica + 4 * szereg4 + 2 * szereg2);

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(wynik, poprzedniWynik))
        {
            break;
        }

        // Zwiekszenie n

        n *= 2;
    }

    // Zwrocenie wyniku

    return wynik;
}


double regula38(int * liczbaIteracji) {

    // Deklaracja zmiennych

    int n = 3;
    double wynik = 0;
    double poprzedniWynik;
    double szeregGranica = wynikFunkcjiPodCalkowej(poczatekGranicyCalkowania) + wynikFunkcjiPodCalkowej(koniecGranicyCalkowania);
    double szereg3 = 0;
    double szereg2 = 0;
    double h;

    // Wyzerowanie iteratora

    *liczbaIteracji = 0;

    while (true)
    {

        // Zwiekszenie iteratora

        *liczbaIteracji += 1;

        // Aktualizacja wartosci kolejnej iteracji

        h = (koniecGranicyCalkowania - poczatekGranicyCalkowania ) / n;
        poprzedniWynik = wynik;

        // Obliczenie wartosci szeregu

        szereg2 += szereg3;

        // Wyzerowanie szeregu we wzorze dla kolejnej iteracji

        szereg3 = 0;

        // Kolejna iteracja

        for (int j = 1; j <= n; j += 3)
        {
            szereg3 += wynikFunkcjiPodCalkowej(poczatekGranicyCalkowania + j * h) + wynikFunkcjiPodCalkowej(poczatekGranicyCalkowania + (j + 1) * h);
        }

        // Aktualizacja wyniku

        wynik = (3 * h / 8) * (szeregGranica + 3 * szereg3 + 2 * szereg2);

        // Sprawdzenie dokladnosci obliczen

        if (!sprawdzenieDokladnosciObliczen(wynik, poprzedniWynik))
        {
            break;
        }

        // Zwiekszenie n

        n *= 3;

    }

    // Zwrocenie wyniku

    return wynik;
}

