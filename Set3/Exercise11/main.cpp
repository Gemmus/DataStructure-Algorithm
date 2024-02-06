/*             Exercise 11E. (Voluntary exercise, Binary search tree, 1p)

We studied the principles of binary search in the class. Implement the class binary search tree. It means that you have
to define a class BinSTree and write the following operation functions (in this exercise only these three are required):

    constructor (initializes the tree)
    insert_to_tree (insert an item to binary search tree)
    isInTree (finds out whether the item is in tree or not)

Our search tree stores integer numbers, but remember that the implementation should be independent of the item type.

Test your search tree in the following way. Write a program, that generates 10000 integer random numbers between
[0, 10000) and stores them to the binary search tree. Because numbers to be inserted are generated in random, there is
no need to balance the tree. After inserting the numbers the program enters the loop, where it asks the user to enter
integer numbers one at a time. When a number is entered, the program finds out, whether the number is in tree or not.
It prints the result of the search. It is interesting to know, how many comparisons are needed in each case.
Calculate inside the isInTree function, how many comparisons were needed before the item was found or it became clear
that it is not in the tree. Print this information to the screen at the end of function isInTree.

Remark1. The goal of the exercise is not only to get the program to work. It is also to learn to understand the concept
of binary search tree a bit more thoroughly. When you run the program try to search different kinds of numbers from the
whole range. Enter numbers which are in tree and numbers which are not. What is the largest number of comparisons needed
and what is the smallest. What does it mean?

Hint. C-standard library (stdlib.h) contains a pseudo-random generator srand() and rand() functions1. srand() is used to
initialize the generator (if you don’t initialize the generator, it will always generate the same “random” sequence).
rand() returns the random integer value between 0 – MAX_RAND.

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int main() {
        int i;
        srand(time(NULL)); // initializes the pseudorandom number generator
        // generates 10000 random numbers
        for (i = 0; i < 10000; i++)
        printf(“%d\n”, rand() % 10000); // generates a random number between 0 – 9999
    }

Here is a demo output of one solution (note that the number of items inserted to the tree is smaller than required to be
able to show the tree in graphical format, and note that the queries to the search tree are automated):

BST exerciser (51 items stored to the tree, 51 items searched for)

Numbers inserted to the BST:
17 15 35 28 46 37 33 40 15 13 26 43 37 30 8 17 31 2 50 25 2 12 3 9 26 36 50 42 0 35 15 28 49 3 28 44 17 8 1 43 19 47 46 28 25 31 26 9 44 37 44

 0: found 6 comparision needed
 1: found 7 comparision needed
 2: found 5 comparision needed
 3: found 6 comparision needed
 4: not found 6 comparision needed
 5: not found 6 comparision needed
 .
 .
 . 
 45: not found 7 comparision needed
 46: found 3 comparision needed
 47: found 6 comparision needed
 48: not found 6 comparision needed
 49: found 5 comparision needed
 50: found 4 comparision needed

Theoretical number of comparisions needed is 5.7
Average number of actual comparisions is 4.7
Min depth 2, Max depth 7
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define MIN 0
#define MAX 10000 // 10 // testing purpose

using namespace std;

template <typename T>
class BinSTree {
private:

    class Node {
    public:
        T _value;
        Node* _pLeft;
        Node* _pRight;
        explicit Node(T _value0) {
            _value = _value0;
            _pLeft = nullptr;
            _pRight = nullptr;
        }
    };

    Node *root;

    Node* insertNode(Node* root0, T data0) {
        if (root0 == nullptr) {
            return new Node(data0);
        }

        if (data0 < root0->_value) {
            root0->_pLeft = insertNode(root0->_pLeft, data0);
        } else if (data0 > root0->_value) {
            root0->_pRight = insertNode(root0->_pRight, data0);
        }
        
        return root0;
    }
    
    void searchNode(Node* root1, T data1, int& count) {
        count++;

        if (root1 == nullptr) {
            cout << setw(5) << right << data1 <<  ": " << setw(10) << right << "not found " << count << " comparison needed" << endl;
            return;
        }

        if (root1->_value == data1) {
            cout << setw(5) << right << data1 << ": " << setw(10) << right << "found " << count << " comparison needed" << endl;
            return;
        }

        if (data1 < root1->_value) {
            searchNode(root1->_pLeft, data1, count);
        } else {
            searchNode(root1->_pRight, data1, count);
        }
    }

public:
    BinSTree() : root(nullptr) {}

    void insert_to_tree(T _data) {
        root = insertNode(root, _data);
    }

    void isInTree(T _data, int& count) {
        searchNode(root, _data, count);
    }
};

int main() {
    //srand(1); // 5 8 7 4 8 1 3 0 7 2 for testing purpose, MAX is set for 10
    /*                    5
                        /  \
                       4    8
                      /    /
                     1    7
                   /  \
                  0    3
                      /
                     2
    */

    srand(time(nullptr));
    BinSTree<int> bst;
    int toBeSearched, num, numCmp, min_depth, max_depth, n = 0;
    double sum = 0;

    cout << "Generating " << MAX << " random numbers." << endl;
    //cout << "Generating " << MAX << " random numbers: "; // for testing purposes
    for(int i = MIN; i < MAX; i++) {
        num = rand() % MAX;
        //cout << num << " "; // for testing purposes
        bst.insert_to_tree(num);
    }

    cout << "\nEnter number to be searched for (or -1 to exit): ";
    while (cin >> toBeSearched && toBeSearched != -1) {
        numCmp = 0;
        bst.isInTree(toBeSearched, numCmp);
        if (numCmp > max_depth) max_depth = numCmp;
        if (numCmp < min_depth) min_depth = numCmp;
        sum+= numCmp; n++;
        cout << "Enter number to be searched for (or -1 to exit): ";
    }

    cout << "\nTheoretical number of comparisons needed is 13.3" << endl;
    cout << "Average number of actual comparisons is " << setprecision(2) << sum / n<< endl;
    cout << "Min depth " << min_depth << ", Max depth " << max_depth << endl;

    return 0;
}
