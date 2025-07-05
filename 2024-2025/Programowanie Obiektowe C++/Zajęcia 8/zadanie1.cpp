#include <iostream>
#include <cmath>

struct sina {
    double a;
    
    sina(double a_) : a(a_) {}

    double operator()(double x) const {
        return std::sin(a * x);
    }
};

template <typename F>
double integrate(F f, double min, double max, double ds) {
    double integral = 0.0;
    for (double x = min; x < max; x += ds) {
        integral += f(x);
    }
    return integral * ds;
}

int main() {
    std::cout << ::integrate(sina(0), 0, 3.1415926, 0.01) << std::endl;
    std::cout << ::integrate(sina(1), 0, 3.1415926, 0.01) << std::endl;
    std::cout << ::integrate(sina(2), 0, 3.1415926, 0.01) << std::endl;
}
