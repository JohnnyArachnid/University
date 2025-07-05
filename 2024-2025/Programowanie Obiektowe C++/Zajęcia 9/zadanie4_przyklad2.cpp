#include <iostream>
#include <string>
#include <memory>

template <class T>
std::unique_ptr<T[]> make_unique(std::size_t size);

int main() {
    auto array = std::make_unique<int[]>(10);

    for (int i = 0; i < 10; ++i) {
        array[i] = i * 10;
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }

    return 0;
}
