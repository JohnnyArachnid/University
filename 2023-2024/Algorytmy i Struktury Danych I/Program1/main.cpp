// Autor: Daniel Szarek
//=====================
#include "funkcje.h"

int main()
{
    srand(time(NULL));
    array<int,ROZMIAR> tablica;
    vector<int> wektor(ROZMIAR);
    generowanie(tablica.begin(),tablica.end());
    generowanie(wektor.begin(),wektor.end());
    cout<<"=== Wartosci kontenerow przed sortowaniem ==="<<endl<<endl<<endl;
    cout<<"Tablica: ";
    wypisywanie(tablica);
    cout<<"Wektor: ";
    wypisywanie(wektor);
    cout<<"\n";
    cout<<"=== Wartosci po sortowaniu ==="<<endl<<endl<<endl;
    cout<<"### BubbleSort ###"<<endl<<endl;
    bubbleSort(tablica.begin(),tablica.end());
    bubbleSort(wektor.begin(),wektor.end());
    cout<<"Tablica: ";
    wypisywanie(tablica);
    cout<<"Wektor: "; 
    wypisywanie(wektor);
    cout<<"\n";
    cout<<"### QuickSort ###"<<endl<<endl;
    quickSort(tablica.begin(),tablica.end());
    quickSort(wektor.begin(),wektor.end());
    cout<<"Tablica: ";
    wypisywanie(tablica);
    cout<<"Wektor: ";
    wypisywanie(wektor);
    cout<<"\n";
    cout<<"=== Sprawdzenie ==="<<endl<<endl<<endl;
    sprawdzenie('t',tablica.begin(),tablica.end());
    sprawdzenie('w',wektor.begin(),wektor.end());
    cout<<"\n";
    return 0;
}