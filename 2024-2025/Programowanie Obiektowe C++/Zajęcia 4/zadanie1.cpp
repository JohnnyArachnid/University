#include <iostream>

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char> {
    typedef int sum_type;
};

template <>
struct sum_traits<int> {
    typedef long int sum_type;
};

template <>
struct sum_traits<float> {
    typedef double sum_type;
};

template <>
struct sum_traits<double> {
    typedef double sum_type;
};

template <typename T>
typename sum_traits<T>::sum_type sum(T* begin, T* end) {
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_type(); 
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

int main() {
    char charArr[] = {'1', '2', '3'};
    int intArr[] = {1, 2, 3, 4, 5};
    float floatArr[] = {1.1f, 2.2f, 3.3f};
    double doubleArr[] = {1.1, 2.2, 3.3};

    std::cout << "Sum charArr: " << sum(charArr, charArr + 3) << std::endl;
    std::cout << "Sum intArr: " << sum(intArr, intArr + 3) << std::endl;
    std::cout << "Sum floatArr: " << sum(floatArr, floatArr + 3) << std::endl;
    std::cout << "Sum doubleArr: " << sum(doubleArr, doubleArr + 3) << std::endl;

    return 0;
}