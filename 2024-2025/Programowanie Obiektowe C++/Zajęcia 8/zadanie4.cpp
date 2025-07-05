#include <iostream>
#include <cmath>

struct Variable {
    double operator()(double x) const {
        return x;
    }
};

struct Constant {
    double _c;
    Constant(double c) : _c(c) {}
    double operator()(double) const {
        return _c;
    }
};

template<typename LHS, typename RHS>
class AddExpr {
    LHS _lhs;
    RHS _rhs;
public:
    AddExpr(const LHS& l, const RHS& r) : _lhs(l), _rhs(r) {}
    double operator()(double x) const {
        return _lhs(x) + _rhs(x);
    }
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
    double operator()(double x) const {
        return _lhs(x) / _rhs(x);
    }
};

template<typename LHS, typename RHS>
DivExpr<LHS, RHS> operator/(const LHS& l, const RHS& r) {
    return DivExpr<LHS,RHS>(l,r);
}

template<typename LHS>
DivExpr<LHS, Constant> operator/(const LHS& l, double r) {
    return DivExpr<LHS, Constant>(l, Constant(r));
}

template<typename RHS>
DivExpr<Constant, RHS> operator/(double l, const RHS& r) {
    return DivExpr<Constant, RHS>(Constant(l), r);
}


template<typename F>
class SinExpr {
    F _f;
public:
    SinExpr(const F& f) : _f(f) {}
    double operator()(double x) const {
        return std::sin(_f(x));
    }
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


int main() {
    Variable x;
    auto expr = 1. / sin(x + 1.0);
    std::cout << "integrate(1 / sin(x + 1), 0, 1): "<< integrate(expr, 0.0, 1.0, 0.001) << std::endl;
    return 0;
}
