# Projekt: Trzy programy w Fortranie - Daniel Szarek

## Opis
Projekt zawiera trzy programy napisane w języku Fortran, które realizują różne zadania:

1. **Kalkulator średnich** - Program do obliczania średnich arytmetycznych, geometrycznych i harmonicznych na podstawie wprowadzonych danych.
2. **Statystyki wielomianu stopnia 2** - Program oblicza wartości funkcji kwadratowej w wybranych punktach, jej pochodną w punkcie x = 0, współrzędne wierzchołka paraboli oraz miejsca zerowe równania kwadratowego.
3. **Gra zgadywanie liczby** - Gra komputerowa, w której użytkownik musi zgadnąć liczbę wylosowaną przez komputer. Program oferuje różne poziomy trudności, dostosowując zakres liczb.

## Program 1: kalkulator_srednich

Program oblicza średnie arytmetyczną, geometryczną i harmoniczną na podstawie wprowadzonych przez użytkownika liczb. Obsługuje przypadek, w którym w danych pojawia się zero, co uniemożliwia obliczenie średniej geometrycznej.

**Funkcje:**
- Obliczanie średniej arytmetycznej.
- Obliczanie średniej geometrycznej (obsługuje zero w danych).
- Obliczanie średniej harmonicznej (obsługuje zero w danych).

## Program 2: statystyki_wielomianu_stopnia_2

Program oblicza podstawowe właściwości funkcji kwadratowej ax² + bx + c, takie jak wartości funkcji w punktach x = -10, x = 0 i x = 10, pochodną w punkcie x = 0, współrzędne wierzchołka paraboli oraz miejsca zerowe funkcji.

**Funkcje:**
- Obliczanie wartości funkcji kwadratowej w trzech wybranych punktach.
- Obliczanie pochodnej funkcji kwadratowej w punkcie x = 0.
- Obliczanie współrzędnych wierzchołka paraboli.
- Obliczanie miejsc zerowych funkcji kwadratowej.

## Program 3: gra_zgadywanie_liczby

Program implementuje grę w zgadywanie liczby z poziomami trudności. Użytkownik ma do wyboru trzy poziomy: łatwy, średni i trudny. Gra polega na zgadywaniu liczby przez użytkownika w określonym zakresie.

**Funkcje:**
- Możliwość wyboru poziomu trudności.
- Losowanie liczby przez komputer.
- Gra w zgadywanie liczby z podpowiedziami (czy liczba jest za mała lub za duża).
- Wskaźnik liczby prób.

## Jak uruchomić

1. Skopiuj kod do pliku `.f90` (np. `kalkulator_srednich.f90`).
2. Skompiluj program za pomocą kompilatora Fortran (np. `gfortran`).
3. Uruchom program.

```bash
gfortran kalkulator_srednich.f90 -o kalkulator_srednich
./kalkulator_srednich