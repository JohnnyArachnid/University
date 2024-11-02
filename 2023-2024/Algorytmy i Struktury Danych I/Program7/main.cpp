// Autor: Daniel Szarek
//=====================
#include "myqueue.h"

// Testy

bool empty_test() {
  MyQueue<int> myqueue;
  return myqueue.empty();
}

bool full_test() {
  int size = rand() % 16;
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) myqueue.push(random);
  return myqueue.full();
}

bool size_test() {
  int size = rand() % 16;
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  for (int i = 0; i < size / 2; i++) myqueue.push(random);
  return size / 2 == myqueue.size();
}

bool max_size_test() {
  int size = rand() % 16;
  MyQueue<int> myqueue(size);
  return myqueue.max_size() == size;
}

bool push_test() {
  int size = (rand() % 16 + 1);
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) {
    myqueue.push(random);
    if(myqueue.back() != random) return false;
  }
  return true;
}

bool front_test() {
  int size = (rand() % 16 + 1);
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  myqueue.set_tab_front(random);
  return myqueue.front() == random;
}

bool back_test() {
  int size = (rand() % 16 + 1);
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  myqueue.push(random);
  return myqueue.back() == random;
}
bool pop_test() {
  int size = (rand() % 16 + 1);
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) myqueue.push(random);
  for (int i = 0; i < size; i++) {
    myqueue.pop();
    if (myqueue.size() != --size) return false;
  }
  return true;
}

bool clear_test() {
  int size = (rand() % 16);
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) myqueue.push(random);
  myqueue.clear();
  if(myqueue.size() == 0) return true;
  return false;
}

bool operator_rownosci_test() {
  int size = (rand() % 16 + 1);
  MyQueue<int> myqueue1(size);
  MyQueue<int> myqueue2(size);
  for (int i = 0; i < (size-1); i++){
    myqueue1.push(i);
    myqueue2.push(i);
  }
  myqueue2.push(21);
  myqueue1=myqueue2;
  for (int i = 0; i < size; i++) if(myqueue1.get_tab(i) != myqueue2.get_tab(i)) return false;
  return true;
}

void display_test(){
  int size = (rand() % 16 + 1);
  MyQueue<int> myqueue(size);
  int random = rand() % 16;
  cout<<"Wylosowane liczby: ";
  for (int i = 0; i < size; i++) {
    myqueue.push(random);
    cout<<random<<" ";
  }
  cout<<"MyQueue: ";
  myqueue.display();
}

// Output

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  cout<<"Witaj w programie testujacym implementacje ADT QUEUE !"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
  sleep(2);
  cout<<"Test: empty() " << empty_test() <<endl;
  cout<<"Test: full() " << full_test() <<endl;
  cout<<"Test: size() " << size_test() <<endl;
  cout<<"Test: max_size() " << max_size_test() <<endl;
  cout<<"Test: push() " << push_test() <<endl;
  cout<<"Test: front() " << front_test() <<endl;
  cout<<"Test: back() " << back_test() <<endl;
  cout<<"Test: pop() " << pop_test() <<endl;
  cout<<"Test: clear() " << clear_test() <<endl;
  cout<<"Test: operator_rownosci_test() " << operator_rownosci_test() <<endl;
  cout<<"Test: display()"<<endl;
  display_test();
  return 0;
}
