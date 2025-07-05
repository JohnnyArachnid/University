#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::mutex mtx;

    auto start_par = std::chrono::high_resolution_clock::now();

    std::for_each(std::execution::par, vec.begin(), vec.end(),
                  [&output, &mtx](int elem) {
                      if (elem % 2 == 0) {
                          std::lock_guard<std::mutex> lock(mtx);
                          output.push_back(elem);
                      }
                  });

    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_par = end_par - start_par;
    std::cout << "Czas wykonania (par): " << duration_par.count() << " s" << std::endl;

    output.clear();
    auto start_seq = std::chrono::high_resolution_clock::now();

    std::for_each(std::execution::seq, vec.begin(), vec.end(),
                  [&output](int elem) {
                      if (elem % 2 == 0) {
                          output.push_back(elem);
                      }
                  });

    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_seq = end_seq - start_seq;
    std::cout << "Czas wykonania (seq): " << duration_seq.count() << " s" << std::endl;

    return 0;
}
