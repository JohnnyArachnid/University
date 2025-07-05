#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> data(10, 5);

    std::fill(std::execution::par_unseq, data.begin(), data.end(), 0);

    std::cout << "Po wypelnieniu:\n";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
