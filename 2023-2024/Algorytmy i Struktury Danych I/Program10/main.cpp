// Autor: Daniel Szarek
//=====================
#include "mybinarysearchtree.h"

// Testy

bool find_min_test() {
  int size = (rand() % 16 + 1);
  BinarySearchTree<int> BinarySearchTree;
  int random;
  int minimalna = 17;
  for (int i = 0; i < size; i++) {
    random = rand() % 16;
    if (minimalna > random) minimalna = random;
    BinarySearchTree.insert(random);
  }
  int* sprawdzenie = BinarySearchTree.find_min();
  return *sprawdzenie == minimalna ? true : false;
}

bool find_max_test() {
  int size = (rand() % 16 + 1);
  BinarySearchTree<int> BinarySearchTree;
  int random;
  int maksymalna = -1;
  for (int i = 0; i < size; i++) {
    random = rand() % 16;
    if (maksymalna < random) maksymalna = random;
    BinarySearchTree.insert(random);
  }
  int* sprawdzenie = BinarySearchTree.find_max();
  return *sprawdzenie == maksymalna ? true : false;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  cout<<"Witaj w programie testujacym wartosc minimalna i maksymalna w BST !"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
  sleep(2);
  cout<<"Test: find_min() "<< find_min_test() <<endl;
  cout<<"Test: find_max() "<< find_max_test() <<endl;
  return 0;
}