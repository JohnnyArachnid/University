#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T,int N = 100, typename R = T*> class Stack;

template<typename T, int N>
class Stack<T, N, T*> {
    T _rep[N];
    unsigned int _top;
public:
    Stack() : _top(0) {}
    void push(T e) {
        if (_top < N) {
            _rep[_top++] = e;
        } else {
            throw std::overflow_error("Stack overflow");
        }
    }
    T pop() {
        if (_top > 0) {
            return _rep[--_top];
        } else {
            throw std::underflow_error("Stack underflow");
        }
    }
    bool is_empty() const {
        return _top == 0;
    }
};

template<typename T, int N, template<typename E> class Sequence>
class Stack<T, N, Sequence<T>> {
    Sequence<T> _rep;
public:
    Stack() {}
    void push(T e) {
        _rep.push_back(e);
    }
    T pop() {
        if (!_rep.empty()) {
            T top = _rep.back();
            _rep.pop_back();
            return top;
        } else {
            throw std::underflow_error("Stack underflow");
        }
    }
    bool is_empty() const {
        return _rep.empty();
    }
};

int main() {
    try {
        Stack<int, 100> s_default;
        s_default.push(55);
        std::cout << "Popped from Stack<int, 100>: " << s_default.pop() << std::endl;

        Stack<int, 0, std::vector<int>> s_container;
        s_container.push(77);
        std::cout << "Popped from Stack<int, 0, std::vector<int>>: " << s_container.pop() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}