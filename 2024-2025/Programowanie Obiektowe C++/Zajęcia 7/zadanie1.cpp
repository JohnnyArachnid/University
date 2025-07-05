#include <iostream>

template<size_t N>
struct factorial {
    enum { val = N * factorial<N - 1>::val };
};

template<>
struct factorial<0> {
    enum { val = 1 };
};

int main() {
    std::cout << "Test factorial:\n";
    std::cout << "factorial<0>::val = " << factorial<0>::val << " (expected 1)\n";
    std::cout << "factorial<5>::val = " << factorial<5>::val << " (expected 120)\n";
    std::cout << "factorial<6>::val = " << factorial<6>::val << " (expected 720)\n";
    return 0;
}