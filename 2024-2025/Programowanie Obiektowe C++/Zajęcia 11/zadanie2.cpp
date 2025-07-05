#include <iostream>
#include <compare>
#include <concepts>

struct Point {
    int x, y;
    auto operator<=>(const Point& other) const = default;
};

template<std::three_way_comparable T>
void compare_and_print(const T& a, const T& b) {
    auto cmp = a <=> b;
    if (cmp < 0)
        std::cout << "a < b\n";
    else if (cmp > 0)
        std::cout << "a > b\n";
    else
        std::cout << "a == b\n";
}

struct NoCompare {
    int val;
};

int main() {
    Point p1{1, 2};
    Point p2{2, 3};
    
    compare_and_print(p1, p2);

    NoCompare nc1{1};
    NoCompare nc2{2};

    // compare_and_print(nc1, nc2);  // UWAGA: błąd kompilacji!

    return 0;
}

