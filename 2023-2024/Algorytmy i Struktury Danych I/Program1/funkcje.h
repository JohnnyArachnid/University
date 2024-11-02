// Autor: Daniel Szarek
//=====================
#include <iostream>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <cassert>

#define ROZMIAR 20

using namespace std;

template <class T> 
void generowanie(T poczatek, T koniec) { generate(poczatek,koniec,[] () {return (rand()%50)+1;}); };

template <class T> 
void wypisywanie(T kontener)
{
    for(auto it = kontener.begin(); it != kontener.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
}

template <class T>
void bubbleSort(T poczatek, T koniec)
{
    for(auto it1 = poczatek; it1 < koniec; it1++)
        {
            for(auto it2 = poczatek; it2 < (koniec-1); it2++)
            {
                if(*it2 > *(it2+1))
                {
                    swap(*it2,*(it2+1));
                } 
            }
        }
}
template <class T> 
void quickSort(T poczatek, T koniec)
{
    if(poczatek >= koniec) return;
    T pivot = poczatek; 
    T srodek = poczatek+1;
    for(T it = srodek; it<koniec; it++)
    {
        if (*it < *pivot) {
            swap(*it, *srodek);
            srodek++;
        }
    }
    swap(*poczatek,*(srodek-1));
    quickSort(poczatek,srodek-1);
    quickSort(srodek,koniec);
}

template <class T>
void sprawdzenie(char znak, T poczatek, T koniec)
{
    if((is_sorted(poczatek, koniec) == 1) && znak == 't')
    {
        cout<<"Tablica posortowana"<<endl;
    } else if ((is_sorted(poczatek, koniec) == 1) && znak == 'w') {
        cout<<"Wektor posortowany"<<endl;
    } else {
        cout<<"Kontener nieposortowany"<<endl;
    }
}
