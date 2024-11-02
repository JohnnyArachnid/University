// Autor: Daniel Szarek
//=====================
// myqueue.h

#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <unistd.h>   // sleep()
#include <ctime> // srand(time(NULL))

using namespace std;

template <typename T>
class MyQueue {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyQueue() : msize(1), head(0), tail(0) {tab = new T[1];} //pusty konstruktor
    MyQueue(int s) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyQueue() { delete [] tab; }
    MyQueue(const MyQueue& other); // copy constructor
    MyQueue(MyQueue&& other); // move constructor
    MyQueue& operator=(const MyQueue& other); // copy assignment operator, return *this
    MyQueue& operator=(MyQueue&& other); // move assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (head + msize -1) % msize == tail; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push(const T& item); // dodanie na koniec
    void push(T&& item); // dodanie na koniec
    T& front() { return tab[head]; } // zwraca początek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop(); // usuwa początek
    void clear(); // czyszczenie listy z elementów
    void display();
    T get_tab(const int i); // uzyskanie wartosci tablicy o danym indeksie do operator_rownosci_test w pliku main.cpp
    void set_tab_front(const T value); // ustanowienie wartosci tablicy o danym indeksie do front_test w pliku main.cpp
};

template <typename T>
MyQueue<T>::MyQueue(const MyQueue& other) : msize{other.msize}, head{other.head}, tail{other.tail} {
    tab = new T[msize];
    assert(tab != nullptr);
    for(int i = 0; i < other.size(); i++) tab[i] = other.tab[i];
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue&& other) : msize{other.msize}, head{other.head}, tail{other.tail}, tab{other.tab} {
    other.msize = 0;
    other.head = 0;
    other.tail = 0;
    other.tab = nullptr;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue& other) {
    MyQueue<T> temp(other);
    msize = temp.msize;
    head = temp.head;
    tail = temp.tail;
    swap(tab,temp.tab);
    return *this;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue&& other) {
    msize = other.msize;
    head = other.head;
    tail = other.tail;
    tab = other.tab;
    return *this;
}

template <typename T>
void MyQueue<T>::push(const T& item) {
    assert(!full());
    tab[tail] = item;
    tail = (tail + 1) % msize;
}
template <typename T>
void MyQueue<T>::push(T&& item) {
    assert(!full());
    tab[tail] = move(item);
    tail = (tail + 1) % msize;
}

template <typename T>
void MyQueue<T>::pop(){
    assert(!empty());
    head = (head + 1) % msize;
}

template <typename T>
void MyQueue<T>::clear(){
    while(!empty()) pop();
}

template <typename T>
void MyQueue<T>::display() {
    for (int i = head; i != tail; i=(i+1) % msize) {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
T MyQueue<T>::get_tab(const int i) {
    return tab[i];
}

#endif

template <typename T>
void MyQueue<T>::set_tab_front(const T value){
    tab[0] = value;
}

// EOF
