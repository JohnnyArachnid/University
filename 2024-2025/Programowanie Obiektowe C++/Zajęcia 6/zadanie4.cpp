#include <iostream>
#include <stdexcept>
#include <algorithm>

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

template<typename T>
class Dynamic_table_allocator {
public:
    typedef T* rep_type;

protected:
    rep_type _rep = nullptr;
    size_t _size = 0;

public:
    void init(size_t n) {
        _size = n;
        _rep = new T[_size];
    }

    void expand_if_needed(size_t top) {
        if (top >= _size) {
            resize(_size * 2);
        }
    }

    void shrink_if_needed(size_t) {}

    void dealocate() {
        delete[] _rep;
        _rep = nullptr;
    }

    size_t size() const { return _size; }

    void resize(size_t new_size) {
        T* tmp = new T[new_size];
        std::copy(_rep, _rep + (_size < new_size ? _size : new_size), tmp);
        delete[] _rep;
        _rep = tmp;
        _size = new_size;
    }

    rep_type& rep() { return _rep; }
    const rep_type& rep() const { return _rep; }
};

template<typename T = int, size_t N = 100,
         typename Checking_policy = No_checking_policy,
         template<typename U> class Allocator_policy = Dynamic_table_allocator>
class Stack : private Allocator_policy<T> {
private:
    size_t _top;
    Checking_policy policy;

    using Allocator = Allocator_policy<T>;
    using rep_type = typename Allocator::rep_type;

public:
    Stack(size_t n = N) : _top(0) {
        Allocator::init(n);
    }

    void push(const T& element) {
        policy.check_push(_top, Allocator::size());
        Allocator::rep()[_top++] = element;
        Allocator::expand_if_needed(_top);
    }

    void pop() {
        policy.check_pop(_top);
        --_top;
        Allocator::shrink_if_needed(_top);
    }

    T top() const {
        policy.check_top(_top);
        return Allocator::rep()[_top - 1];
    }

    bool is_empty() const {
        return _top == 0;
    }

    size_t size() const {
        return _top;
    }

    void resize(size_t new_size) {
        Allocator::resize(new_size);
    }

    ~Stack() {
        Allocator::dealocate();
    }
};

int main() {
    
    Stack<int, 2, Abort_on_error_policy, Dynamic_table_allocator> stack;

    for (int i = 0; i < 5; ++i) {
        stack.push(i);
        std::cout << "Pushed: " << i << " | Top: " << stack.top() << " | Size: " << stack.size() << "\n";
    }

    stack.resize(20);
    std::cout << "Resized stack to 20\n";

    while (!stack.is_empty()) {
        std::cout << "Popping: " << stack.top() << "\n";
        stack.pop();
    }

    stack.pop();

    return 0;
}