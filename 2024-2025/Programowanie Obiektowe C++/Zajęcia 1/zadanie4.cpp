#include <iostream>
#include <string>
#include <type_traits>

template <typename K>
class C {
private:
    K value;
public:
    C(K v) : value(v) {}
    K getValue() const { return value; }
};

template <typename K>
void f(const C<K>& obj) {
    std::cout << "Typ argumentu: C<" << typeid(K).name() << ">, wartosc: " << obj.getValue() << std::endl;
}

void zadanie4_testy() {
    C<int> cInt(10);
    C<double> cDouble(3.14);
    C<std::string> cString("Hello");

    f(cInt);
    f(cDouble);
    f(cString);
}

int main() {
    zadanie4_testy();
    return 0;
}