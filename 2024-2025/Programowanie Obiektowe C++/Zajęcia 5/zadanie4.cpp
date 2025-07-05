#include <iostream>

template<typename T, typename U>
class Is_convertible {
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

template<typename T>
struct Strip {
    typedef T arg_t;
    typedef T striped_t;
    typedef T base_t;
    typedef const T const_type;

    typedef T& ref_type;
    typedef T& ref_base_type;
    typedef const T& const_ref_type;
};

template<typename T>
struct Strip<const T> {
    typedef const T arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef T const const_type;

    typedef T const& ref_type;
    typedef T& ref_base_type;
    typedef T const& const_ref_type;
};

template<typename T>
struct Strip<T&> {
    typedef T& arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef base_t const const_type;

    typedef T ref_type;
    typedef base_t& ref_base_type;
    typedef base_t const& const_ref_type;
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "Is_convertible<Strip<const int&>::base_t, int> same_type? "
              << Is_convertible<Strip<const int&>::base_t, int>::same_type << "\n";

    std::cout << "Is_convertible<Strip<const int&>::base_t, const int> same_type? "
              << Is_convertible<Strip<const int&>::base_t, const int>::same_type << "\n";

    return 0;
}