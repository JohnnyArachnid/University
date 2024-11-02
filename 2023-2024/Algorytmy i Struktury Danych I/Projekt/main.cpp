// Autor: Daniel Szarek
//=====================
#include "poly.h"

// Zmienne do testów

const int coefficients1[] = {1, 2, 3};
const int coefficients2[] = {-4, 0, 6};
const int size = 3;
const Poly<int> polyDefault;
const Poly<int> polySize(size);
const Poly<int> polyCoefficients1(coefficients1, size);
const Poly<int> polyCoefficients2(coefficients2, size);
const Poly<int> polyCopy(polyCoefficients1);

// Testy

bool konstruktor_domyslny_test() {
    return polyDefault.is_zero();
}

bool konstruktor_rozmiar_test() {
    return polySize.is_zero() && polySize.degree() == 2;
}

bool konstruktor_tablicy_współczynnikow_i_rozmiaru_test() {
    return (!polyCoefficients1.is_zero() && polyCoefficients2[2] == 6);
}

bool konstruktor_kopiujacy_test() {
    return polyCopy == polyCoefficients1;
}

bool operator1_test() {
    Poly<int> polyTemp1 = polyCoefficients1 + polyDefault;
    Poly<int> polyTemp2 = polyCoefficients2 + polySize;
    Poly<int> polyTemp3 = polyCoefficients1 + polyCoefficients2;
    if (polyTemp3[0] != -3) { return false; }
    if (polyTemp3[1] != 2) { return false; }
    if (polyTemp3[2] != 9) { return false; }
    return polyTemp1 == polyCoefficients1 && polyTemp2 == polyCoefficients2; 
}

bool operator2_test() {
    Poly<int> polyTemp1(polyCoefficients1);
    Poly<int> polyTemp2(polyCoefficients2);
    polyTemp1 += polyDefault;
    if (polyTemp1 != polyCoefficients1) { return false; }
    polyTemp2 += polySize;
    if (polyTemp2 != polyCoefficients2) { return false; }
    polyTemp1 += polyTemp2;
    if (polyTemp1[0] != -3) { return false; }
    if (polyTemp1[1] != 2) { return false; }
    if (polyTemp1[2] != 9) { return false; }
    return true;
    
}

bool operator3_test() {
    Poly<int> polyTemp1 = polyCoefficients1 - polyDefault;
    Poly<int> polyTemp2 = polyCoefficients2 - polySize;
    Poly<int> polyTemp3 = polyCoefficients1 - polyCoefficients2;
    if (polyTemp3[0] != 5) { return false; }
    if (polyTemp3[1] != 2) { return false; }
    if (polyTemp3[2] != -3) { return false; }
    return polyTemp1 == polyCoefficients1 && polyTemp2 == polyCoefficients2;
}

bool operator4_test() {
    Poly<int> polyTemp1(polyCoefficients1);
    Poly<int> polyTemp2(polyCoefficients2);
    polyTemp1 -= polyDefault;
    if (polyTemp1 != polyCoefficients1) { return false; }
    polyTemp2 -= polySize;
    if (polyTemp2 != polyCoefficients2) { return false; }
    polyTemp1 -= polyTemp2;
    if (polyTemp1[0] != 5) { return false; }
    if (polyTemp1[1] != 2) { return false; }
    if (polyTemp1[2] != -3) { return false; }
    return true;   
}

bool operator5_test() {
    Poly<int> polyTemp1 = polyCoefficients1 * polyDefault;
    Poly<int> polyTemp2 = polyCoefficients2 * polySize;
    Poly<int> polyTemp3 = polyCoefficients1 * polyCoefficients2;
    if (polyTemp3[0] != -4) { return false; }
    if (polyTemp3[1] != -8) { return false; }
    if (polyTemp3[2] != -6) { return false; }
    if (polyTemp3[3] != 12) { return false; }
    if (polyTemp3[4] != 18) { return false; }
    return polyTemp1.is_zero() && polyTemp2.is_zero();
}

