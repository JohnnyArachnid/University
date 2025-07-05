#ifndef KOLOR_H
#define KOLOR_H

#include <iostream>

struct Kolor {
    int r, g, b;

    Kolor(int r_ = 0, int g_ = 0, int b_ = 0) : r(r_), g(g_), b(b_) {}

    friend std::ostream& operator<<(std::ostream& os, const Kolor& k) {
        os << "(" << k.r << "," << k.g << "," << k.b << ")";
        return os;
    }
};

#endif
