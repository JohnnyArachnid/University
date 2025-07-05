#include <iostream>
#include <vector>
#include <deque>

template<typename T, typename U>
struct Is_convertible {
private:
    typedef char one;
    typedef struct { char c[2]; } two;

    static one test(U);
    static two test(...);
    static T makeT();

public:
    static constexpr bool value = sizeof(test(makeT())) == sizeof(one);
    static constexpr bool same_type = false;
};

template<typename T>
struct Is_convertible<T, T> {
    static constexpr bool value = true;
    static constexpr bool same_type = true;
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "int -> double is convertible? " << Is_convertible<int, double>::value << "\n";
    std::cout << "double -> int is convertible? " << Is_convertible<double, int>::value << "\n";
    std::cout << "double -> int same type? " << Is_convertible<double, int>::same_type << "\n";

    return 0;
}