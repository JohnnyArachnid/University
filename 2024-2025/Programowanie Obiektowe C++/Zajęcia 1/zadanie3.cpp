#include <iostream>
#include <array>

template <typename T, std::size_t N>
T dot_product(const std::array<T, N>& vec1, const std::array<T, N>& vec2) {
    T result = 0;
    for (std::size_t i = 0; i < N; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

void zadanie3_testy() {
    std::array<int, 3> vec1 = {1, 2, 3};
    std::array<int, 3> vec2 = {4, 5, 6};
    
    std::array<double, 4> vec3 = {1.5, 2.5, 3.5, 4.5};
    std::array<double, 4> vec4 = {0.5, 1.5, 2.5, 3.5};

    std::cout << "dot_product<int, 3> = " << dot_product(vec1, vec2) << std::endl;
    std::cout << "dot_product<double, 4> = " << dot_product(vec3, vec4) << std::endl;
}

int main() {
    zadanie3_testy();
    return 0;
}