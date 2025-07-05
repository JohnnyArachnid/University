#include <iostream>
#include <string>

template <typename T>
T maksimum(const T &a, const T &b) {
    return (a < b) ? b : a;
}

void zadanie1_testy() {
    std::cout << "maksimum(5, 10) = " << maksimum(5, 10) << std::endl;
    std::cout << "maksimum(3.14, 2.71) = " << maksimum(3.14, 2.71) << std::endl;
    std::cout << "maksimum(\"kot\", \"pies\") = " << maksimum(std::string("kot"), std::string("pies")) << std::endl;
}

int main() {
    zadanie1_testy();
    return 0;
}