// Autor: Daniel Szarek
//=====================
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <unistd.h>

#define MINSIZE 2

using namespace std;

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
  public:
    ArrayList(int msize = MINSIZE) : msize{msize}, last{0} { // construktor
      tab = new T[msize];
      assert(tab != nullptr);
    }
    ~ArrayList() { delete [] tab; } // destruktor

    ArrayList(const ArrayList& other) : msize{other.msize}, last{other.last} { // copy constructor
      tab = new T[msize];
      for (size_t i = 0; i < last; i++) tab[i] = other.tab[i];
    }

    ArrayList& operator=(const ArrayList& other) { // copy assigment operator, return *this
      if (this != &other) {
        delete [] tab;
        tab = new T[msize];
        msize = other.msize;
        last = other.last;
        for (int i = 0; i < last; ++i) tab[i] = other.tab[i];
      }
      return *this;
    }

    bool empty() { return last == 0; } // checks if the container has no elements

    bool full() { return last == msize; } // checks if the container is full

    int size() { return last; } // liczba elementow na liscie

    int max_size() { return msize; } // najwieksza mozliwa liczba elementow

    void push_front(const T& item) {  // dodanie na poczatek
      if (++last > msize) doublemsize();
      for (int i = last - 1; i > 0; i--) tab[i] = tab[i - 1];
      tab[0] = item;
    }

    void push_back(const T& item) { // dodanie na koniec
      if (last + 1 > msize) doublemsize();
      tab[last++] = item;
    }

    T& front() { // zwraca poczatek, nie usuwa, error dla pustej listy
      assert(!this->empty());
      return tab[0];
    }

    T& back() { // zwraca koniec, nie usuwa, error dla pustej listy
      assert(!this->empty());
      return tab[last - 1];
    }

    T pop_front() { // usuwa poczatek, error dla pustej listy
      assert(!this->empty());
      if (last - 1 <= msize / 2) halfmsize();
      T value = tab[0];
      for (int i = 0; i < last; i++) tab[i] = tab[i + 1];
      tab[last--] = T();
      return value;
    }

    T pop_back() { // usuwa koniec, error dla pustej listy
      assert(!this->empty());
      if (last - 1 <= msize / 2) halfmsize();
      T value = tab[--last];
      tab[last] = T();
      return value;
    }

    void clear() { // czyszczenie listy z elementow
      msize = MINSIZE, last = 0;
      T* minTab = new T[msize];
      T* temp = tab;
      tab = minTab;
      delete [] temp;
    }

    void display() { // lepiej zdefiniowac operator<<
      for (int i = 0; i < last; i++) cout << tab[i] << ' ';
      cout << '\n';
    }

    void reverse() { // odwracanie kolejnosci
      int i = 0, j = last - 1;
      while (i < j) {
        T temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
        i++;
        j--;
      }
    }

    void sort() { // sortowanie listy
      T temp;
      for (int i = 0; i < last; i++) {
        for (int j = 0; j < last; j++) {
          if (tab[i] < tab[j]) {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
          }
        }
      }
    }

    void merge(ArrayList& other) { // merges two sorted lists into one
      int i = 0;
      while (!other.empty() && i != last) {
        if (other.front() < tab[i]) {
          this->insert(other.pop_front(), i);
        }
        i++;
      }
      while (!other.empty()) {
        this->push_back(other.pop_front());
      }
    }

    void insert(const T& item, int pos) { // inserts item before pos
      if (++last > msize) doublemsize();
      for (int i = last; i > pos; i--) tab[i] = tab[i - 1];
      tab[pos] = item;
    }

    void erase(int pos) { // usuniecie elementu na pozycji pos
      if (last - 1 <= msize / 2) halfmsize();
      for (int i = pos; i < last; i++) tab[i] = tab[i + 1];
      tab[last--] = T();
    }

    T& get_index(int pos) { return tab[pos]; } // pobranie wartosci o wskazanym indeksie

    void doublemsize() { // zwiekszenie rozmiaru dwukrotnie
      msize *= 2;
      T* expandedTab = new T[msize];
      for (int i = 0; i < last; i++) expandedTab[i] = tab[i];
      T* temp = tab;
      tab = expandedTab;
      delete [] temp;
    }

    void halfmsize() { // zmniejszenie rozmiaru dwukrotnie
      if (msize > MINSIZE) msize /= 2;
      T* halvedTab = new T[msize];
      for (int i = 0; i < last; i++) halvedTab[i] = tab[i];
      T* temp = tab;
      tab = halvedTab;
      delete [] temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }

        return os;
    }
};

#endif

// EOF
