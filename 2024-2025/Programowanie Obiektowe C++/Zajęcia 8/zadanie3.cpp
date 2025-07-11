#include <iostream>

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

  double operator()(double x) {
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

  std::cout << "integrate(x + 1.0, 0, 1): "
            << integrate(x + 1.0, 0.0, 1.0, 0.001) << "\n";

  std::cout << "integrate(2.0 + x, 0, 1): "
            << integrate(2.0 + x, 0.0, 1.0, 0.001) << "\n";

  std::cout << "integrate(x + x, 0, 1): "
            << integrate(x + x, 0.0, 1.0, 0.001) << "\n";

  return 0;
}
