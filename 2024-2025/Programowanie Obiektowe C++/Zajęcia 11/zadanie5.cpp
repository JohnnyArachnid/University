#include <iostream>
#include <concepts>

template<typename T>
void wypisz(T x) {
    std::cout << "Ogolny typ: " << x << std::endl;
}

template<typename T>
requires std::integral<T>
void wypisz(T x) {
    std::cout << "Specjalizacja: typ calkowity: " << x << std::endl;
}

int main() {
    wypisz(123);
    wypisz(3.14);
    wypisz("tekst");
}
