// Autor: Daniel Szarek
//=====================

#include "funkcje.h"

bool sprawdzenieDokladnosciObliczenDlaWspolrzednychX(const double wartoscX1, const double wartoscX2) {
    if (fabs(wartoscX1 - wartoscX2) < epsilon)
    {
        return false;
    }
    return true;
}

bool sprawdzenieDokladnosciObliczenDlaWartosciY(const double wartoscY) {
    if (fabs(wartoscY) < epsilon) {
        return false;
    }
    return true;
}

void metodaNewtona(Wielomian & a, const gsl_vector * przedzialyPierwiastkowWielomianu, gsl_vector * pierwiastkiWielomianu, int iterator[]) {
     for (size_t i = 0; i < a.rozmiar * 2; i += 2) 
     {

        // Wyzerowanie iteratora

        iterator[i / 2] = 0;

        // Wybranie wspolrzednej x punktu startowego

        double wartoscX = (gsl_vector_get(przedzialyPierwiastkowWielomianu, i) + gsl_vector_get(przedzialyPierwiastkowWielomianu, i + 1)) / 2;

        // Inicjacja punktu startowego

        Punkt x1(wartoscX, a.wartoscWielomianuWPunkcie(wartoscX), a.wartoscWielomianuPochodnaWPunkcie(wartoscX));

        // Wyznacznie wartosci wspolczynnika kolejnej iteracji x

        wartoscX = x1.x - x1.y / x1.pochodnaY;

        // Inicjacja punktu kolejnej iteracji

        Punkt x2(wartoscX, a.wartoscWielomianuWPunkcie(wartoscX), a.wartoscWielomianuPochodnaWPunkcie(wartoscX));

        while(true) {

            // Zwiekszenie iteratora

            iterator[i / 2] += 1;

            // Sprawdzenie zbieznosci

            if (!(sprawdzenieDokladnosciObliczenDlaWartosciY(x2.y) || sprawdzenieDokladnosciObliczenDlaWspolrzednychX(x1.x, x2.x))) {
                break;
            }

            // Kolejna iteracja

            wartoscX = x2.x - x2.y / x2.pochodnaY;
            x1 = x2;
            x2(wartoscX, a.wartoscWielomianuWPunkcie(wartoscX), a.wartoscWielomianuPochodnaWPunkcie(wartoscX));
        }

        // Zapisanie wyniku

        gsl_vector_set(pierwiastkiWielomianu, i / 2, x2.x);

    }
}

void metodaBisekcji(Wielomian & a, const gsl_vector * przedzialyPierwiastkowWielomianu, gsl_vector * pierwiastkiWielomianu, int * iterator) {
    for (size_t i = 0; i < a.rozmiar * 2; i += 2)
    {

        // Wyzerowanie iteratora

        iterator[i / 2] = 0;

        // Inicjacja punktow koncow przedzialu poszukiwan

        Punkt x1(gsl_vector_get(przedzialyPierwiastkowWielomianu, i), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i)), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i)));
        Punkt x3(gsl_vector_get(przedzialyPierwiastkowWielomianu, i + 1), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i + 1)), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i + 1)));

        // Inicjacja punktu pomiedzy krancami przedzialow

        Punkt x2((x1.x + x3.x) / 2, a.wartoscWielomianuWPunkcie((x1.x + x3.x) / 2), a.wartoscWielomianuWPunkcie((x1.x + x3.x) / 2));

        while (true)
        {

            // Zwiekszenie iteratora

            iterator[i / 2] += 1;

            // Sprawdzenie zbieznosci

            if (!(sprawdzenieDokladnosciObliczenDlaWartosciY(x2.y) || sprawdzenieDokladnosciObliczenDlaWspolrzednychX(x1.x, x3.x))) {
                break;
            }

            // Zastosowanie iteracyjnej formuly ze wzoru

            if (x1.y * x2.y >= 0)
            {
                x1 = x2;
            }
            else
            {
                x3 = x2;
            }

            // Kolejna iteracja

            x2((x1.x + x3.x) / 2,a.wartoscWielomianuWPunkcie((x1.x + x3.x) / 2),a.wartoscWielomianuWPunkcie((x1.x + x3.x) / 2));
        }

        // Zapisanie wyniku

        gsl_vector_set(pierwiastkiWielomianu, i / 2, x2.x);
    }
}

void metodaSiecznych(Wielomian & a, const gsl_vector * przedzialyPierwiastkowWielomianu, gsl_vector * pierwiastkiWielomianu, int iterator[]) {
    for (size_t i = 0; i < a.rozmiar * 2; i += 2)
    {
        // Wyzerowanie iteratora

        iterator[i / 2] = 0;

        // Wybranie dwoch punktow startowych

        Punkt x1(gsl_vector_get(przedzialyPierwiastkowWielomianu, i), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i)), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i)));
        Punkt x3(gsl_vector_get(przedzialyPierwiastkowWielomianu, i + 1), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i + 1)), a.wartoscWielomianuWPunkcie(gsl_vector_get(przedzialyPierwiastkowWielomianu, i + 1)));

        // Zastosowanie iteracyjnej formuly ze wzoru

        Punkt x2((x3.x - ((x3.y)*(x3.x - x1.x)/(x3.y-x1.y))), a.wartoscWielomianuWPunkcie((x3.x - ((x3.y)*(x3.x - x1.x)/(x3.y-x1.y)))),a.wartoscWielomianuWPunkcie((x3.x - ((x3.y)*(x3.x - x1.x)/(x3.y-x1.y)))));

        while (true)
        {

            // Zwiekszenie iteratora

            iterator[i / 2] += 1;

            // Sprawdzenie zbieznosci

            if (!(sprawdzenieDokladnosciObliczenDlaWartosciY(x2.y) || sprawdzenieDokladnosciObliczenDlaWspolrzednychX(x1.x, x3.x))) {
                break;
            }

            // Kolejna iteracja

            x1 = x3;
            x3 = x2;
            x2((x3.x - ((x3.y)*(x3.x - x1.x)/(x3.y-x1.y))),a.wartoscWielomianuWPunkcie((x3.x - ((x3.y)*(x3.x - x1.x)/(x3.y-x1.y)))),a.wartoscWielomianuWPunkcie((x3.x - ((x3.y)*(x3.x - x1.x)/(x3.y-x1.y)))));
        }

        // Zapisanie wyniku

        gsl_vector_set(pierwiastkiWielomianu, i / 2, x2.x);

    }
}


