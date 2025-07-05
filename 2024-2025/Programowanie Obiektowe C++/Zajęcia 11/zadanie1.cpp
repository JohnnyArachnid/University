#include <concepts>
#include <iostream>

template<std::integral T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    std::cout << gcd(48, 18) << "\n";
    std::cout << gcd(128u, 32u) << "\n";
    // std::cout << gcd(3.5, 1.5) << "\n";     // UWAGA: błąd kompilacji!
    return 0;
}
