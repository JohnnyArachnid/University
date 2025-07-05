#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> result(data.size());

    std::transform(std::execution::par, data.begin(), data.end(), result.begin(),
                   [](int x) {
                       return x * x;
                   });

    std::cout << "Zmodyfikowane wartości:\n";
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
