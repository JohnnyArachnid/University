#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);

    std::cout << "ptr1: " << *ptr1 << std::endl;

    std::shared_ptr<int> ptr2 = ptr1;

    std::cout << "Liczba wlascicieli: " << ptr1.use_count() << std::endl;

    ptr1.reset();

    std::cout << "ptr2: " << *ptr2 << std::endl;
    std::cout << "Liczba wlascicieli: " << ptr2.use_count() << std::endl;
}
