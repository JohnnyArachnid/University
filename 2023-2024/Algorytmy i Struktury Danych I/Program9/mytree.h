// Autor: Daniel Szarek
//=====================
// mytree.h

#ifndef MYTREE_H
#define MYTREE_H

#include <iostream> // deklaracje strumieni cout, cin, cerr
#include <cassert> // assert()
#include <unistd.h> // sleep()
#include <ctime> // srand(time(NULL))
#include <stack> // stack

using namespace std;

template <typename T>
struct BSTNode {
// the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    //BSTNode *parent;   // używane w pewnych zastosowaniach
    // kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    // konstruktor zwykły
    BSTNode(const T& item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() {} // destruktor
};

template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;
public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { clear(); } // trzeba wyczyścić
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; } // podgląd korzenia
    void insert(const T& item) { root = insert(root, item); }
    //void remove(const T& item); // na razie nie usuwamy elementów
    // Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T* find_min_iter();
    T* find_min_rek(BSTNode<T> * node, T* value);
    T* find_max_iter();
    T* find_max_rek(BSTNode<T> * node, T* value);
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void iter_preorder();
    void iter_inorder(); // trudne
    void iter_postorder(); // trudne
    void bfs(); // przejście poziomami (wszerz)
    void clear() { clear(root); root = nullptr; }
    void display() { display(root, 0); }
    BSTNode<T> *get_root() { return root; } // wyluskanie root do testow rekurencyjnych

    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    void clear(BSTNode<T> *node);
    BSTNode<T> * insert(BSTNode<T> *node, const T& item); // zwraca nowy korzeń
    BSTNode<T> * search(BSTNode<T> *node, const T& item) const;
    void preorder(BSTNode<T> *node);
    void inorder(BSTNode<T> *node);
    void postorder(BSTNode<T> *node);
    void display(BSTNode<T> *node, int level);
    virtual void visit(BSTNode<T> *node) {
        assert(node != nullptr);
        cout << "visiting " << node->value << endl;
    }
};

template <typename T>
void RandomBinaryTree<T>::clear(BSTNode<T> *node) {
  if (node == nullptr) return;
  clear(node->left);
  clear(node->right);
  node->left = nullptr;
  node->right = nullptr;
}

template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T> *node, int level) {
    if (node == nullptr) return;
    display(node->right, level + 1);
    cout << string(3 * level, ' ') << node->value << endl;
    display(node->left, level + 1);
}

template <typename T>
BSTNode<T> * RandomBinaryTree<T>::insert(BSTNode<T> *node, const T& item) {
    if (node == nullptr) {
        return new BSTNode<T>(item);
    }
    if (rand() % 2) { // można lepiej
        node->left = insert(node->left, item);
    } else {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzen
}

template <typename T>
T* RandomBinaryTree<T>::find_min_iter() {
    if (root == nullptr) return nullptr;
    T* minimalna = &(root->value);
    stack<BSTNode<T>*> S;
    BSTNode<T> *node = root;
    S.push(node);
    while (!S.empty()) {
        node = S.top();
        S.pop();
        if (node->right != nullptr) {
            S.push(node->right);
            if (node->right->value < *minimalna) minimalna = &(node->right->value);
        }
        if (node->left != nullptr) {
            S.push(node->left);
            if (node->left->value < *minimalna) minimalna = &(node->left->value);
        }
        else {
            if (node->value < *minimalna) minimalna = &(node->value);
        }
    }
    return minimalna;
}

template <typename T>
T* RandomBinaryTree<T>::find_min_rek(BSTNode<T> * node, T* value) {
    if (node == nullptr) return value;
    if (*value > node->value) value = &(node->value);
    T* value1 = find_min_rek(node->left, value);
    T* value2 = find_min_rek(node->right, value);
    if (*value1 < *value2) return value1;
    else return value2;
}

template <typename T>
T* RandomBinaryTree<T>::find_max_iter() {
    if (root == nullptr) return nullptr;
    T* maksymalna = &(root->value);
    stack<BSTNode<T>*> S;
    BSTNode<T> *node = root;
    S.push(node);
    while (!S.empty()) {
        node = S.top();
        S.pop();
        if (node->right != nullptr) {
            S.push(node->right);
            if (node->right->value > *maksymalna) maksymalna = &(node->right->value);
        }
        if (node->left != nullptr) {
            S.push(node->left);
            if (node->left->value > *maksymalna) maksymalna = &(node->left->value);
        }
        else {
            if (node->value > *maksymalna) maksymalna = &(node->value);
        }
    }
    return maksymalna;
}

template <typename T>
T* RandomBinaryTree<T>::find_max_rek(BSTNode<T> * node, T* value) {
    if (node == nullptr) return value;
    if (*value < node->value) value = &(node->value);
    T* value1 = find_max_rek(node->left, value);
    T* value2 = find_max_rek(node->right, value);
    if (*value1 > *value2) return value1;
    else return value2;
}

#endif

// EOF
