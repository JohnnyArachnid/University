#include <iostream>

template<size_t N, size_t M>
struct pow {
    enum { val = N * pow<N, M - 1>::val };
};

template<size_t N>
struct pow<N, 0> {
    enum { val = 1 };
};

template<size_t M>
struct pow<1, M> {
    enum { val = 1 };
};

template<size_t M>
struct pow<0, M> {
    enum { val = 0 };
};

template<>
struct pow<0,0> {
    enum { val = 0 };
};

int main() {
    std::cout << "Test pow<N, M>:\n";
    std::cout << "pow<2, 3>::val = " << pow<2,3>::val << " (expected 8)\n";
    std::cout << "pow<5, 0>::val = " << pow<5,0>::val << " (expected 1)\n";
    std::cout << "pow<1, 100>::val = " << pow<1,100>::val << " (expected 1)\n";
    std::cout << "pow<0, 5>::val = " << pow<0,5>::val << " (expected 0)\n";
    std::cout << "pow<0, 0>::val = " << pow<0,0>::val << " (expected 0)\n";
    return 0;
}