#include <iostream>
#include <typeinfo>
#include <type_traits>

template<typename H, typename T> struct TypeList {
  typedef H Head;
  typedef T Tail;
};

class Null_type {};

template<typename T> struct Length;

template<> struct Length<Null_type> {
    enum { value = 0 };
};

template<typename H, typename T> struct Length<TypeList<H, T>> {
    enum { value = 1 + Length<T>::value };
};

template<int N, typename T> struct At;

template<int N, typename H, typename T> struct At<N, TypeList<H, T>> {
    typedef typename At<N-1, T>::Result Result;
};

template<typename H, typename T> struct At<0, TypeList<H, T>> {
    typedef H Result;
};

template<typename T, typename TL> struct In;

template<typename T> struct In<T, Null_type> {
    enum { value = 0 };
};

template<typename T, typename H, typename TAIL> struct In<T, TypeList<H, TAIL>> {
    enum { value = (std::is_same<T, H>::value) ? 1 : In<T, TAIL>::value };
};

int main() {
    typedef TypeList<int, TypeList<double, TypeList<char, Null_type>>> MyList;

    std::cout << "Length of MyList: " << Length<MyList>::value << std::endl;

    typedef typename At<0, MyList>::Result TypeAt0;
    std::cout << "Type at index 0: " << typeid(TypeAt0).name() << std::endl;

    typedef typename At<1, MyList>::Result TypeAt1;
    std::cout << "Type at index 1: " << typeid(TypeAt1).name() << std::endl;

    std::cout << "Is 'double' in MyList? " << In<double, MyList>::value << std::endl;
    std::cout << "Is 'float' in MyList? " << In<float, MyList>::value << std::endl;
    
    return 0;
}