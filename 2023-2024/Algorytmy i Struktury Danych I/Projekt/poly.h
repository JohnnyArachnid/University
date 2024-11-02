// Autor: Daniel Szarek
//=====================
// poly.h

#ifndef POLY_H
#define POLY_H

#include <iostream> // deklaracje strumienia cout
#include <unistd.h> // sleep()
#include <cassert> // assert()

template <typename T>
class Poly {
    unsigned size; // Rozmiar tablicy współczynników
    T* tab; // Tablica współczynników
public:
    Poly(); // Domyślny konstruktor
    Poly(const unsigned size); // Konstruktor rozmiaru
    Poly(const T* coefficients, const unsigned size); // Konstruktor tablicy współczynników i rozmiaru
    Poly(const Poly& other); // Konstruktor kopiujący
    ~Poly(); // Destruktor
    Poly operator+(const Poly& other) const; // Operator dodawania
    Poly& operator+=(const Poly& other); // Operator dodawania i przypisania
    Poly operator-(const Poly& other) const; // Operator odejmowania
    Poly& operator-=(const Poly& other); // Operator odjęcia i przypisania
    Poly operator*(const Poly& other) const; // Operator mnożenia
    Poly& operator*=(const Poly& other); // Operator mnożenia i przypisania
    Poly& operator=(const Poly& other); // Operator przypisania
    T& operator[](const unsigned degree) const; // Operator odczytu współczynnika przy danej potędze x
    bool operator==(const Poly& other) const; // Operator równości
    bool operator!=(const Poly& other) const; // Operator nierówności
    T algorytmHornera(const T& point) const; // Obliczanie wartości wielomianu algorytmem Hornera
    void wyswietlanie() const; // Wyświetlanie wielomianu w terminalu
    void clear(); // Wyzerowanie wielomianu
    bool is_zero() const; // Sprawdzenie czy wielomian jest wielomianem zerowym
    int degree() const; // Zwrocenie stopnia wielomianu
};

// Implementacja konstruktora domyślnego

template <typename T>
Poly<T>::Poly() : size(0), tab(nullptr) {}

// Implementacja konstruktora rozmiaru

template <typename T>
Poly<T>::Poly(const unsigned size) : size(size), tab(new T[size]()) {}

// Implementacja konstruktora tablicy współczynników i rozmiaru

template <typename T>
Poly<T>::Poly(const T* coefficients, const unsigned size) : size(size) {
    tab = new T[size];
    for (unsigned i = 0; i < size; i++) {
        tab[i] = coefficients[i];
    }
}

// Implementacja konstruktora kopiujacego

template <typename T>
Poly<T>::Poly(const Poly& other) : size(other.size) {
    tab = new T[size];
    for (unsigned i = 0; i < size; i++) {
        tab[i] = other.tab[i];
    }
}

// Implementacja destruktora

template <typename T>
Poly<T>::~Poly() {
    clear();
}

// Implementacja operatora dodawania

template <typename T>
Poly<T> Poly<T>::operator+(const Poly& other) const {
    if (is_zero()) { return other; }
    if (other.is_zero()) { return *this; }
    unsigned resultSize = (size >= other.size) ? size : other.size;
    Poly<T> result(resultSize);
    for (unsigned i = 0; i < size; i++) { result[i] = tab[i]; }
    for (unsigned i = 0; i < other.size; i++) { result[i] += other.tab[i]; }
    return result;
}

// Implementacja operatora dodawania i przypisania

template <typename T>
Poly<T>& Poly<T>::operator+=(const Poly& other) {
    *this = *this + other;
    return *this;
}

// Implementacja operatora odejmowania

template <typename T>
Poly<T> Poly<T>::operator-(const Poly& other) const {
    if (other.is_zero()) { return *this; }
    if (is_zero()) {
        Poly<T> result(other.size);
        for (unsigned i = 0; i < result.size; i++) { result[i] -= other.tab[i]; }
        return result;            
    }
    unsigned resultSize = (size >= other.size) ? size : other.size;
    Poly<T> result(resultSize);
    for (unsigned i = 0; i < size; i++) { result[i] = tab[i]; }
    for (unsigned i = 0; i < other.size; i++) { result[i] -= other.tab[i]; }
    return result;
}

// Implementacja operatora odjęcia i przypisania

template <typename T>
Poly<T>& Poly<T>::operator-=(const Poly& other) {
    *this = *this - other;
    return *this;
}

// Implementacja operatora mnożenia

template <typename T>
Poly<T> Poly<T>::operator*(const Poly& other) const {
    Poly<T> result;
    if (is_zero() || other.is_zero()) { return result; }
    unsigned resultSize = size + other.size - 1;
    result.size = resultSize;
    result.tab = new T[result.size]();
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < other.size; j++) {
            result.tab[i + j] += tab[i] * other.tab[j];
        }
    }
    return result;
}

// Implementacja operatora mnożenia i przypisania

template <typename T>
Poly<T>& Poly<T>::operator*=(const Poly& other) {
    *this = *this * other;
    return *this;
}

// Implementacja operatora przypisania

template <typename T>
Poly<T>& Poly<T>::operator=(const Poly& other) {
    if (this != &other) {
        clear();
        size = other.size;
        tab = new T[size];
        for (unsigned i = 0; i < size; i++) {
            tab[i] = other.tab[i];
        }
    }
    return *this;
}

// Implementacja operatoratora odczytu współczynnika przy danej potędze x

template <typename T>
T& Poly<T>::operator[](const unsigned degree) const {
    if (degree < 0 || degree >= size) {
        throw std::out_of_range("Wspolczynnik wykracza po za indeks tablicy wspolczynnikow");
    }
    return tab[degree];
}

// Implementacja operatora równości

template <typename T>
bool Poly<T>::operator==(const Poly& other) const {
    return (*this - other).is_zero();
}

// Implementacja operatora nierówności

template <typename T>
bool Poly<T>::operator!=(const Poly& other) const {
    return !(*this == other);
}

// Implementacja funkcji obliczania wartości wielomianu algorytmem Hornera

template <typename T>
T Poly<T>::algorytmHornera(const T& point) const {
    T result = T();
    for (int i = size - 1; i >= 0; i--) {
        result = result * point + tab[i];
    }
    return result;
}

// Implementacja funkcji wyswietlajaca wielomian w terminalu

template <typename T>
void Poly<T>::wyswietlanie() const {
    if (is_zero()) {
        std::cout << "Wielomian pusty" << std::endl;
        return;
    }
    for (int i = size - 1; i >= 0; i--) {
        if (tab[i] != 0) {
            if (tab[i] < 0 || i == (int)size - 1) {
                std::cout << tab[i];
            } else {
                std::cout << "+" << tab[i];
            }
            if (i > 0) { std::cout << "x^" << i; }
        }
    }
    std::cout << std::endl;
}

// Implementacja funckji zerujacej wielomian

template <typename T>
void Poly<T>::clear() {
    delete[] tab;
    tab = nullptr;
    size = 0;
}

// Implementacja funkcji sprawdzajacej czy wielomian jest wielomianem zerowym

template <typename T>
bool Poly<T>::is_zero() const {
    for (unsigned i = 0; i < size; i++) { if (tab[i] != T()) { return false; } }
    return true;
}

// Implementacja funkcji zwracajacej stopien wielomianu

template <typename T>
int Poly<T>::degree() const {
    return (int) size - 1;
}

#endif // POLY_H

// EOF
