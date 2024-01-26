/* Exercise 7a. (More operation functions for dynamically linked list)

In exercise 6 you implemented some operation functions for dynamically allocated linked list. The type definition of
LinkedList was
        template <class T>
        class LinkedList {
        private:
            // definition of the list node class
            class Node {
                …
            };

            Node *first; // no *last variable
            // in this implementation!!
             …
        };

Continue to develop further the program of exercise 8. Write the following operation functions for a character list:
        void delete_first();
        void delete_last();
        bool find_pos(T item, int &pos);

The find_pos function returns true if item is found and false otherwise. If the item is found the order number of it is
passed to the caller in the parameter pos.
*/

#include <iostream>
#include "dynlist.h"

using namespace std;

// Application
int main() {
    LinkedList<char> list;
    int order_no;
    char to_be_searched;
    list.delete_last();
    list.insert_to_end('?');
    list.delete_last();
    list.insert_to_end('x');
    list.insert_to_end('a');
    list.insert_to_end('b');
    list.insert_to_end('c');
    list.insert_to_end('d');
    list.insert_to_end('y');
    cout << list;
    cout << "Enter first character to be searched: \n";
    cin >> to_be_searched;
    if (list.find_pos(to_be_searched, order_no))
        cout << "The order no is " << order_no << endl;
    else
        cout << "Character " << to_be_searched << " not found.\n";
    cout << "Enter second character to be searched: \n";
    cin >> to_be_searched;
    if (list.find_pos(to_be_searched, order_no))
        cout << "The order no is " << order_no << endl;
    else
        cout << "Character " << to_be_searched << " not found.\n";
    list.delete_first();
    cout << list;
    list.delete_last();
    cout << list;
    return (EXIT_SUCCESS);
}
