// Autor: Daniel Szarek
//=====================
#include "singlelist.h"

// Testy

bool empty_test() {
  SingleList<int> list;
  return list.empty();
}

bool size_test() {
  SingleList<int> list;
  int random = rand() % 16;
  unsigned size = (rand() % 16)+1;
  for (unsigned i = 0; i < size; i++) list.push_back(random);
  return (unsigned)list.size() == size;
}

bool push_front_test() {
  SingleList<int> list;
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
  SingleList<int> list;
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
  SingleList<int> list;
  int random = rand() % 16;
  list.push_back(random);
  return list.front() == random;
}

bool back_test() {
  SingleList<int> list;
  int random = rand() % 16;
  list.push_back(random);
  return list.back() == random;
}

bool pop_front_test() {
  SingleList<int> list;
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
  SingleList<int> list;
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
  SingleList<int> list;
  unsigned size = rand() % 16;
  int random = rand() % 16;
  for (unsigned i = 0; i < size; i++) list.push_back(random);
  list.clear();
  if(list.size() == 0){
    return true;
  } return false;
}

bool reverse_test() {
  SingleList<int> list1;
  SingleList<int> list2;
  unsigned size = rand() % 16;
  int random;
  for (unsigned i = 0; i < size; i++) {
    random = rand() % 16;
    list1.push_back(random);
    list2.push_front(random);
  }
  list2.reverse();
  for (unsigned i = 0; i < size; i++){
    SingleNode<int> *node1 = list1.head;
    SingleNode<int> *node2 = list2.head;
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

bool operator_rownosci_test() {
  SingleList<int> list1;
  SingleList<int> list2;
  SingleList<int> list3;
  unsigned size = rand() % 16;
  for (unsigned i = 0; i < size; i++){
    list1.push_back(i);
    list2.push_back(i);
  }
  list1.push_back(22);
  list3=list1;
  list1=list2;
  for (unsigned i = 0; i < size; i++){
    SingleNode<int> *node1 = list1.head;
    SingleNode<int> *node2 = list2.head;
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

void display_test(){
  SingleList<int> list1;
  unsigned size = rand() % 16;
  int random;
  for (unsigned i = 0; i < size; i++){
    random = rand() % 16;
    list1.push_back(random);
  }
  SingleList<int> list2(list1), list3;
  cout<<"Lista nr.1: ";
  list1.display();
  cout<<"Lista nr.2 (konstruktor kopiujący): ";
  list2.display();
  cout<<"Lista nr.3 (konstruktor domyslny): ";
  list3.display();
}

// Output

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  cout<<"Witaj w programie testujacym implementacje ADT LIST (lista pojedynczo powiązana)!"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
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
  cout<<"Test: reverse_test() " << reverse_test() <<endl;
  cout<<"Test: operator_rownosci_test() " << operator_rownosci_test() <<endl;
  cout<<"Test: display_test(): "<<endl;
  display_test();
  return 0;
}