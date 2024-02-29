/*
A binary search tree is defined as a pointer to the following class
template <class T>
class Node {
    Node *left,*right;
    T item;
    Node(): left(NULL), right(NULL) {};
};

Write a class Tree which contains a constructor, operating function insert_node(T data) that
creates a new node and put the given data to it and returns pointer to the created node (2p), and
the destructor using recursion which releases all memory resources reserved by the tree (4p).
*/

#include <iostream>

template <class T>
class Node {
public:
    Node<T> *left, *right;
    T item;
    Node() : left(nullptr), right(nullptr) {};
};

template <class T>
class Tree {
private:
    Node<T>* root;

    void deleteSubtree(Node<T>* node) {
        if (node == nullptr) return;

        deleteSubtree(node->left);
        deleteSubtree(node->right);
        delete node;
    }

public:
    Tree() : root(nullptr) {}

    Node<T>* insert_node(T data) {
        Node<T>* newNode = new Node<T>();
        newNode->item = data;

        if (root == nullptr) {
            root = newNode;
        } else {
            Node<T>* current = root;
            Node<T>* parent = nullptr;
            while (current != nullptr) {
                parent = current;
                if (data < current->item) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (data < parent->item) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        return newNode;
    }

    ~Tree() {
        deleteSubtree(root);
    }
};

int main() {
    Tree<int> tree;
    tree.insert_node(5);
    tree.insert_node(3);
    tree.insert_node(7);
    // Other operations

    // Destructor of Tree will be automatically called when tree goes out of scope
    return 0;
}
