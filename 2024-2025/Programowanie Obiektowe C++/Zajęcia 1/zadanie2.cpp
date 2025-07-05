#include <iostream>
#include <string>

template <typename T, typename U>
T convert(U u) {
    return (T)u;
}

void zadanie2_testy() {
    std::cout << "convert<char>(65) = " << convert<char>(65) << std::endl;
    std::cout << "convert<int>(3.14) = " << convert<int>(3.14) << std::endl;
    std::cout << "convert<double>(42) = " << convert<double>(42) << std::endl;
    std::cout << "convert<std::string>(97) = " << std::to_string(convert<int>(97)) << std::endl;
}

int main() {
    zadanie2_testy();
    return 0;
}