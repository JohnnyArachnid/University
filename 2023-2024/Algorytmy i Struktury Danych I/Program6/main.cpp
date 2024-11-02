// Autor: Daniel Szarek
//=====================
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

bool isNumber(const string& s); // Sprawdzenie czy jest liczba

int rpn(vector<string> input); // Funkcja do liczenia ONP

void rezultat(vector<string> input); // Funkcja do wypisywania wyniku na ekran

int main(){
    vector<string> input = {"-6","2","/"}; // Testy
    rezultat(input);
    input = {"4","2","8","10","*","/","-"}; // Testy
    rezultat(input);
    input = {"2","4","+","4","6","-","*"}; // Testy
    rezultat(input);
    input = {"5","3","7","-","2","*","3","5","1","+","*","-","*","3","-"}; // Testy
    rezultat(input);
    input = {"2","0","/"}; // Testy
    rezultat(input);
}

bool isNumber(const string& s) {
    for (unsigned i = 0; i < s.length(); i++) {
        if (i == 0 && s[i] == '-' && s.length() > 1) continue; // Sprawdzenie minusa
        if (!isdigit(s[i])) return false; // Sprawdzenie char czy sa cyframi od 0 do 9
    }
    return true;
}

int rpn(vector<string> input){
    stack<int> S; // Zaimplementowanie stosu
    int a,b;
    for (const string& s : input) {
        if (isNumber(s)) S.push(stoi(s)); // Liczba na stos
        else {
            a = S.top(); // Pobranie pierwszej liczby do operacji
            S.pop(); // Usuniecie pierwszej liczby ze stosu
            b = S.top(); // Pobranie drugiej liczby do operacji
            S.pop(); // Usuniecie drugiej liczby ze stosu
            if(s == "+") S.push(b+a); // Wynik operatora + na stos
            if(s == "-") S.push(b-a); // Wynik operatora - na stos
            if(s == "*") S.push(b*a); // Wynik operatora * na stos
            if(s == "/") {
                assert(a != 0); // Sprawdzenie dzielenia przez 0
                S.push(b/a); // Wynik operatora / na stos
            }                
        }
    }
    return S.top(); // Wynik dzialania
}

void rezultat(vector<string> input){
    int wynik = rpn(input);
    cout<<"Dane wejściowe: ";
    for(const string& s : input) cout<<s<<" ";
    cout<<"Rezultat: "<<wynik<<endl;
}