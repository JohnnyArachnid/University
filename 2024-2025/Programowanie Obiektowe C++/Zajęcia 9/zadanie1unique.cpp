#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr1 = std::make_unique<int>(10);

    std::cout << "ptr1: " << *ptr1 << std::endl;

    std::unique_ptr<int> ptr2 = std::move(ptr1);

    if (!ptr1) {
        std::cout << "ptr1 juz niczego nie wskazuje.\n";
    }

    std::cout << "ptr2: " << *ptr2 << std::endl;
}


