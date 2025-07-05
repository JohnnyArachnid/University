#include <iostream>
#include <vector>
#include <execution>
#include <cmath>
#include <chrono>

int main() {
    std::vector<double> input(100'000'000, 9.0);
    std::vector<double> output(input.size());

    auto start_seq = std::chrono::high_resolution_clock::now();
    std::transform(std::execution::seq, input.begin(), input.end(), output.begin(),
        [](double x) { return std::log(x); });
    auto end_seq = std::chrono::high_resolution_clock::now();

    auto start_par = std::chrono::high_resolution_clock::now();
    std::transform(std::execution::par, input.begin(), input.end(), output.begin(),
        [](double x) { return std::log(x); });
    auto end_par = std::chrono::high_resolution_clock::now();

    std::cout << "Czas wykonania (par): " << std::chrono::duration<double>(end_par - start_par).count() << " s\n";
    std::cout << "Czas wykonania (seq): " << std::chrono::duration<double>(end_seq - start_seq).count() << " s\n";

    return 0;
}