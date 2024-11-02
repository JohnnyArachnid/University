// Autor: Daniel Szarek
//=====================
// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <unistd.h>   // sleep()
#include <ctime> // srand(time(NULL))

using namespace std;

template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() {} // destruktor
};


template <typename T>
class DoubleList {
public:
    DoubleNode<T> *head, *tail;
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(); // tu trzeba wyczyscic wezly

    DoubleList(const DoubleList& other); // copy constructor
    // usage:   DoubleList<int> list2(list1);

    DoubleList& operator=(const DoubleList& other); // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }
    int size() const; // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1)
    void push_back(const T& item); // O(1)
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(1)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void display_reversed(); // O(n)
};

template <typename T>
DoubleList<T>::~DoubleList() {
    for (DoubleNode<T> *node; !empty(); ) {
        node = head->next;
        delete head;
        head = node;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other) : head{nullptr}, tail{nullptr} {
    DoubleNode<T> *node = other.head;
    while(node != nullptr){
        push_back(node->value);
        node = node->next;
    }
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& other){
    clear();
    DoubleNode<T> *node = other.head;
    while(node != nullptr) {
        push_back(node->value);
        node = node->next;
    }
    return *this;
}

template <typename T>
int DoubleList<T>::size() const {
    int size = 1;
    if (empty()) return 0;
    else {
        DoubleNode<T> *node = head;
        while (node->next != nullptr) {
            size++;
            node = node->next;
        }
    }
    return size;
}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail = new DoubleNode<T>(item, nullptr, tail);
        tail->prev->next = tail;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::pop_front() {
    assert(!empty());
    DoubleNode<T> *node = head;
    node = head->next;
    delete head;
    if(node != nullptr) {
        node->prev = nullptr;
        head = node;
    } else {
        head = nullptr;
        tail = nullptr;
    }
}

template <typename T>
void DoubleList<T>::pop_back() {
    assert(!empty());
    DoubleNode<T>* node = tail;
    node = tail->prev; 
    delete tail;
    if (node != nullptr) {
        node->next = nullptr;
        tail = node;
    } else {
        head = nullptr;
        tail = nullptr;
    }
}

template <typename T>
void DoubleList<T>::clear() {
    while (!empty()) pop_back();
}

template <typename T>
void DoubleList<T>::display() {
    DoubleNode<T> *node = head;
    if (node != nullptr) {
        while (node != nullptr){
        cout<<node->value<<" ";
        node = node->next;
        }
        cout<<endl;
    } else cout<<"Lista pusta!"<<endl;
}

template <typename T>
void DoubleList<T>::display_reversed() {
    DoubleNode<T> *node = tail;
    if (node != nullptr) {
        while (node != nullptr){
        cout<<node->value<<" ";
        node = node->prev;
        }
        cout<<endl;
    } else cout<<"Lista pusta!"<<endl;
}

#endif

// EOF
