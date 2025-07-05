#include <iostream>
#include <concepts>

template<std::integral T>
void wyswietl(T x) {
    std::cout << "Typ calkowity: " << x << std::endl;
}

template<std::floating_point T>
void wyswietl(T x) {
    std::cout << "Typ zmiennoprzecinkowy: " << x << std::endl;
}

int main() {
    wyswietl(42);
    wyswietl(3.14);
}
