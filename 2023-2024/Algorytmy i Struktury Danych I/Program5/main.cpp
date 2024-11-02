// Autor: Daniel Szarek
//=====================
#include "mydeque.h"

// Testy

bool empty_test() {
  MyDeque<int> mydeque;
  return mydeque.empty();
}

bool full_test() {
  int size = rand() % 16;
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mydeque.push_back(random);
  return mydeque.full();
}

bool size_test() {
  int size = rand() % 16;
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mydeque.push_back(random);
  return size == mydeque.size();
}

bool max_size_test() {
  int size = rand() % 16;
  MyDeque<int> mydeque(size);
  return mydeque.max_size() == size;
}

bool push_front_test() {
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int first = 21;
  mydeque.push_front(first);
  int random = rand() % 16;
  for (int i = 1; i < size; i++) mydeque.push_back(random);
  if (mydeque.front() == first) return true;
  return false;
}

bool push_back_test() {
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int last = 21;
  mydeque.push_back(last);
  int random = rand() % 16;
  for (int i = 1; i < size; i++) mydeque.push_front(random);
  if (mydeque.back() == last) return true;
  return false;
}

bool front_test() {
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  mydeque.push_front(random);
  return mydeque.front() == random;
}

bool back_test() {
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  mydeque.push_back(random);
  return mydeque.back() == random;
}
bool pop_front_test() {
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mydeque.push_back(random);
  for (int i = 0; i < size; i++) {
    mydeque.pop_front();
    if (mydeque.size() != --size) return false;
  }
  return true;
}

bool pop_back_test() {
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mydeque.push_back(random);
  for (int i = 0; i < size; i++) {
    mydeque.pop_back();
    if (mydeque.size() != --size) return false;
  }
  return true;
}

bool clear_test() {
  int size = (rand() % 16);
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mydeque.push_back(random);
  mydeque.clear();
  if(mydeque.size() == 0) return true;
  return false;
}

bool operator_rownosci_test() {
  int size = (rand() % 16);
  MyDeque<int> mydeque1(size);
  MyDeque<int> mydeque2(size);
  for (int i = 0; i < (size-1); i++){
    mydeque1.push_back(i);
    mydeque2.push_back(i);
  }
  mydeque2.push_back(21);
  mydeque1=mydeque2;
  for (int i = 0; i < size; i++) if(mydeque1.tab[i] != mydeque2.tab[i]) return false;
  return true;
}

void display_test(){
  int size = (rand() % 16);
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  cout<<"Wylosowane liczby: ";
  for (int i = 0; i < size; i++) {
    mydeque.push_back(random);
    cout<<random<<" ";
  }
  cout<<"Mydeque: ";
  mydeque.display();
}
bool erase_test(){
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mydeque.push_back(random);
  mydeque.erase(size-1);
  if(mydeque.size() == (size-1)) return true;
  return false;
}

bool index_test(){
  int size = (rand() % 16 + 1);
  MyDeque<int> mydeque(size);
  int i;
  for (i = 0; i < size; i++) mydeque.push_back(i);
  int liczba1 = mydeque.index(i);
  int liczba2 = mydeque.index(i-1);
  if(size - 1 == liczba2 && liczba1 == -1) return true;
  return false;
}

// Output

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  cout<<"Witaj w programie testujacym implementacje ADT DEQUE !"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
  sleep(2);
  cout<<"Test: empty() " << empty_test() <<endl;
  cout<<"Test: full() " << full_test() <<endl;
  cout<<"Test: size() " << size_test() <<endl;
  cout<<"Test: max_size() " << max_size_test() <<endl;
  cout<<"Test: push_front() " << push_front_test() <<endl;
  cout<<"Test: push_back() " << push_back_test() <<endl;
  cout<<"Test: front() " << front_test() <<endl;
  cout<<"Test: back() " << back_test() <<endl;
  cout<<"Test: pop_front() " << pop_front_test() <<endl;
  cout<<"Test: pop_back() " << pop_back_test() <<endl;
  cout<<"Test: clear() " << clear_test() <<endl;
  cout<<"Test: operator_rownosci_test() " << operator_rownosci_test() <<endl;
  cout<<"Test: display()"<<endl;
  display_test();
  cout<<"Test: erase() "<< erase_test() <<endl;
  cout<<"Test: index() "<< index_test() <<endl;
  return 0;
}
