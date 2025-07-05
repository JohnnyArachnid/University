#include <iostream>
#include <vector>
#include <execution>
#include <cmath> 
#include <chrono>

int main() {
    std::vector<double> data(100'000'000, 16.0);

    auto start_seq = std::chrono::high_resolution_clock::now();
    std::for_each(std::execution::seq, data.begin(), data.end(),
        [](double& x) { x = std::sqrt(x); });
    auto end_seq = std::chrono::high_resolution_clock::now();

    auto start_par = std::chrono::high_resolution_clock::now();
    std::for_each(std::execution::par, data.begin(), data.end(),
        [](double& x) { x = std::sqrt(x); });
    auto end_par = std::chrono::high_resolution_clock::now();

    std::cout << "Czas wykonania (par): " << std::chrono::duration<double>(end_par - start_par).count() << " s\n";
    std::cout << "Czas wykonania (seq): " << std::chrono::duration<double>(end_seq - start_seq).count() << " s\n";

    return 0;
}