bool operator6_test() {
    Poly<int> polyTemp1(polyCoefficients1);
    Poly<int> polyTemp2(polyCoefficients2);
    polyTemp1 *= polyDefault;
    if (!(polyTemp1.is_zero())) { return false; }
    polyTemp2 *= polySize;
    if (!(polyTemp2.is_zero())) { return false; }
    polyTemp1 = polyCoefficients1;
    polyTemp1 *= polyCoefficients2;
    if (polyTemp1[0] != -4) { return false; }
    if (polyTemp1[1] != -8) { return false; }
    if (polyTemp1[2] != -6) { return false; }
    if (polyTemp1[3] != 12) { return false; }
    if (polyTemp1[4] != 18) { return false; }
    return true;  
}

bool operator7_test() {
    Poly<int> polyTemp1 = polyDefault;
    Poly<int> polyTemp2 = polySize;
    Poly<int> polyTemp3 = polyCoefficients1;
    return polyTemp1 == polyDefault && polyTemp2 == polySize && polyTemp3 == polyCoefficients1;
}

bool operator8_test() {
    return polyCoefficients1[0] == 1 && polyCoefficients2[1] == 0 && polySize[2] == 0;
}

bool operator9_test() {
    return konstruktor_kopiujacy_test();
}

bool operator10_test() {
    return polyCoefficients1 != polyCoefficients2 && polyDefault != polyCopy;
}

bool algorytmHornera_test() {
    return polyCoefficients1.algorytmHornera(2) == 17 && polyCoefficients2.algorytmHornera(-1) == 2 && polyDefault.algorytmHornera(0) == 0 && polySize.algorytmHornera(3) == 0;
}

bool clear_test() {
    Poly<int> polyTemp1 = polyDefault;
    Poly<int> polyTemp2 = polySize;
    Poly<int> polyTemp3 = polyCoefficients1;
    polyTemp1.clear();
    polyTemp2.clear();
    polyTemp3.clear();
    return polyTemp1.is_zero() && polyTemp2.is_zero() && polyTemp3.is_zero();
}

bool is_zero_test() {
    return !(polyCoefficients1.is_zero()) && polyDefault.is_zero() && polySize.is_zero();
}

void wyswietlanie_test() {
    polyDefault.wyswietlanie(); // Powinno wyświetlić: Wielomian pusty
    polySize.wyswietlanie(); // Powinno wyświetlić: Wielomian pusty
    polyCoefficients1.wyswietlanie(); // Powinno wyświetlić: 3x^2+2x^1+1
    polyCoefficients2.wyswietlanie(); // Powinno wyświetlić: 6x^2-4
}

void assert_test(bool wynik, const char* nazwaTestu) {
    std::cout << "Test: " << nazwaTestu << " : " << wynik << std::endl;
    assert(wynik);
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    std::cout << "Witaj w programie implementacji wielomianu na bazie tablic!" << std::endl << "(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)" << std::endl << std::endl;
    sleep(2);
    assert_test(konstruktor_domyslny_test(), "konstruktora domyslnego");
    assert_test(konstruktor_rozmiar_test(), "konstruktora rozmiaru");
    assert_test(konstruktor_tablicy_współczynnikow_i_rozmiaru_test(), "konstruktora tablicy wspolczynnikow i rozmiaru");
    assert_test(konstruktor_kopiujacy_test(), "konstruktora kopiujacego");
    assert_test(operator1_test(), "operatora +");
    assert_test(operator2_test(), "operatora +=");
    assert_test(operator3_test(), "operatora -");
    assert_test(operator4_test(), "operatora -=");
    assert_test(operator5_test(), "operatora *");
    assert_test(operator6_test(), "operatora *=");
    assert_test(operator7_test(), "operatora =");
    assert_test(operator8_test(), "operatora []");
    assert_test(operator9_test(), "operatora = (kopiujacy)");
    assert_test(operator10_test(), "operatora !=");
    assert_test(algorytmHornera_test(), "algorytmuHornera");
    assert_test(clear_test(), "clear");
    assert_test(is_zero_test(), "is_zero");
    wyswietlanie_test();
    return 0;
}
