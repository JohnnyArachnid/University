#include <iostream>

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char> {
    typedef int sum_type;
    static sum_type zero() { return 0; }
};

template <>
struct sum_traits<int> {
    typedef long int sum_type;
    static sum_type zero() { return 0; }
};

template <>
struct sum_traits<float> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};

template <>
struct sum_traits<double> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};

struct char_sum_traits {
    typedef char sum_type;
    static sum_type zero() { return 0; }
};

template <typename Traits, typename T>
typename Traits::sum_type sum(T* begin, T* end) {
    typedef typename Traits::sum_type sum_type;
    sum_type total = Traits::zero();
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

template <typename T>
typename sum_traits<T>::sum_type sum(T* begin, T* end) {
    return sum<sum_traits<T>, T>(begin, end);
}

int main() {
    char charArr[] = {'1', '2', '3'};
    int intArr[] = {1, 2, 3};
    float floatArr[] = {1.1f, 2.2f, 3.3f};
    double doubleArr[] = {1.1, 2.2, 3.3};

    std::cout << "Sum charArr (char): " << sum(charArr, charArr + 3) << std::endl;
    std::cout << "Sum charArr (char_sum_traits): " << sum<char_sum_traits>(charArr, charArr + 3) << std::endl;
    std::cout << "Sum intArr: " << sum(intArr, intArr + 3) << std::endl;
    std::cout << "Sum floatArr: " << sum(floatArr, floatArr + 3) << std::endl;
    std::cout << "Sum doubleArr: " << sum(doubleArr, doubleArr + 3) << std::endl;

    return 0;
}