#include <iostream>
#include <vector>
#include <numeric>
#include <execution>
#include <chrono>

int main() {
    std::vector<int> data(100'000'000, 1);
    std::vector<int> prefix(data.size());

    auto start_seq = std::chrono::high_resolution_clock::now();
    std::exclusive_scan(std::execution::seq, data.begin(), data.end(), prefix.begin(), 0);
    auto end_seq = std::chrono::high_resolution_clock::now();

    auto start_par = std::chrono::high_resolution_clock::now();
    std::exclusive_scan(std::execution::par, data.begin(), data.end(), prefix.begin(), 0);
    auto end_par = std::chrono::high_resolution_clock::now();

    std::cout << "Czas wykonania (par): " << std::chrono::duration<double>(end_par - start_par).count() << " s\n";
    std::cout << "Czas wykonania (seq): " << std::chrono::duration<double>(end_seq - start_seq).count() << " s\n";

    return 0;
}