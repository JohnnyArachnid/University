#include <iostream>

template<size_t N>
double pow(double x) {
    return ((N % 2) ? x : 1) * pow<N/2>(x*x);
}

template<>
double pow<1>(double x) { return x; }

template<>
double pow<0>(double x) { return 1.0; }

template<int N>
struct factorial {
    enum { val = N * factorial<N-1>::val };
};

template<>
struct factorial<0> {
    enum { val = 1 };
};

template<int N>
double sin(double x) {
    return sin<N-1>(x) + (N % 2 ? 1 : -1) * pow<(2*N-1)>(x) / factorial<2*N-1>::val;
}

template<>
double sin<0>(double x) {
    return 0;
}

template<int N>
double inner(double *a, double *b) {
    return (*a) * (*b) + inner<N-1>(++a, ++b);
}

template<>
double inner<1>(double *a, double *b) {
    return (*a) * (*b);
}

int main() {
    std::cout << "Test sin approximation:\n";
    double x = 0.5;
    std::cout << "sin<5>(" << x << ") = " << sin<5>(x) << " (approximate)\n";
    return 0;
}