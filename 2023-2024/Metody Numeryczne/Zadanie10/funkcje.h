// Autor: Daniel Szarek
//=====================

#include <cmath>
#include <cassert>
#include <iostream>
#include <fstream>
#include <chrono>
#include <gsl/gsl_linalg.h>

// Dokladnosc obliczen podanych w poleceniu

const double epsilon = 1.0e-8;

// Klasa wielomian utworzona na potrzebe obliczenia miejsc zerowych wyznacznika podanego w poleceniu

class Wielomian {
private:
    double wynikDzialan; // Zmienna do obliczen
public:
    double *wspolczynnikiWielomianu; // Tablica przechowujaca wspolczynniki wielomianu
    size_t rozmiar; // Wartosc stopnia wielomianu, zmienne wykorzystujemy do zainicjowania rozmiaru tablicy z wspolczynnikami wielomianu
    Wielomian() : wynikDzialan(0), wspolczynnikiWielomianu(nullptr), rozmiar(0)  {} // Konstruktor domyslny
    Wielomian(double *wspolczynnikiWielomianu, size_t rozmiar) { // Konstruktor z wartosciami
        this->wynikDzialan = 0; 
        this->rozmiar = rozmiar;
        this->wspolczynnikiWielomianu = new double[rozmiar + 1];
        for (size_t  i = 0 ; i <= rozmiar; i++) {
            this->wspolczynnikiWielomianu[i] = wspolczynnikiWielomianu[i];
        }
        assert(this->wspolczynnikiWielomianu != nullptr );
    }

    // Funkcja obliczajaca wartosc wielomianu w punkcie

    double wartoscWielomianuWPunkcie(const double x) {
        if (wynikDzialan != 0) {
            wynikDzialan = 0;
        }
        for (int i = 0; i <= (int)(rozmiar); i++) { wynikDzialan += pow(x, rozmiar - i) * wspolczynnikiWielomianu[i]; }
        return wynikDzialan;
    }

    // Funkcja obliczajaca wartosc pochodnej wielomianu w punkcie

    double wartoscWielomianuPochodnaWPunkcie(const double x) {
        if (wynikDzialan != 0) {
            wynikDzialan = 0;
        }
        for (int i = 0; i <= (int)(rozmiar); i++) {
            if (rozmiar - i == 0) { break ;} 
            wynikDzialan += pow(x, this->rozmiar - i - 1) * wspolczynnikiWielomianu[i] * (rozmiar - i);
        }
        return wynikDzialan;
    }

    // Destruktor

    ~Wielomian() { delete [] wspolczynnikiWielomianu; }
};

// Struktura Punkt odzwierciedlajaca punkt nalezacy do wykresu funkcji wielomianu, dodatkowo obliczam wartosc dla pochodnej do metody Newtona

struct Punkt {
public:
    double x; // Zmienna x
    double y;   // Zmienna f(x) = y
    double pochodnaY;   // Zmienna f`(x) = y
    Punkt() : x(0), y(0), pochodnaY(0) {} // Konstruktor domyslny
    Punkt(const double x, const double y, const double pochodnaY) { // Konstruktor z wartosciami
        this->x = x;
        this->y = y;
        this->pochodnaY = pochodnaY;
    }

    // Operator =, przypisujacy wartosci jednego Punktu do drugiego

    void operator=(const Punkt &other) {
        this->x = other.x;
        this->y = other.y;
        this->pochodnaY = other.pochodnaY;
    }

    // Ponowna inicjacja dla Punktu

    void operator()(const double x, const double y, const double pochodnaY) {
        this->x = x;
        this->y = y;
        this->pochodnaY = pochodnaY;
    }
        
    // Destruktor

    ~Punkt() {}
};

// Funkcja sprawdzajaca dokladnosc obliczen porownujac ja z naszym kryterium podanym w poleceniu dla wspolrzednych x

bool sprawdzenieDokladnosciObliczenDlaWspolrzednychX(const double wartoscX1, const double wartoscX2);

// Funkcja sprawdzajaca dokladnosc obliczen porownujac ja z naszym kryterium podanym w poleceniu dla wartosci y

bool sprawdzenieDokladnosciObliczenDlaWartosciY(const double wartoscY);

// Funkcja obliczajaca pierwiastki wielomianu metoda Newtona

void metodaNewtona(Wielomian & a, const gsl_vector * przedzialyPierwiastkowWielomianu, gsl_vector * pierwiastkiWielomianu, int iterator[]);

// Funkcja obliczajaca pierwiastki wielomianu metoda Bisekcji

void metodaBisekcji(Wielomian & a, const gsl_vector * przedzialyPierwiastkowWielomianu, gsl_vector * pierwiastkiWielomianu, int iterator[]);

// Funkcja obliczajaca pierwiastki wielomianu metoda Siecznych

void metodaSiecznych(Wielomian & a, const gsl_vector * przedzialyPierwiastkowWielomianu, gsl_vector * pierwiastkiWielomianu, int iterator[]);