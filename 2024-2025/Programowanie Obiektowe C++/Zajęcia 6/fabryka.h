#ifndef FABRYKA_H
#define FABRYKA_H

#include <map>
#include <string>
#include <stdexcept>
#include "kolor.h"

class PolitykaWyjatek {
public:
    Kolor nieznanyKolor(const std::string& nazwa) {
        throw std::runtime_error("Nieznany kolor: " + nazwa);
    }
};

class PolitykaDomyslnaSzary {
public:
    Kolor nieznanyKolor(const std::string& nazwa) {
        return Kolor(128, 128, 128);
    }
};

template <class Polityka>
class FabrykaKolorow : public Polityka {
    std::map<std::string, Kolor> baza;
public:
    FabrykaKolorow() {
        baza["czarny"] = Kolor(0, 0, 0);
        baza["zielony"] = Kolor(0, 255, 0);
    }
    Kolor zwrocKolor(const std::string& nazwa) {
        auto it = baza.find(nazwa);
        if (it != baza.end())
            return it->second;
        return this->nieznanyKolor(nazwa);
    }
};

#endif
