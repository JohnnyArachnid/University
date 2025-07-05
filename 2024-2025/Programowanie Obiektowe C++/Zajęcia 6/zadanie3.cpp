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

template<typename T, size_t N = 0>
struct Static_table_allocator {
    typedef T rep_type[N];

    void init(rep_type&, size_t) {}
    void expand_if_needed(rep_type&, size_t) {}
    void shrink_if_needed(rep_type&, size_t) {}
    void dealocate(rep_type&) {}

    static size_t size() { return N; }
};

template<typename T>
struct Dynamic_table_allocator {
    typedef T* rep_type;
    size_t _size;

    void init(rep_type& rep, size_t n) {
        _size = n;
        rep = new T[_size];
    }

    void expand_if_needed(rep_type& rep, size_t top) {
        if (top == _size) {
            _size *= 2;
            T* tmp = new T[_size];
            std::copy(rep, rep + top, tmp);
            delete[] rep;
            rep = tmp;
        }
    }

    void shrink_if_needed(rep_type&, size_t) {}

    void dealocate(rep_type& rep) {
        delete[] rep;
    }

    size_t size() const { return _size; }
};

template<typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy, template<typename U> class Allocator_policy = Static_table_allocator>
class Stack {
private:
    typedef typename Allocator_policy<T>::rep_type rep_type;
    rep_type _rep;
    size_t _top;
    Checking_policy policy;
    Allocator_policy<T> alloc;

public:
    Stack(size_t n = N) : _top(0) {
        alloc.init(_rep, n);
    }

    void push(const T& element) {
        policy.check_push(_top, alloc.size());
        _rep[_top++] = element;
        alloc.expand_if_needed(_rep, _top);
    }

    void pop() {
        policy.check_pop(_top);
        --_top;
        alloc.shrink_if_needed(_rep, _top);
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

    ~Stack() {
        alloc.dealocate(_rep);
    }
};

int main() {
    Stack<int, 2, Abort_on_error_policy, Dynamic_table_allocator> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element after pushing 3 elements: " << stack.top() << std::endl;

    return 0;
}
