// Autor: Daniel Szarek
//=====================
#include "arraylist.h"

// Testy

bool empty_test() {
  ArrayList<int> list;
  return list.empty();
}

bool size_test() {
  ArrayList<int> list;
  int random = rand() % 1024;
  for (int i = 0; i < random; i++) list.push_front(1);
  return list.size() == random;
}

bool max_size_test() {
  ArrayList<int> list(64);
  return list.max_size() == 64;
}

bool push_front_test() {
  ArrayList<int> list;
  for (int i = 0; i < 64; i++) {
    int random = rand();
    list.push_front(random);
    if (list.front() != random) return false;
  }
  return true;
}

bool push_back_test() {
  ArrayList<int> list;
  for (int i = 0; i < 64; i++) {
    int random = rand();
    list.push_back(random);
    if (list.back() != random) return false;
  }
  return true;
}

bool front_test() {
  ArrayList<int> list;
  int random = rand();
  list.push_back(random);
  return list.front() == random;
}

bool back_test() {
  ArrayList<int> list;
  int random = rand();
  list.push_front(random);
  return list.back() == random;
}

bool full_test() {
  ArrayList<int> list;
  for (int i = 0; i < list.max_size(); i++) list.push_front(1);
  return list.full() == true;
}

bool pop_front_test() {
  ArrayList<int> list;
  int size = 64;
  int randomVal[64];
  for (int i = 0; i < 64; i++) {
    randomVal[i] = rand();
    list.push_back(randomVal[i]);
  }
  for (int i = 0; i < 64; i++) if (list.pop_front() != randomVal[i] || list.size() != --size) return false;
  return true;
}

bool pop_back_test() {
  ArrayList<int> list;
  int size = 64;
  int randomVal[64];
  for (int i = 0; i < 64; i++) {
    randomVal[i] = rand();
    list.push_front(randomVal[i]);
  }
  for (int i = 0; i < 64; i++) if (list.pop_back() != randomVal[i] || list.size() != --size) return false;
  return true;
}

bool clear_test() {
  ArrayList<int> list;
  for (int i = 0; i < 64; i++) list.push_back(i);
  list.clear();
  return list.size() == 0 ? true : false;
}

bool get_index_test() {
  ArrayList<int> list;
  int randomVal[128];
  for (int i = 0; i < 128; i++) {
    int random = rand();
    randomVal[i] = random;
    list.push_back(random);
  }
  for (int i = 0; i < list.size(); i++) if (randomVal[i] != list.get_index(i)) return false;
  return true;
}

bool insert_test() {
  ArrayList<int> list;
  int size = 64;
  for (int i = 0; i < size; i++) list.push_back(1);
  for (int i = 0; i < 64; i++) {
    int random = rand(), randomIndex = rand() % size;
    list.insert(random, randomIndex);
    size++;
    if (list.get_index(randomIndex) != random) return false;
  }
  return true;
}

bool erase_test() {
  ArrayList<int> list;
  for (int i = 0; i < 64; i++) list.push_back(i);
  int random = rand() % 64;
  list.erase(random);
  if (list.size() != 63) return false;
  for (int i = 0; i < list.size(); i++) if (list.get_index(i) == random) return false;
  return true;
}

bool sort_test() {
  ArrayList<int> list;
  for (int i = 0; i < 64; i++) list.push_back(rand());
  list.sort();
  for (int i = 0; i < 63; i++) if (list.get_index(i) > list.get_index(i + 1)) return false;
  return true;
}

bool merge_test() {
  ArrayList<int> list, list2, list3, list4;
  int size = 64 + rand() % 64, size2 = 64 + rand() % 64;
  for (int i = 0; i < size; i++) list.push_back(rand());
  for (int i = 0; i < size2; i++) list2.push_back(rand());
  list.sort();
  list2.sort();
  list.merge(list2);
  if (list.size() != size + size2) return false;
  for (int i = 0; i < list.size() - 1; i++) if (list.get_index(i) > list.get_index(i + 1)) return false;
  return true;
}

bool reverse_test() {
  ArrayList<int> list;
  vector<int> v;
  int random = rand() % 64;
  for (int i = 0; i < random; i++) {
    random = rand();
    list.push_back(random);
    v.push_back(random);
  }
  list.reverse();
  reverse(v.begin(),v.end());
  for (int i = 0; i < list.size(); i++) if (list.get_index(i) != v[i]) return false;
  return true;
}

// Output

int main(){

  cout<<"Witaj w programie testujacym implementacje ADT LIST!"<<endl<<"(Ponizej zostana przeprowadzone testy wynik 1 to true, 0 to false)"<<endl<<endl;
  sleep(2);
  cout<<"Test: empty() " << empty_test() <<endl;
  cout<<"Test: size() " << size_test() <<endl;
  cout<<"Test: max_size() " << max_size_test() <<endl;
  cout<<"Test: push_front() " << push_front_test() <<endl;
  cout<<"Test: push_back() " << push_back_test() <<endl;
  cout<<"Test: front() "<<front_test()<<endl;
  cout<<"Test: back() " << back_test() <<endl;
  cout<<"Test: full() " << full_test() <<endl;
  cout<<"Test: pop_front() " << pop_front_test() <<endl;
  cout<<"Test: pop_back() " << pop_back_test() <<endl;
  cout<<"Test: clear() " << clear_test() <<endl;
  cout<<"Test: get_index() " << get_index_test() <<endl;
  cout<<"Test: insert() " << insert_test() <<endl;
  cout<<"Test: erase() " << erase_test() <<endl;
  cout<<"Test: sort() " << sort_test() <<endl;
  cout<<"Test: merge() " << merge_test() <<endl;
  cout<<"Test: reverse() " << reverse_test() <<endl;
  return 0;
}
