// Autor: Daniel Szarek
//=====================
#include <iostream>
#include <cmath>
#include <chrono>

const double E = 1e-10; //Dokladnosc bledu podana w poleceniu

const long int iteracja = 1e7; //Wartosc iteratora do obliczenia sum obu wzorow

using namespace std;

int main(){
    double suma1 = 0; //Suma dla wzoru z polecenia
    double suma2 = suma1; //Suma dla zoptymalizowanego wzoru
    int x = 1; //Wartosc x=1 z polecenia
    auto begin = std::chrono::high_resolution_clock::now(); //Mierzenie czasu dla pierwotnego wzoru
    for(int i=0;i<iteracja;i++){
        suma1+=pow(sin(i*pow(x,4)),2)*exp(-i)+cos(i*pow(x,4))*exp(-4*i); //Srednio 1.7 sekundy
    }
    auto end = std::chrono::high_resolution_clock::now(); //Mierzenie czasu dla pierwotnego wzoru
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); //Mierzenie czasu dla pierwotnego wzoru
    printf("Wartosc sumy dla pierwotnego wzoru: %.9f\n",suma1);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    begin = std::chrono::high_resolution_clock::now(); //Mierzenie czasu dla drugiej wersji wzoru
    for(int i=0;i<iteracja;i++){
        suma2+=exp(-i)*(1-cos(i*pow(x,4))*(cos(i*pow(x,4))-exp(-3*i))); //Srednio 1.3 sekundy, bardziej optymalna wersja od pierwotnej wzoru
    }
    end = std::chrono::high_resolution_clock::now(); //Mierzenie czasu dla drugiej wersji wzoru
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); //Mierzenie czasu dla drugiej wersji wzoru
    printf("Wartosc sumy dla zoptymalizowanego wzoru: %.9f\n",suma1);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    double pierwsze_wywolanie_funkcji, drugie_wywolanie_funkcji; //Deklaracja funckji dla n oraz n+1
    int licznik_iteracji; //Wartosc n
    for(licznik_iteracji=0;licznik_iteracji<1;licznik_iteracji++) pierwsze_wywolanie_funkcji=exp(-licznik_iteracji)*(1-cos(licznik_iteracji*pow(1,4))*(cos(licznik_iteracji*pow(1,4))-exp(-3*licznik_iteracji))); //Obliczanie wartosci dla f(1) dla n=0
    drugie_wywolanie_funkcji = pierwsze_wywolanie_funkcji + exp(-(licznik_iteracji))*(1-cos((licznik_iteracji)*pow(1,4))*(cos((licznik_iteracji)*pow(1,4))-exp(-3*(licznik_iteracji)))); //Obliczanie wartosci dla f(1) dla n=1
    while(fabs(pierwsze_wywolanie_funkcji-drugie_wywolanie_funkcji) > E) { //Wyznaczenie wartosci maksymalnej N
        pierwsze_wywolanie_funkcji = drugie_wywolanie_funkcji; //Obliczanie wartosci dla f(1) dla n
        licznik_iteracji++; // n=n+1
        drugie_wywolanie_funkcji += exp(-licznik_iteracji)*(1-cos(licznik_iteracji*pow(1,4))*(cos(licznik_iteracji*pow(1,4))-exp(-3*licznik_iteracji))); //Obliczanie wartosci dla f(1) dla nowego n
    }
    cout<<"Wartosc bledu po maksymalnym N: "<<fabs(pierwsze_wywolanie_funkcji-drugie_wywolanie_funkcji)<<endl; //Wypisanie wartosci bledu dla maksymalnej N
    cout<<"Wartosc maksymalnego N: "<<licznik_iteracji<<endl; //Wypisanie wartosci maksymalnej N
    return 0;
}