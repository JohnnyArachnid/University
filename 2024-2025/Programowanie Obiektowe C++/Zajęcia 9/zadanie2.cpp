#include <iostream>
#include <memory>

int main() {
    std::cout << "Rozmiar int*:            " << sizeof(int*) << " bajtow\n";
    std::cout << "Rozmiar unique_ptr<int>: " << sizeof(std::unique_ptr<int>) << " bajtow\n";
    std::cout << "Rozmiar shared_ptr<int>: " << sizeof(std::shared_ptr<int>) << " bajtow\n";

    return 0;
}