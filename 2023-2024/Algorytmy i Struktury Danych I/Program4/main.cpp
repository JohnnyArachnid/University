// Autor: Daniel Szarek
//=====================
#include "doublelist.h"

// Testy

bool empty_test() {
  DoubleList<int> list;
  return list.empty();
}

bool size_test() {
  DoubleList<int> list;
  int random = rand() % 16;
  unsigned size = rand() % 16;
  for (unsigned i = 0; i < size; i++) list.push_back(random);
  return (unsigned)list.size() == size;
}

bool push_front_test() {
  DoubleList<int> list;
  int first = 1;
  list.push_front(first);
  unsigned size = rand() & 16;
  for (unsigned i = 0; i < size; i++){
    int random = rand() % 16;
    list.push_back(random);
  }
  if (list.front() == first) return true;
  return false;
}

bool push_back_test() {
  DoubleList<int> list;
  int last = 1;
  list.push_front(last);
  unsigned size = rand() & 16;
  for (unsigned i = 0; i < size; i++){
    int random = rand() % 16;
    list.push_front(random);
  }
  if (list.back() == last) return true;
  return false;
}

bool front_test() {
  DoubleList<int> list;
  int random = rand() % 16;
  list.push_back(random);
  return list.front() == random;
}

bool back_test() {
  DoubleList<int> list;
  int random = rand() % 16;
  list.push_back(random);
  return list.back() == random;
}

bool pop_front_test() {
  DoubleList<int> list;
  unsigned size = (rand() % 16)+1;
  for (unsigned i = 0; i < size; i++) {
    int random = rand() % 16;
    list.push_back(random);
  }
  list.pop_front();
  size-=1;
  if ((unsigned)list.size() == size) return true;
  return false;
}

bool pop_back_test() {
  DoubleList<int> list;
  unsigned size = (rand() % 16)+1;
  for (unsigned i = 0; i < size; i++) {
    int random = rand() % 16;
    list.push_back(random);
  }
  list.pop_back();
  size-=1;
  if ((unsigned)list.size() == size) return true;
  return false;
}

bool clear_test() {
  DoubleList<int> list;
  unsigned size = rand() % 16;
  int random = rand() % 16;
  for (unsigned i = 0; i < size; i++) list.push_back(random);
  list.clear();
  if(list.size() == 0){
    return true;
  } return false;
}

bool operator_rownosci_test() {
  DoubleList<int> list1;
  DoubleList<int> list2;
  DoubleList<int> list3;
  unsigned size = rand() % 16;
  for (unsigned i = 0; i < size; i++){
    list1.push_back(i);
    list2.push_back(i);
  }
  list1.push_back(22);
  list3=list1;
  list1=list2;
  for (unsigned i = 0; i < size; i++){
    DoubleNode<int> *node1 = list1.head;
    DoubleNode<int> *node2 = list2.head;
    while (node1 != nullptr){
      if (node1->value != node2->value) return false;
      else{
        node1 = node1->next;
        node2 = node2->next;
      }
    }
  }
  return true;
}

void display_test_and_reserved_test(){
  DoubleList<int> list1;
  unsigned size = rand() % 16;
  int random;
  for (unsigned i = 0; i < size; i++){
    random = rand() % 16;
    list1.push_back(random);
  }
  DoubleList<int> list2(list1), list3;
  cout<<"Lista nr.1 przed odwróceniem: ";
  list1.display();
  cout<<"Lista nr.1 po odwróceniu: ";
  list1.display_reversed();
  cout<<"Lista nr.2 (konstruktor kopiujacy) przed odwróceniem: ";
  list2.display();
  cout<<"Lista nr.2 (konstruktor kopiujacy) po odwróceniu: ";
  list2.display_reversed();
  cout<<"Lista nr.3 (konstruktor domyslny) przed odwróceniem: ";
  list3.display();
  cout<<"Lista nr.3 (konstruktor domyslny) po odwróceniu: ";
  list3.display_reversed();
}

// Output

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  cout<<"Witaj w programie testujacym implementacje ADT LIST (lista podwójnie powiązana)!"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
  sleep(2);
  cout<<"Test: empty() " << empty_test() <<endl;
  cout<<"Test: size() " << size_test() <<endl;
  cout<<"Test: push_front() " << push_front_test() <<endl;
  cout<<"Test: push_back() " << push_back_test() <<endl;
  cout<<"Test: front() " << front_test() <<endl;
  cout<<"Test: back() " << back_test() <<endl;
  cout<<"Test: pop_front() " << pop_front_test() <<endl;
  cout<<"Test: pop_back() " << pop_back_test() <<endl;
  cout<<"Test: clear() " << clear_test() <<endl;
  cout<<"Test: operator_rownosci_test() " << operator_rownosci_test() <<endl;
  cout<<"Test: display_test i display_reversed_test (): "<<endl;
  display_test_and_reserved_test();
  return 0;
}
