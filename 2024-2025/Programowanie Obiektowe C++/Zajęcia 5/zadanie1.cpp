#include <iostream>

template<typename T>
struct is_class {
private:
    typedef char one;
    typedef struct { char c[2]; } two;

    template<typename U>
    static one test(int U::*);

    template<typename U>
    static two test(...); 

public:
    static constexpr bool value = sizeof(test<T>(nullptr)) == sizeof(one);
};

struct MyClass {};
enum MyEnum { A, B };

int main() {
    std::cout << std::boolalpha;
    std::cout << "MyClass is class? " << is_class<MyClass>::value << "\n";
    std::cout << "MyEnum is class? " << is_class<MyEnum>::value << "\n";
    std::cout << "int is class? " << is_class<int>::value << "\n"; 
    std::cout << "std::string is class? " << is_class<std::string>::value << "\n";
}