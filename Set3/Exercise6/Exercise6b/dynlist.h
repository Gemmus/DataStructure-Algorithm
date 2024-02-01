/* dynlist.h -- Dynamic linked linear list */
#include <iostream>

using namespace std;

// Interface of list
template <class T>
class LinkedList {
private:
    // definition of the list node class
    class Node {
    public:
        T     _value;	// data
        Node *_pNext;	// pointer to the next node
        Node() : _pNext(NULL) {}
        Node(T val) : _value(val), _pNext(NULL) {}
        Node(T val, Node* next) : _value(val), _pNext(next) {}
    };

    Node *first;
    Node *last;

public:
    LinkedList();
    ~LinkedList();
    LinkedList<T>& insert_to_end(T data);
    void print(std::ostream &out = std::cout) const;
};

// Implementation of list
template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
    last = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node *aux1, *aux2;

    aux1 = first;
    while (aux1 != NULL) {
        aux2 = aux1->_pNext;
        delete aux1;
        printf("\nDeleted"); //for testing purposes
        aux1 = aux2;
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::insert_to_end(T data) {
    Node *newnode = new Node(data);
    if (first == NULL)
        first = newnode;		//first node
    else
        last->_pNext = newnode;	//not first node
    last = newnode;

    return *this;
}

template <class T>
void LinkedList<T>::print(std::ostream &out) const {
    Node *what;

    out << "\nList:" << endl;
    what = first;
    while (what != NULL) {
        out << what->_value;
        what = what->_pNext;
    }
    out << endl;
}

template <class T>
std::ostream &operator<<(std::ostream &out,  LinkedList<T> const &data) {
    data.print(out);
    return out;
}
