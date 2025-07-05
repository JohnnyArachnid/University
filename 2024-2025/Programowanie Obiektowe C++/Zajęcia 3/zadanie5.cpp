#include <iostream>
#include <set>
#include <functional>

template <typename T>
void print_set(const std::set<T, std::greater<T>>& s) {
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::set<int, std::greater<int>> s;

    s.insert(5);
    s.insert(10);
    s.insert(2);
    s.insert(8);
    s.insert(1);

    std::cout << "Zbior posortowany malejaco: ";
    print_set(s);

    s.insert(10);

    std::cout << "Zbior po probie dodania duplikatu (10): ";
    print_set(s);

    return 0;
}