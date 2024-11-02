// Autor: Daniel Szarek
//=====================
#include "mypriorityqueue.h"

// Testy

bool empty_test() {
  MyPriorityQueue<int> mypriorityqueue;
  return mypriorityqueue.empty();
}

bool size_test() {
  int size = rand() % 16;
  MyPriorityQueue<int> mypriorityqueque(size);
  int random = rand() % 16;
  for (int i = 0; i < size / 2; i++) mypriorityqueque.push(random);
  return size / 2 == mypriorityqueque.size();
}

bool push_test() {
  int size = (rand() % 16 + 1);
  MyPriorityQueue<int> mypriorityqueque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) {
    mypriorityqueque.push(random);
    if(mypriorityqueque.top() != random) return false;
  }
  return true;
}

bool top_test() {
  int size = (rand() % 16 + 1);
  MyPriorityQueue<int> mypriorityqueque(size);
  int random = rand() % 16;
  mypriorityqueque.push(random);
  return mypriorityqueque.top() == random;
}


bool pop_test() {
  int size = (rand() % 16 + 1);
  MyPriorityQueue<int> mypriorityqueque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mypriorityqueque.push(random);
  for (int i = 0; i < size; i++) {
    mypriorityqueque.pop();
    if (mypriorityqueque.size() != --size) return false;
  }
  return true;
}

bool clear_test() {
  int size = (rand() % 16);
  MyPriorityQueue<int> mypriorityqueque(size);
  int random = rand() % 16;
  for (int i = 0; i < size; i++) mypriorityqueque.push(random);
  mypriorityqueque.clear();
  if(mypriorityqueque.size() == 0) return true;
  return false;
}

bool operator_rownosci_test() {
  int size = (rand() % 16 + 1);
  MyPriorityQueue<int> mypriorityqueque1(size);
  MyPriorityQueue<int> mypriorityqueque2(size);
  for (int i = 0; i < (size-1); i++){
    mypriorityqueque1.push(i);
    mypriorityqueque2.push(i);
  }
  mypriorityqueque2.push(21);
  mypriorityqueque1=mypriorityqueque2;
  for (int i = 0; i < size; i++) if(mypriorityqueque1.get_value_index_vector(i) != mypriorityqueque2.get_value_index_vector(i)) return false;
  return true;
}

void display_test(){
  int size = (rand() % 16 + 1);
  MyPriorityQueue<int> mypriorityqueque(size);
  int random;
  cout<<"Wylosowane liczby: ";
  for (int i = 0; i < size; i++) {
    random = rand() % 16;
    mypriorityqueque.push(random);
    cout<<random<<" ";
  }
  cout<<"MyPriorityQueue (Posortowana): ";
  mypriorityqueque.display();
}

// Output

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  cout<<"Witaj w programie testujacym implementacje ADT PRIORITY QUEUE !"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
  sleep(2);
  cout<<"Test: empty() " << empty_test() <<endl;
  cout<<"Test: size() " << size_test() <<endl;
  cout<<"Test: push() " << push_test() <<endl;
  cout<<"Test: top() " << top_test() <<endl;
  cout<<"Test: pop() " << pop_test() <<endl;
  cout<<"Test: clear() " << clear_test() <<endl;
  cout<<"Test: operator_rownosci_test() " << operator_rownosci_test() <<endl;
  cout<<"Test: display()"<<endl;
  display_test();
  return 0;
}

