// Autor: Daniel Szarek
//=====================
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double pochodna1(double x, double h){ //Wzor na pochodna nr. 1 z polecenia
    double dzielenie = h;
    return ((sin(x+h) - sin(x)) / dzielenie);
}

double pochodna2(double x, double h){ //Wzor na pochodna nr. 2 z polecenia
    double dzielenie = 2*h;
    return ((sin(x+h) - sin(x-h)) / dzielenie);
}

double pochodna3(double x, double h){ //Wzor na pochodna nr. 3 z polecenia
    double dzielenie = 12*h;
    return ((-sin(x+2*h)+8*sin(x+h)-8*sin(x-h)+sin(x-2*h))/dzielenie);
}

int main(){
    fstream plik1,plik2,plik3,plik4,plik5,plik6; //Pliki do wypisywania wyników, a potem do możliwości utworzenia wykresów
    string nazwy[6] = {"plik1.txt","plik2.txt","plik3.txt","plik4.txt","plik5.txt","plik6.txt"}; //Nazwy plików
    double minimalne[6][2]; //Wartości minimalne dla h oraz odpowiadającym mu wyniku
    int licznikPetli = 0, licznikNazw = 0; //Iteratory
    double h=0.0000000000000001; //Wartosc h
    double x1 = 1, x2 = M_PI_2; //Wartosci x
    double wynikMin=fabs(pochodna1(x1,h)-cos(x1)); //Wartosc minimalna
    double wynik; //Deklaracja wyniku
    double zwiekszacz = h; //Zwiekszacz w petli
    plik1.open(nazwy[licznikNazw],ios::out); //Otwarcie pliku 1
    minimalne[licznikNazw][0] = h; //Wartosc minimalna
    minimalne[licznikNazw][1] = wynikMin; //Wartosc minimalna
    while(h<=1){
        h+=zwiekszacz;  //Zwiekszanie h
        if(licznikPetli == 100) //Zwiekszanie zwiekszacza
        {
            zwiekszacz*=10;
            licznikPetli = 0;
        }
        wynik = fabs(pochodna1(x1,h)-cos(x1)); //Obliczanie wyniku
        plik1<<h<<"         "<<wynik<<endl; //Wypisaine do pliku
        if(wynikMin > wynik){ //Sprawdzenie czy minimalna
            minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
            minimalne[licznikNazw][1] = wynik; //Przypisanie wartosci minimalnej dla wyniku
            wynikMin=wynik; //Podmiana wyniku na wynikMin
        }
        licznikPetli++;
    } 
    h=0.0000000000000001; //Stan h przy rozpoczeciu petli
    zwiekszacz = h; //Stan zwiekszacza przy rozpoczeciu petli
    licznikPetli = 0; //Wyzerowanie iteratora
    licznikNazw++; //Inkrementacja iteratora nazw
    wynikMin = fabs(pochodna2(x1,h)-cos(x1)); //Wartosc minimalna
    minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
    minimalne[licznikNazw][1] = wynikMin; //Przypisanie wartosci minimalnej dla wyniku
    plik2.open(nazwy[licznikNazw],ios::out); //Otwarcie pliku 2
    while(h<=1){
        h+=zwiekszacz;  //Zwiekszanie h
        if(licznikPetli == 100) //Zwiekszanie zwiekszacza
        {
            zwiekszacz*=10;
            licznikPetli = 0;
        }
        wynik = fabs(pochodna2(x1,h)-cos(x1)); //Obliczanie wyniku
        plik2<<h<<"         "<<wynik<<endl; //Wypisaine do pliku
        if(wynikMin > wynik){ //Sprawdzenie czy minimalna
            minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
            minimalne[licznikNazw][1] = wynik; //Przypisanie wartosci minimalnej dla wyniku
            wynikMin=wynik; //Podmiana wyniku na wynikMin
        }
        licznikPetli++;
    } 
    h=0.0000000000000001; //Stan h przy rozpoczeciu petli
    zwiekszacz = h; //Stan zwiekszacza przy rozpoczeciu petli
    licznikPetli = 0; //Wyzerowanie iteratora
    licznikNazw++; //Inkrementacja iteratora nazw
    wynikMin = fabs(pochodna3(x1,h)-cos(x1)); //Wartosc minimalna
    minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
    minimalne[licznikNazw][1] = wynikMin; //Przypisanie wartosci minimalnej dla wyniku
    plik3.open(nazwy[licznikNazw],ios::out); //Otwarcie pliku 3
    while(h<=1){
        h+=zwiekszacz;  //Zwiekszanie h
        if(licznikPetli == 100) //Zwiekszanie zwiekszacza
        {
            zwiekszacz*=10;
            licznikPetli = 0;
        }
        wynik = fabs(pochodna3(x1,h)-cos(x1)); //Obliczanie wyniku
        plik3<<h<<"         "<<wynik<<endl; //Wypisaine do pliku
        if(wynikMin > wynik){ //Sprawdzenie czy minimalna
            minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
            minimalne[licznikNazw][1] = wynik; //Przypisanie wartosci minimalnej dla wyniku
            wynikMin=wynik; //Podmiana wyniku na wynikMin
        }
        licznikPetli++;
    } 
    h=0.0000000000000001; //Stan h przy rozpoczeciu petli
    zwiekszacz = h; //Stan zwiekszacza przy rozpoczeciu petli
    licznikPetli = 0; //Wyzerowanie iteratora
    licznikNazw++; //Inkrementacja iteratora nazw
    wynikMin = fabs(pochodna1(x2,h)-cos(x2)); //Wartosc minimalna
    minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
    minimalne[licznikNazw][1] = wynikMin; //Przypisanie wartosci minimalnej dla wyniku
    plik4.open(nazwy[licznikNazw],ios::out); //Otwarcie pliku 4
    while(h<=1){
        h+=zwiekszacz;  //Zwiekszanie h
        if(licznikPetli == 100) //Zwiekszanie zwiekszacza
        {
            zwiekszacz*=10;
            licznikPetli = 0;
        }
        wynik = fabs(pochodna1(x2,h)-cos(x2)); //Obliczanie wyniku
        plik4<<h<<"         "<<wynik<<endl; //Wypisaine do pliku
        if(wynikMin > wynik){ //Sprawdzenie czy minimalna
            minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
            minimalne[licznikNazw][1] = wynik; //Przypisanie wartosci minimalnej dla wyniku
            wynikMin=wynik; //Podmiana wyniku na wynikMin
        }
        licznikPetli++;
    } 
    h=0.0000000000000001; //Stan h przy rozpoczeciu petli
    zwiekszacz = h; //Stan zwiekszacza przy rozpoczeciu petli
    licznikPetli = 0; //Wyzerowanie iteratora
    licznikNazw++; //Inkrementacja iteratora nazw
    wynikMin = fabs(pochodna2(x2,h)-cos(x2)); //Wartosc minimalna
    minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
    minimalne[licznikNazw][1] = wynikMin; //Przypisanie wartosci minimalnej dla wyniku
    plik5.open(nazwy[licznikNazw],ios::out); //Otwarcie pliku 5
    while(h<=1){
        h+=zwiekszacz;  //Zwiekszanie h
        if(licznikPetli == 100) //Zwiekszanie zwiekszacza
        {
            zwiekszacz*=10;
            licznikPetli = 0;
        }
        wynik = fabs(pochodna2(x2,h)-cos(x2)); //Obliczanie wyniku
        plik5<<h<<"         "<<wynik<<endl; //Wypisaine do pliku
        if(wynikMin > wynik){ //Sprawdzenie czy minimalna
            minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
            minimalne[licznikNazw][1] = wynik; //Przypisanie wartosci minimalnej dla wyniku
            wynikMin=wynik; //Podmiana wyniku na wynikMin
        }
        licznikPetli++;
    } 
    h=0.0000000000000001; //Stan h przy rozpoczeciu petli
    zwiekszacz = h; //Stan zwiekszacza przy rozpoczeciu petli
    licznikPetli = 0; //Wyzerowanie iteratora
    licznikNazw++; //Inkrementacja iteratora nazw
    wynikMin = fabs(pochodna3(x2,h)-cos(x2)); //Wartosc minimalna
    minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
    minimalne[licznikNazw][1] = wynikMin; //Przypisanie wartosci minimalnej dla wyniku
    plik6.open(nazwy[licznikNazw],ios::out); //Otwarcie pliku 6
    while(h<=1){
        h+=zwiekszacz;  //Zwiekszanie h
        if(licznikPetli == 100) //Zwiekszanie zwiekszacza
        {
            zwiekszacz*=10;
            licznikPetli = 0;
        }
        wynik = fabs(pochodna3(x2,h)-cos(x2)); //Obliczanie wyniku
        plik6<<h<<"         "<<wynik<<endl; //Wypisaine do pliku
        if(wynikMin > wynik){ //Sprawdzenie czy minimalna
            minimalne[licznikNazw][0] = h; //Przypisanie wartosci minimalnej dla h
            minimalne[licznikNazw][1] = wynik; //Przypisanie wartosci minimalnej dla wyniku
            wynikMin=wynik; //Podmiana wyniku na wynikMin
        }
        licznikPetli++;
    } 
    for(int i=0;i<6;i++){
        cout<<"Wartosc minimalnego h dla pliku: "<<i+1<<" wynosi: "<<minimalne[i][0]<<endl; //Wypisanie wartosci min dla h
        cout<<"Wartosc minimalnego wyniku dla pliku: "<<i+1<<" wynosi: "<<minimalne[i][1]<<endl; //Wypisanie wartosci min dla wyniku
        cout<<'\n';
    }
    return 0;
}