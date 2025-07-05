#include <iostream>
#include <string>

template <typename T>
T convert(const std::string& str);

template <>
int convert<int>(const std::string& str) {
    return std::stoi(str);
}

template <>
double convert<double>(const std::string& str) {
    return std::stod(str);
}

int main() {
    std::string int_str = "123";
    std::string double_str = "45.67";
    
    int int_value = convert<int>(int_str);
    double double_value = convert<double>(double_str);
    
    std::cout << "Converted int: " << int_value << std::endl;
    std::cout << "Converted double: " << double_value << std::endl;
    
    return 0;
}