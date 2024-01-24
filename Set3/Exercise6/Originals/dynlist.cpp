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
