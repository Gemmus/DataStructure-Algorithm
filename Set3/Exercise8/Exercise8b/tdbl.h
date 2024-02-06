/* tdbl.h -- Dynamic doubly linked linear list */

#include <iostream>

using namespace std;

// Interface of doubly linked list
template <typename T>
class Tdbl {
private:
    class Node {
    public:
        T _value;
        Node *_pNext;
        Node *_pPrev;

        Node() : _pNext(NULL), _pPrev(NULL) {}
        Node(T val) : _value(val), _pNext(NULL), _pPrev(NULL) {}
        Node(T val, Node *next, Node *prev) : _value(val), _pNext(next), _pPrev(prev) {}
    };

    Node *first;
    Node *last;

public:
    Tdbl();
    ~Tdbl();
    Tdbl<T> &insert_to_front(T data);
    Tdbl<T> &insert_to_back(T data);
    void print() const;
    void print_reverse() const;
};

// Implementation of doubly linked list
template <class T>
Tdbl<T>::Tdbl() {
    first = NULL;
    last = NULL;
}

template <class T>
Tdbl<T>::~Tdbl() {
    Node *aux1, *aux2;

    aux1 = first;
    while (aux1 != NULL) {
        aux2 = aux1->_pNext;
        delete aux1;
        //printf("\nDeleted."); //for testing purposes
        aux1 = aux2;
    }
}

template <class T>
Tdbl<T>& Tdbl<T>::insert_to_front(T data) {
    Node *newnode = new Node(data);
    if (first == NULL) {
        first = newnode;
        //cout << "Linked list was empty. Now has one node which value is: " << first->_value << endl;
    } else {
        Node *what;
        what = newnode;
        what->_pNext = first;
        first->_pPrev = what;
        first = what;
        //cout << "New node inserted to front which value is: " << newnode->_value << endl;
    }
    return *this;
}

template <class T>
Tdbl<T>& Tdbl<T>::insert_to_back(T data) {
    Node *newnode = new Node(data);
    if (first == NULL) {
        first = newnode;
        //cout << "Linked list was empty. Now has one node which value is: " << first->_value << endl;
    } else {
        newnode->_pPrev = last;
        last->_pNext = newnode;
        //cout << "New node inserted to end which value is: " << newnode->_value << endl;
    }
    last = newnode;

    return *this;
}

template <class T>
void Tdbl<T>::print() const {
    Node *what;
    cout << "\nList:";
    what = first;
    while (what != NULL) {
        cout << " " << what->_value << " ";
        what = what->_pNext;
    }
}

template <class T>
void Tdbl<T>::print_reverse() const {
    Node *what;
    cout << "\nList:";
    what = last;
    while (what != NULL) {
        cout << " " << what->_value << " ";
        what = what->_pPrev;
    }
}
