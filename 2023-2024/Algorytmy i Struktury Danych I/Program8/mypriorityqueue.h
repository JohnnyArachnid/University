// Autor: Daniel Szarek
//=====================
// mypriorityqueue.h

#ifndef MYPRIORITYQUEUE_H
#define MYPRIORITYQUEUE_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <unistd.h>   // sleep()
#include <ctime> // srand(time(NULL))
#include <vector> // vektory
#include <algorithm> // make_heap, push_heap, pop_heap

using namespace std;

template <typename T>
class MyPriorityQueue {
    vector<T> lst; // działa domyślny konstruktor dla vector
public:
    MyPriorityQueue() {}; // pusty konstruktor
    MyPriorityQueue(int s) { lst.reserve(s); } // default constructor
    ~MyPriorityQueue() { lst.clear(); }
    MyPriorityQueue(const MyPriorityQueue& other); // copy constructor
    MyPriorityQueue(MyPriorityQueue&& other); // move constructor
    MyPriorityQueue& operator=(const MyPriorityQueue& other); // copy assignment operator, return *this
    MyPriorityQueue& operator=(MyPriorityQueue&& other); // move assignment operator, return *this
    bool empty() const { return lst.empty(); }
    int size() const { return lst.size(); } // liczba elementów w kolejce
    void push(const T& item) { // dodanie do kolejki
        lst.push_back(item);
        push_heap(lst.begin(), lst.end());
    }
    void push(T&& item) { // dodanie do kolejki
        lst.push_back(move(item));
        push_heap(lst.begin(), lst.end());
    }
    T& top() { return lst.front(); } // zwraca element największy, nie usuwa
    void pop() { // usuwa element największy
        pop_heap(lst.begin(), lst.end());
        lst.pop_back();
    }
    void clear() { lst.clear(); } // czyszczenie listy z elementów
    void display(); // wyswietlanie zawartosci
    T get_value_index_vector(const int i); // uzyskanie wartosci wektora o danym indeksie do operator_rownosci_test w pliku main.cpp
};

template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(const MyPriorityQueue& other) {
    lst.reserve(other.size());
    lst = other.lst;
}

template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(MyPriorityQueue&& other) {
    lst = other.lst;
    other.clear();
}

template <typename T>
MyPriorityQueue<T>& MyPriorityQueue<T>::operator=(const MyPriorityQueue& other) {
    lst.clear();
    lst.reserve(other.size());
    lst = other.lst;
    return *this;
}

template <typename T>
MyPriorityQueue<T>& MyPriorityQueue<T>::operator=(MyPriorityQueue&& other) {
    lst = other.lst;
    return *this;
}

template <typename T>
void MyPriorityQueue<T>::display(){
    sort_heap(lst.begin(), lst.end());
    for (int i=0; i<size(); i++) cout<<lst[i]<<" ";
    cout<<endl;
}

template <typename T>
T MyPriorityQueue<T>::get_value_index_vector(const int i){ return lst[i]; }

#endif

// EOF
