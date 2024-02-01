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

public:
    LinkedList();
    ~LinkedList();
    LinkedList<T>& insert_to_begin(T data);
    LinkedList<T>& insert_to_end(T data);
    void print(std::ostream &out) const;
    void delete_first();
    void delete_last();
    void del(int position);
    bool find_pos(T item, int *pos);
    int size();
    T& operator[](int position);
};

// Implementation of list
template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node *aux1, *aux2;

    aux1 = first;
    while (aux1 != NULL) {
        aux2 = aux1->_pNext;
        delete aux1;
        printf("\nDeleted."); //for testing purposes
        aux1 = aux2;

    }
}

template <class T>
LinkedList<T>& LinkedList<T>::insert_to_begin(T data) {
    Node *newnode = new Node(data);
    if (first == NULL) {
        first = newnode;
        cout << "Linked list was empty. Now has one node which value is: " << first->_value << endl;
    } else {
        Node *what;
        what = newnode;
        what->_pNext = first;
        first = what;
        cout << "New node inserted to beginning which value is: " << newnode->_value << endl;
    }
    return *this;
}

template <class T>
LinkedList<T>& LinkedList<T>::insert_to_end(T data) {
    Node *newnode = new Node(data);
    if (first == NULL) {
        first = newnode;        //first node
        cout << "Linked list was empty. Now has one node which value is: " << first->_value << endl;
    } else {
        Node *what = first;
        while (what->_pNext != NULL) {
            what = what->_pNext;
        }
        what->_pNext = newnode;
        cout << "New node inserted to end which value is: " << newnode->_value << endl;
    }
    return *this;
}

template <class T>
void LinkedList<T>::print(std::ostream &out) const {
    Node *what;

    out << "\nList:";
    what = first;
    while (what != NULL) {
        out << " " << what->_value << " ";
        what = what->_pNext;
    }
    out << endl;
}

template <class T>
std::ostream &operator<<(std::ostream &out,  LinkedList<T> const &data) {
    data.print(out);
    return out;
}

template <class T>
void LinkedList<T>::delete_first(){
    if (first == NULL) {
        cout << "No node in linked list yet, deletion of first node not possible." << endl;
    } else if (first->_pNext == NULL) {
        delete first;
        cout << "Linked list had only one node which was deleted." << endl;
    } else {
        Node *aux = first;
        first = first->_pNext;
        aux->_value = '0';
        delete aux;
        cout << "First node of the linked list was deleted." << endl;
    }
}

template <class T>
void LinkedList<T>::delete_last() {
    if (first == NULL) {
        cout << "No node in linked list yet, deletion of last node not possible." << endl;
    } else if (first->_pNext == NULL) {
        first = NULL;
        cout << "Linked list had only one node which was deleted." << endl;
    } else {
        Node *newLast = first;
        while (newLast->_pNext->_pNext != NULL) {
            newLast = newLast->_pNext;
        }
        newLast->_pNext->_value = '0';
        delete newLast->_pNext;
        newLast->_pNext = NULL;
    }
}

template <class T>
void LinkedList<T>::del(int position) {
    if (position < 0 || position >= size()) {
        cerr << "Invalid position for deletion." << endl;
        return;
    }

    Node *delAux = first;

    if (position == 0) {
        first = first->_pNext;
        delete delAux;
        cout << "Node deleted at position " << position << "." << endl;
    } else {
        for (int i = 0; i < position - 1; i++) {
            delAux = delAux->_pNext;
        }
        Node *toBeDeleted = delAux->_pNext;
        delAux->_pNext = toBeDeleted->_pNext;

        delete toBeDeleted;
        cout << "Node deleted at position " << position << "." << endl;
    }
}

template <class T>
bool LinkedList<T>::find_pos(T item, int *pos) {
    Node *toBeFound = new Node(item);
    int index = 0;
    bool found = false;

    if (first == NULL) {
        cout << "No node in linked list yet, deletion not possible." << endl;
    } else if (first->_pNext == NULL) {
        if (first->_value == toBeFound->_value) {
            *pos = index;
            found = true;
        }
    } else {
        Node *aux = first;
        while (aux != NULL) {
            if (aux->_value == toBeFound->_value) {
                *pos = index;
                found = true;
            }
            aux = aux->_pNext;
            index++;
        }
    }
    return found;
}

template <class T>
int LinkedList<T>::size() {
    int count = 0;
    Node *countAux = first;
    while (countAux != NULL) {
        countAux = countAux->_pNext;
        count++;
    }
    return count;
}

template <class T>
T& LinkedList<T>::operator[](int position) {

    Node *search = first;
    int index = 0;

    if (position < size()) {
        while (search != NULL && index < position) {
            search = search->_pNext;
            index++;
        }
    }

    return search->_value;
}
