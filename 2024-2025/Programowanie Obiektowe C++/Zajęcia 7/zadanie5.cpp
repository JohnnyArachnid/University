#include <iostream>

template<size_t N>
double inner(double* a, double* b) {
    return (*a) * (*b) + inner<N-1>(++a, ++b);
}

template<>
double inner<1>(double* a, double* b) {
    return (*a) * (*b);
}

int main() {
    std::cout << "Test inner product (double version):\n";

    double a[] = {1.0, 2.0, 3.0};
    double b[] = {4.0, 5.0, 6.0};

    std::cout << "inner<3>(a, b) = " << inner<3>(a, b) << " (expected 32)\n";

    return 0;
}