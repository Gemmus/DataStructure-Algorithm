/*
Write a function which receives a single linked integer list as a parameter and creates a new linked
list with the same data content but in an opposite order. Remember to include class definitions for
the node on your answer. (6p)
*/

#include <iostream>

template <class T>
class Node {
public:
    T _value;
    Node *_pNext;
    Node(T _value0) : _value(_value0), _pNext(nullptr) {};
};

template <class T>
Node<T>* reverse(const Node<T>* source) {
    Node<T>* reversed = nullptr;
    const Node<T>* current = source;

    while (current != nullptr) {
        Node<T>* newNode = new Node<T>(current->_value);
        newNode->_pNext = reversed;
        reversed = newNode;
        current = current->_pNext;
    }

    return reversed;
}

template <class T>
void printList(const Node<T>* node) {
    while (node != nullptr) {
        std::cout << node->_value << " ";
        node = node->_pNext;
    }
    std::cout << std::endl;
}

int main() {
    Node<int>* first = new Node<int>(1);
    first->_pNext = new Node<int>(2);
    first->_pNext->_pNext = new Node<int>(3);
    first->_pNext->_pNext->_pNext = new Node<int>(4);

    std::cout << "Original List: ";
    printList(first);

    Node<int>* reversed = reverse(first);

    std::cout << "Reversed List: ";
    printList(reversed);

    std::cout << "Original List: ";
    printList(first);

    // Free memory
    while (reversed != nullptr) {
        Node<int>* temp = reversed;
        reversed = reversed->_pNext;
        delete temp;
    }

    // Free original list
    while (first != nullptr) {
        Node<int>* temp = first;
        first = first->_pNext;
        delete temp;
    }

    return 0;
}
