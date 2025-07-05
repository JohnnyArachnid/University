#include <iostream>

template<size_t N, typename T = double>
struct Inner {
    static T dot(T* a, T* b) {
        return (*a) * (*b) + Inner<N-1, T>::dot(++a, ++b);
    }
};

template<typename T>
struct Inner<1, T> {
    static T dot(T* a, T* b) {
        return (*a) * (*b);
    }
};

template<size_t N, typename T = double>
T dot(T* a, T* b) {
    return Inner<N, T>::dot(a, b);
}

int main() {
    std::cout << "Test dot product (template version with type):\n";

    double c[] = {1.0, 2.0, 3.0};
    double d[] = {4.0, 5.0, 6.0};

    std::cout << "dot<3>(c, d) = " << dot<3>(c, d) << " (expected 32)\n";

    std::cout << "\nTest with float type:\n";

    float e[] = {1.5f, 2.5f, 3.5f};
    float f[] = {4.5f, 5.5f, 6.5f};

    std::cout << "dot<3>(e, f) = " << dot<3>(e, f) << " (expected about 45.25)\n";

    return 0;
}