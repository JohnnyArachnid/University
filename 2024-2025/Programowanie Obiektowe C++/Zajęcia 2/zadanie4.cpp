#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class SequenceGen {
private:
    int current;
public:
    SequenceGen() : current(1) {}

    int operator()() {
        int value = current;
        current += 2;
        return value;
    }
};

int main() {
    std::vector<int> numbers(20);

    std::generate_n(numbers.begin(), 20, SequenceGen());

    std::cout << "Sekwencja liczb nieparzystych: ";
    for (int num : numbers)
        std::cout << num << " ";
    std::cout << std::endl;

    auto it = std::find_if(numbers.begin(), numbers.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4));

    if (it != numbers.end()) {
        std::cout << "Pierwszy element wiekszy od 4: " << *it << std::endl;
    } else {
        std::cout << "Nie znaleziono elementu większego od 4." << std::endl;
    }

    return 0;
}