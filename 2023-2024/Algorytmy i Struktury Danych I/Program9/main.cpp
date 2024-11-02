// Autor: Daniel Szarek
//=====================
#include "mytree.h"

// Testy

bool find_min_iter_test() {
  int size = (rand() % 16 + 1);
  RandomBinaryTree<int> randombinarytree;
  int random;
  int minimalna = 17;
  for (int i = 0; i < size; i++) {
    random = rand() % 16;
    if (minimalna > random) minimalna = random;
    randombinarytree.insert(random);
  }
  int* sprawdzenie = randombinarytree.find_min_iter();
  return *sprawdzenie == minimalna ? true : false;
}

bool find_min_rek_test() {
  int size = (rand() % 16 + 1);
  RandomBinaryTree<int> randombinarytree;
  int random;
  int minimalna = 17;
  for (int i = 0; i < size; i++) {
    random = rand() % 16;
    if (minimalna > random) minimalna = random;
    randombinarytree.insert(random);
  }
  int* sprawdzenie = randombinarytree.find_min_rek(randombinarytree.get_root(),&(randombinarytree.top()));
  return *sprawdzenie == minimalna ? true : false;
}

bool find_max_iter_test() {
  int size = (rand() % 16 + 1);
  RandomBinaryTree<int> randombinarytree;
  int random;
  int maksymalna = -1;
  for (int i = 0; i < size; i++) {
    random = rand() % 16;
    if (maksymalna < random) maksymalna = random;
    randombinarytree.insert(random);
  }
  int* sprawdzenie = randombinarytree.find_max_iter();
  return *sprawdzenie == maksymalna ? true : false;
}

bool find_max_rek_test() {
  int size = (rand() % 16 + 1);
  RandomBinaryTree<int> randombinarytree;
  int random;
  int maksymalna = -1;
  for (int i = 0; i < size; i++) {
    random = rand() % 16;
    if (maksymalna < random) maksymalna = random;
    randombinarytree.insert(random);
  }
  int* sprawdzenie = randombinarytree.find_max_rek(randombinarytree.get_root(),&(randombinarytree.top()));
  return *sprawdzenie == maksymalna ? true : false;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  cout<<"Witaj w programie testujacym wartosc minimalna i maksymalna w ADT TREE !"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
  sleep(2);
  cout<<"Test: find_min_iter() "<< find_min_iter_test() <<endl;
  cout<<"Test: find_min_rek() "<< find_min_rek_test() <<endl;
  cout<<"Test: find_max_iter() "<< find_max_iter_test() <<endl;
  cout<<"Test: find_max_rek() "<< find_max_rek_test() <<endl;
  return 0;
}