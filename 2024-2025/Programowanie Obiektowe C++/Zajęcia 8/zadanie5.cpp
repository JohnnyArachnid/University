#include <iostream>
#include <cmath>

template<typename T, typename R>
class Expr {
  R _rep;
public:
  Expr() {}
  Expr(R rep) : _rep(rep) {}

  T operator()(T x) const {
    return _rep(x);
  }

  R rep() const { return _rep; }
};

template<typename T>
struct Variable {
  T operator()(T x) const {
    return x;
  }
};

template<typename T>
struct Constant {
  T _c;
  Constant(T c) : _c(c) {}

  T operator()(T x) const {
    return _c;
  }
};


template<typename T, typename LHS, typename RHS>
class AddExpr {
  LHS _lhs;
  RHS _rhs;

public:
  AddExpr(const LHS& l, const RHS& r) : _lhs(l), _rhs(r) {}

  T operator()(T x) const {
    return _lhs(x) + _rhs(x);
  }
};

template<typename T, typename LHS, typename RHS>
Expr<T, AddExpr<T, LHS, RHS>> operator+(const Expr<T, LHS>& l, const Expr<T, RHS>& r) {
  return Expr<T, AddExpr<T, LHS, RHS>>(AddExpr<T, LHS, RHS>(l.rep(), r.rep()));
}

template<typename T, typename LHS>
Expr<T, AddExpr<T, LHS, Constant<T>>> operator+(const Expr<T, LHS>& l, T r) {
  return Expr<T, AddExpr<T, LHS, Constant<T>>>(AddExpr<T, LHS, Constant<T>>(l.rep(), Constant<T>(r)));
}

template<typename T, typename RHS>
Expr<T, AddExpr<T, Constant<T>, RHS>> operator+(T l, const Expr<T, RHS>& r) {
  return Expr<T, AddExpr<T, Constant<T>, RHS>>(AddExpr<T, Constant<T>, RHS>(Constant<T>(l), r.rep()));
}

template<typename T>
struct SinExpr {
  T operator()(T x) const {
    return std::sin(x);
  }
};


template<typename T, typename F>
T integrate(F f, T min, T max, T ds) {
  T result = 0.0;
  for (T x = min; x < max; x += ds) {
    result += f(x);
  }
  return result * ds;
}


int main() {
  Variable<double> x;
  std::cout << "integrate(x + 1.0, 0, 1): "
            << integrate<double>(Expr<double, Variable<double>>(x) + 1.0, 0.0, 1.0, 0.001) << "\n";
  std::cout << "integrate(2.0 + x, 0, 1): "
            << integrate<double>(2.0 + Expr<double, Variable<double>>(x), 0.0, 1.0, 0.001) << "\n";

  Variable<float> x_float;
  std::cout << "integrate(x_float + 1.0f, 0, 1): "
            << integrate<float>(Expr<float, Variable<float>>(x_float) + 1.0f, 0.0f, 1.0f, 0.001f) << "\n";
  std::cout << "integrate(2.0f + x_float, 0, 1): "
            << integrate<float>(2.0f + Expr<float, Variable<float>>(x_float), 0.0f, 1.0f, 0.001f) << "\n";

  std::cout << "integrate(1.0 / sin(x + 1.0), 0, 1): "
            << integrate<double>(Expr<double, SinExpr<double>>() + 1.0, 0.0, 1.0, 0.001) << "\n";

  return 0;
}
