// Autor: Daniel Szarek
//=====================
#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <unistd.h>   // sleep()
#include <ctime> // srand(time(NULL))

using namespace std;

template <typename T>
struct SingleNode {
// the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, SingleNode *ptr = nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList {
public:
    SingleNode<T> *head, *tail;
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList(); // tu trzeba wyczyscic wezly

    SingleList(const SingleList& other); // copy constructor
    // usage:   SingleList<int> list2(list1);

    SingleList& operator=(const SingleList& other); // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }
    int size() const; // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1), L.push_front(item)
    void push_back(const T& item); // O(1), L.push_back(item)
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void reverse(); // O(n)
};

template <typename T>
SingleList<T>::~SingleList() {
    // I sposob.
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}

template <typename T>
SingleList<T>::SingleList(const SingleList& other) : head{nullptr}, tail{nullptr} {
    SingleNode<T> *node = other.head;
    while(node != nullptr) {
        push_back(node->value);
        node = node->next;
    }
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList<T>& other) {
    clear();
    SingleNode<T> *node = other.head;
    while (node != nullptr) {
        push_back(node->value);
        node = node->next;
    }
    return *this;
}

template <typename T>
int SingleList<T>::size() const {
    int size = 1;
    if (empty()) return 0;
    else {
        SingleNode<T> *node = head;
        while (node->next != nullptr) {
            size++;
            node = node->next;
        }
    }
  return size;
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) head = new SingleNode<T>(item, head); 
    else head = tail = new SingleNode<T>(item);
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else head = tail = new SingleNode<T>(item);
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) head = tail = nullptr; // jeden wezel na liscie
    else head = head->next; // wiecej niz jeden wezel na liscie
    delete node;
  }

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) head = tail = nullptr; // jeden wezel na liscie
    else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before = head;
        while (before->next != tail) before = before->next;
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

template <typename T>
void SingleList<T>::clear() {
    while (!empty()) pop_back();
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    if (node != nullptr) {
        while (node != nullptr){
        cout<<node->value<<" ";
        node = node->next;
        }
        cout<<endl;
    } else cout<<"Lista pusta!"<<endl;
}

template <typename T>
void SingleList<T>::reverse() {
    SingleNode<T> *node1 = head;
    SingleList<T> tmp;
    while (node1 != nullptr) {
        tmp.push_front(node1->value);
        node1 = node1->next;
    }
    SingleNode<T> *node2 = tmp.head;
    clear();
    while (node2 != nullptr) {
        push_back(node2->value);
        node2 = node2->next;
    }
}

#endif