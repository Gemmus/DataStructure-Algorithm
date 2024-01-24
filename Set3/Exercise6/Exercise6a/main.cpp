/* Exercise 6a. (Dynamically allocated linked list)

An address of the first node is capable to represent the whole list in dynamic memory, provided that the next member in
the last node is NULL to indicate the end of the list. In this case the data type Tlist of class LinkedList can be defined
as follows:
        template <class T>
        class LinkedList {
        private:
            // definition of the list node class
            class Node {
                …
            };
            Node *first; // no *last variable in this implementation!!
            …
        };

When operation functions are defined for that type we get the class LinkedList. Write the
following operation functions for the class LinkedList defined above:

        LinkedList();
        ~LinkedList();
        LinkedList<T>& insert_to_end(T data);
        void print(std::ostream &out = std::cout) const;

Start working from the given example program (dynlist.h and dynlist.cpp, available from the Oma-portal). This list is a
genuine ADT including the test application. First check how the program works, then modify the class definition by
removing the *last variable in the LinkedList class definition and modify the list implementation in such a way that it
works again.
*/

/* dynlist.cpp -- Dynamic linked linear list */

#include <iostream>
#include "dynlist.h"

using namespace std;

// Application
int main (void)  {
    LinkedList<char> list;

    list.insert_to_end('a').insert_to_end('b').insert_to_end('c').insert_to_end('d');

    cout << list;
}
