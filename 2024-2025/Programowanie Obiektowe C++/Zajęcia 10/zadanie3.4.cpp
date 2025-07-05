#include <iostream>
#include <vector>
#include <numeric>
#include <execution>
#include <chrono>

int main() {
    std::vector<int> data(100'000'000);
    std::iota(data.begin(), data.end(), 0);

    auto start_seq = std::chrono::high_resolution_clock::now();
    auto count_seq = std::count_if(std::execution::seq, data.begin(), data.end(),
        [](int x) { return x % 7 == 0; });
    auto end_seq = std::chrono::high_resolution_clock::now();

    auto start_par = std::chrono::high_resolution_clock::now();
    auto count_par = std::count_if(std::execution::par, data.begin(), data.end(),
        [](int x) { return x % 7 == 0; });
    auto end_par = std::chrono::high_resolution_clock::now();
    
    std::cout << "Czas wykonania (par): " << std::chrono::duration<double>(end_par - start_par).count() << " s\n";
    std::cout << "Czas wykonania (seq): " << std::chrono::duration<double>(end_seq - start_seq).count() << " s\n";

    return 0;
}