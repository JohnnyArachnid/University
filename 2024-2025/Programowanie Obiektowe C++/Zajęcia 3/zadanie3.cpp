#include <iostream>
#include <stdexcept>

template<typename T,int N = 100> class Stack;

template<typename T>
class Stack<T, 666> {
    T _rep[666];
    unsigned int _top;
public:
    Stack() : _top(0) {}
    void push(T e) { 
        if (_top < 666) {
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
    bool is_empty() const { return _top == 0; }
};

template<typename T, int N>
class Stack<T*, N> {
    T* _rep[N];
    unsigned int _top;
public:
    Stack() : _top(0) {}
    void push(T* e) { 
        if (_top < N) {
            _rep[_top++] = e;
        } else {
            throw std::overflow_error("Stack overflow");
        }
    }
    T* pop() {
        if (_top > 0) {
            return _rep[--_top];
        } else {
            throw std::underflow_error("Stack underflow");
        }
    }
    bool is_empty() const { return _top == 0; }
};

template<int N>
class Stack<double, N> {
    double _rep[N];
    unsigned int _top;
public:
    Stack() : _top(0) {}
    void push(double e) {
        if (_top < N) {
            _rep[_top++] = e;
        } else {
            throw std::overflow_error("Stack overflow");
        }
    }
    double pop() {
        if (_top > 0) {
            return _rep[--_top];
        } else {
            throw std::underflow_error("Stack underflow");
        }
    }
    bool is_empty() const { return _top == 0; }
};

template<int N>
class Stack<int*, N> {
    int* _rep[N];
    unsigned int _top;
public:
    Stack() : _top(0) {}
    void push(int* e) {
        if (_top < N) {
            _rep[_top++] = e;
        } else {
            throw std::overflow_error("Stack overflow");
        }
    }
    int* pop() {
        if (_top > 0) {
            return _rep[--_top];
        } else {
            throw std::underflow_error("Stack underflow");
        }
    }
    bool is_empty() const { return _top == 0; }
};

template<>
class Stack<double, 666> {
    double _rep[666];
    unsigned int _top;
public:
    Stack() : _top(0) {}
    void push(double e) {
        if (_top < 666) {
            _rep[_top++] = e;
        } else {
            throw std::overflow_error("Stack overflow");
        }
    }
    double pop() {
        if (_top > 0) {
            return _rep[--_top];
        } else {
            throw std::underflow_error("Stack underflow");
        }
    }
    bool is_empty() const { return _top == 0; }
};

template<>
class Stack<double*, 44> {
    double* _rep[44];
    unsigned int _top;
public:
    Stack() : _top(0) {}
    void push(double* e) {
        if (_top < 44) {
            _rep[_top++] = e;
        } else {
            throw std::overflow_error("Stack overflow");
        }
    }
    double* pop() {
        if (_top > 0) {
            return _rep[--_top];
        } else {
            throw std::underflow_error("Stack underflow");
        }
    }
    bool is_empty() const { return _top == 0; }
};

int main() {
    try {
        Stack<int, 666> stackInt;
        stackInt.push(42);
        std::cout << "Popped from Stack<int, 666>: " << stackInt.pop() << std::endl;

        int a = 10, b = 20;
        Stack<int*, 5> stackIntPtr;
        stackIntPtr.push(&a);
        stackIntPtr.push(&b);
        std::cout << "Popped from Stack<int*, 5>: " << *stackIntPtr.pop() << std::endl;

        Stack<double, 5> stackDouble;
        stackDouble.push(3.14);
        std::cout << "Popped from Stack<double, 5>: " << stackDouble.pop() << std::endl;

        int x = 30, y = 40;
        Stack<int*, 5> stackIntPtr2;
        stackIntPtr2.push(&x);
        stackIntPtr2.push(&y);
        std::cout << "Popped from Stack<int*, 5>: " << *stackIntPtr2.pop() << std::endl;

        Stack<double, 666> stackDouble666;
        stackDouble666.push(6.28);
        std::cout << "Popped from Stack<double, 666>: " << stackDouble666.pop() << std::endl;

        double* p1 = new double(1.23), *p2 = new double(4.56);
        Stack<double*, 44> stackDoublePtr;
        stackDoublePtr.push(p1);
        stackDoublePtr.push(p2);
        std::cout << "Popped from Stack<double*, 44>: " << *stackDoublePtr.pop() << std::endl;
        delete p1;
        delete p2;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}