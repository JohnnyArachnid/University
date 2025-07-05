#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>

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

template <typename IT>
typename sum_traits<typename std::iterator_traits<IT>::value_type>::sum_type
sum(IT begin, IT end) {
    typedef typename std::iterator_traits<IT>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;
    sum_type total = sum_traits<value_type>::zero(); 
    while (begin != end) { 
        total += *begin; 
        ++begin; 
    }
    return total; 
}

int main() {
    char charArr[] = {'1', '2', '3'};
    int intArr[] = {1, 2, 3};
    float floatArr[] = {1.1f, 2.2f, 3.3f};
    double doubleArr[] = {1.1, 2.2, 3.3};

    std::cout << "Sum charArr: " << sum(charArr, charArr + 3) << std::endl;
    std::cout << "Sum intArr: " << sum(intArr, intArr + 3) << std::endl;
    std::cout << "Sum floatArr: " << sum(floatArr, floatArr + 3) << std::endl;
    std::cout << "Sum doubleArr: " << sum(doubleArr, doubleArr + 3) << std::endl;

    std::vector<char> vec = {'1', '2', '3'};
    std::list<float> lst = {1.1f, 2.2f, 3.3f};
    std::deque<double> deq = {1.1, 2.2, 3.3};

    std::cout << "Sum vector<int>: " << sum(vec.begin(), vec.end()) << std::endl;
    std::cout << "Sum list<float>: " << sum(lst.begin(), lst.end()) << std::endl;
    std::cout << "Sum deque<double>: " << sum(deq.begin(), deq.end()) << std::endl;

    return 0;
}
