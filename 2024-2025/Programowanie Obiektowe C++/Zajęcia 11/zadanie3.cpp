#include <iostream>
#include <vector>
#include <concepts>

template<typename T>
class MyVector {
private:
    std::vector<T> data;
public:
    void push_back(const std::copyable auto& value) {
        data.push_back(value);
    }
    void print() const {
        for (const auto& el : data)
            std::cout << el << " ";
        std::cout << "\n";
    }
};

class NoCopy {
public:
    NoCopy(int v) : value(v) {}

    NoCopy(const NoCopy&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;

    friend std::ostream& operator<<(std::ostream& os, const NoCopy& obj) {
        return os << obj.value;
    }
private:
    int value;
};

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.print();

    MyVector<NoCopy> vecNoCopy;

    NoCopy a(5);
    //vecNoCopy.push_back(a);  // UWAGA: błąd kompilacji!

    return 0;
}
