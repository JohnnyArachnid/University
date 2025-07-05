#include <iostream>
#include <stdexcept>

class No_checking_policy {
public:
    void check_push(size_t current_size, size_t max_size) {}
    void check_pop(size_t current_size) {}
    void check_top(size_t current_size) {}
};

class Abort_on_error_policy {
public:
    void check_push(size_t current_size, size_t max_size) const {
        if (current_size >= max_size) {
            std::cerr << "Error: Stack overflow!" << std::endl;
            std::abort();
        }
    }
    void check_pop(size_t current_size) const {
        if (current_size == 0) {
            std::cerr << "Error: Stack underflow!" << std::endl;
            std::abort();
        }
    }
    void check_top(size_t current_size) const {
        if (current_size == 0) {
            std::cerr << "Error: Stack is empty!" << std::endl;
            std::abort();
        }
    }
};

template<typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy>
class Stack {
private:
    T _rep[N];
    size_t _top;
    Checking_policy policy;

public:
    Stack() : _top(0) {}

    void push(const T& element) {
        policy.check_push(_top, N);
        _rep[_top++] = element;
    }

    void pop() {
        policy.check_pop(_top);
        --_top;
    }

    T top() const {
        policy.check_top(_top);
        return _rep[_top - 1];
    }

    bool is_empty() const {
        return _top == 0;
    }

    size_t size() const {
        return _top;
    }
};

int main() {
    Stack<int, 5, Abort_on_error_policy> stack;

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Top element: " << stack.top() << std::endl;

        stack.pop();
        std::cout << "Top element after pop: " << stack.top() << std::endl;

        stack.pop();
        stack.pop();
        stack.pop();

    } catch (const std::exception& e) {
        std::cout << "Zlapano wyjatek: " << e.what() << "\n";
    }

    return 0;
}