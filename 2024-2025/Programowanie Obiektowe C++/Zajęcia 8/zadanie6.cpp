#include <iostream>
#include <cmath>


struct Variable {
    double operator()(double x) const { return x; }
};

struct First {
    double operator()(double x) const { return x; }
    double operator()(double x, double) const { return x; }
};

struct Second {
    double operator()(double, double y) const { return y; }
};

struct Constant {
    double _c;
    Constant(double c) : _c(c) {}
    double operator()(double) const { return _c; }
    double operator()(double, double) const { return _c; }
};


template<typename LHS, typename RHS>
class AddExpr {
    LHS _lhs;
    RHS _rhs;
public:
    AddExpr(const LHS& l, const RHS& r) : _lhs(l), _rhs(r) {}
    double operator()(double x) const { return _lhs(x) + _rhs(x); }
    double operator()(double x, double y) const { return _lhs(x, y) + _rhs(x, y); }
};

template<typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS& l, const RHS& r) {
    return AddExpr<LHS, RHS>(l, r);
}

template<typename LHS>
AddExpr<LHS, Constant> operator+(const LHS& l, double r) {
    return AddExpr<LHS, Constant>(l, Constant(r));
}

template<typename RHS>
AddExpr<Constant, RHS> operator+(double l, const RHS& r) {
    return AddExpr<Constant, RHS>(Constant(l), r);
}


template<typename LHS, typename RHS>
class DivExpr {
    LHS _lhs;
    RHS _rhs;
public:
    DivExpr(const LHS& l, const RHS& r) : _lhs(l), _rhs(r) {}
    double operator()(double x) const { return _lhs(x) / _rhs(x); }
    double operator()(double x, double y) const { return _lhs(x, y) / _rhs(x, y); }
};

template<typename RHS>
DivExpr<Constant, RHS> operator/(double l, const RHS& r) {
    return DivExpr<Constant, RHS>(Constant(l), r);
}


template<typename F>
class SinExpr {
    F _f;
public:
    SinExpr(const F& f) : _f(f) {}
    double operator()(double x) const { return std::sin(_f(x)); }
    double operator()(double x, double y) const { return std::sin(_f(x, y)); }
};

template<typename F>
SinExpr<F> sin(const F& f) {
    return SinExpr<F>(f);
}


template<typename F>
double integrate(F f, double min, double max, double ds) {
    double result = 0.0;
    for (double x = min; x < max; x += ds) {
        result += f(x);
    }
    return result * ds;
}

template<typename F>
double integrate2d(F f, double x_min, double x_max, double y_min, double y_max, double dx, double dy) {
    double result = 0.0;
    for (double x = x_min; x < x_max; x += dx) {
        for (double y = y_min; y < y_max; y += dy) {
            result += f(x, y);
        }
    }
    return result * dx * dy;
}


int main() {
    Variable x;
    auto expr1 = 1. / sin(x + 1.0);
    std::cout << "integrate(1 / sin(x + 1), 0, 1): "
              << integrate(expr1, 0.0, 1.0, 0.001) << std::endl;

    First x2;
    Second y2;
    auto expr2 = x2 + y2;
    std::cout << "integrate2d(x + y, 0, 1, 0, 1): "
              << integrate2d(expr2, 0.0, 1.0, 0.0, 1.0, 0.01, 0.01) << std::endl;

    return 0;
}
