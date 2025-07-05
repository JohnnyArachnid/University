#include <iostream>
#include <string>

template <typename T>
class Stack {
public:
    static const size_t N = 100;
    typedef T value_type;

private:
    T _rep[100];
    size_t _top;

public:
    Stack() : _top(0) {}
    void push(T val) {_rep[_top++]=val;}
    T pop() {return _rep[--_top];}
    bool is_empty() { return (_top == 0);}

};

template<typename S>
typename S::value_type f(S s) {
    typename S::value_type total = 0;
    while (!s.is_empty()) {
        total += s.pop();
    }
    return total;
};

void test_stack_sum() {
    Stack<int> int_stack;
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);

    std::cout << "Suma elementow stosu int: " << f(int_stack) << std::endl;

    Stack<double> double_stack;
    double_stack.push(1.1);
    double_stack.push(2.2);
    double_stack.push(3.3);

    std::cout << "Suma elementow stosu double: " << f(double_stack) << std::endl;
}

int main() {
    test_stack_sum();
    return 0;
}