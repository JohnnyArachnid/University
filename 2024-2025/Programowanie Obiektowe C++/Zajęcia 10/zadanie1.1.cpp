#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4};

    std::for_each(std::execution::seq, v.begin(), v.end(), [](int n) {
        std::cout << n << " ";
    });
}

