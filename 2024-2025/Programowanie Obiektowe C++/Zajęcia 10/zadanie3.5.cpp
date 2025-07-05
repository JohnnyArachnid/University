#include <iostream>
#include <vector>
#include <numeric>
#include <execution>
#include <chrono>

int main() {
    std::vector<int> data(100'000'000);
    std::iota(data.begin(), data.end(), 1);

    auto data_seq = data;

    auto start_seq = std::chrono::high_resolution_clock::now();
    std::partition(std::execution::seq, data_seq.begin(), data_seq.end(),
        [](int x) { return x % 2 == 0; });
    auto end_seq = std::chrono::high_resolution_clock::now();

    auto data_par = data;

    auto start_par = std::chrono::high_resolution_clock::now();
    std::partition(std::execution::par, data_par.begin(), data_par.end(),
        [](int x) { return x % 2 == 0; });
    auto end_par = std::chrono::high_resolution_clock::now();

    // Wyniki
    std::cout << "Czas wykonania (par): " << std::chrono::duration<double>(end_par - start_par).count() << " s\n";
    std::cout << "Czas wykonania (seq): " << std::chrono::duration<double>(end_seq - start_seq).count() << " s\n";

    return 0;
}