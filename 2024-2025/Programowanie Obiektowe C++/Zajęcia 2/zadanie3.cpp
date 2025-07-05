#include <iostream>
#include <vector>
#include <list>
#include <string>

template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init) {
T total=init;
for( ; first != last;++first) 
   total+= *first;
return total;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::list<double> decimals = {1.1, 2.2, 3.3, 4.4};

    int sum_int = accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Suma liczb calkowitych: " << sum_int << std::endl;

    double sum_double = accumulate(decimals.begin(), decimals.end(), 0.0);
    std::cout << "Suma liczb zmiennoprzecinkowych: " << sum_double << std::endl;

    std::vector<std::string> words = {"Hello", " ", "World", "!"};
    std::string sentence = accumulate(words.begin(), words.end(), std::string(""));
    std::cout << "Polaczony string: " << sentence << std::endl;

    return 0;
}
