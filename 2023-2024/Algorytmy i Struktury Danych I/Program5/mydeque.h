// Autor: Daniel Szarek
//=====================
// mydeque.h

#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <unistd.h>   // sleep()
#include <ctime> // srand(time(NULL))

using namespace std;

template <typename T>
class MyDeque {
public:
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
    MyDeque() : msize(1), head(0), tail(0) {tab = new T[1];} //pusty konstruktor
    MyDeque(int s) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyDeque() { delete [] tab; } //destruktor
    MyDeque(const MyDeque& other); // copy constructor
    MyDeque& operator=(const MyDeque& other); // copy assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push_front(const T& item); // dodanie na początek O(1)
    void push_back(const T& item); // dodanie na koniec O(1)
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop_front(); // usuwa początek kolejki O(1)
    void pop_back(); // usuwa koniec kolejki O(1)
    void clear(); // czyszczenie listy z elementów
    void display(); //wyswietlenie elementow
    void erase(int pos); // usuniecie elementu o danym indeksie
    int index(const T& item); // jaki index na liście (-1 gdy nie ma)
};

template <typename T>
MyDeque<T>::MyDeque(const MyDeque& other) : msize{other.msize}, head{other.head}, tail{other.tail} {
  tab = new T[msize];
  assert(tab != nullptr);
  if (tail != 0) for (int i = 0; i < tail; i++) tab[i] = other.tab[i];
  if (head != 0) for (int i = head; i < msize; i++) tab[i] = other.tab[i];
}

template <typename T>
MyDeque<T>& MyDeque<T>::operator=(const MyDeque& other) {
    MyDeque<T> temp(other);
    msize = temp.msize;
    head = temp.head;
    tail = temp.tail;
    swap(tab,temp.tab);
    return *this;
}

template <typename T>
void MyDeque<T>::push_front(const T& item) {
    head = (head + msize -1) % msize;
    tab[head] = item;
}

template <typename T>
void MyDeque<T>::push_back(const T& item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyDeque<T>::pop_front(){
    head = (head + msize + 1) % msize;
}

template <typename T>
void MyDeque<T>::pop_back(){
    tail = (tail - 1 + msize) % msize;
}

template <typename T>
void MyDeque<T>::clear(){
    while(!empty()) pop_back();
}

template <typename T>
void MyDeque<T>::display() {
    if(empty()) cout<<"MyDeque jest puste"<<endl;
    for (int i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    cout<<endl;
}

template <typename T>
void MyDeque<T>::erase(int pos) {
    if(pos <= 0 && pos > msize) return;
    for(int i = pos + 1; i < size(); i++) tab[(head + i + msize - 1) % msize] = tab[(head + 1) % msize];
    tail = (tail - 1 + msize) % msize; 
}

template <typename T>
int MyDeque<T>::index(const T& item){
    for(int i = 0; i < (msize-1); i++) if(tab[i] == item) return i;
    return -1;
}

#endif

// EOF
