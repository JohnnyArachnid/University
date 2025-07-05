#include <iostream>
#include "kolor.h"
#include "fabryka.h"

int main() {
    FabrykaKolorow<PolitykaWyjatek> fabryka;
    FabrykaKolorow<PolitykaDomyslnaSzary> fabrykaSzara;

    try {
        std::cout << fabryka.zwrocKolor("zielony") << "\n";
        std::cout << fabryka.zwrocKolor("niebieski") << "\n";
    } catch (const std::exception& e) {
        std::cout << "Zlapano wyjatek: " << e.what() << "\n";
    }
    std::cout << fabrykaSzara.zwrocKolor("zielony") << "\n";
    std::cout << fabrykaSzara.zwrocKolor("niebieski") << "\n";
    return 0;
}