#include <iostream>
#include <vector>
#include <list>

template<typename T>
struct has_value_type {
private:
    typedef char one;
    typedef struct { char c[2]; } two;

    template<typename U>
    static one test(typename U::value_type*);

    template<typename U>
    static two test(...);

public:
    static constexpr bool value = sizeof(test<T>(nullptr)) == sizeof(one);
};

// Testy
int main() {
    std::cout << std::boolalpha;
    std::cout << "std::vector<int> has value_type? " << has_value_type<std::vector<int>>::value << "\n";
    std::cout << "std::list<double> has value_type? " << has_value_type<std::list<double>>::value << "\n";
    std::cout << "int has value_type? " << has_value_type<int>::value << "\n";
    std::cout << "double has value_type? " << has_value_type<double>::value << "\n";
}