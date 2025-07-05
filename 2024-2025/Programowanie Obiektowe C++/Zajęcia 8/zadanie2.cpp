#include <iostream>
#include <cmath>

struct Variable {
    double operator()(double x) const {
        return x;
    }
};

struct Constant {
    double value;
    
    Constant(double v) : value(v) {}

    double operator()(double x) const {
        return value;
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
    Variable x;
    std::cout << "Całka z Variable(x) w przedziale [0, 1]: " << integrate(x, 0.0, 1.0, 0.001) << std::endl;

    std::cout << "Całka z Constant(1.0) w przedziale [0, 1]: " << integrate(Constant(1.0), 0.0, 1.0, 0.001) << std::endl;

    return 0;

}
