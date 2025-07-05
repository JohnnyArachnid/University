#include <iostream>

template<size_t N>
double pow(double x) {
    return ((N % 2) ? x : 1) * pow<N / 2>(x * x);
}

template<>
double pow<1>(double x) {
    return x;
}

template<>
double pow<0>(double x) {
    return 1.0;
}

int main() {
    std::cout << "Test pow<N>(x):\n";
    std::cout << "pow<3>(2.0) = " << pow<3>(2.0) << " (expected 8)\n";
    std::cout << "pow<4>(2.0) = " << pow<4>(2.0) << " (expected 16)\n";
    std::cout << "pow<0>(2.0) = " << pow<0>(2.0) << " (expected 1)\n";
    std::cout << "pow<1>(2.0) = " << pow<1>(2.0) << " (expected 2)\n";
    return 0;
}