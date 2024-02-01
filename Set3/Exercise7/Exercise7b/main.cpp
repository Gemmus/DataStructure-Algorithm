/* Exercise 7b. (Extra exercise, Ordered dynamically linked list, 0.25p)

In the exercise 3b we practiced with an ordered list. That ordered list was implemented using a simple array implementation.
Implement now that ordered list using linked list structure. Add the list.insert(item) function to the lab7a program.
This operation function insert an item to the list in such a way that the list is always ordered (smallest item first).
Use the same test program than in lab3b, this demonstrates again benefits of abstraction and generality paradigm. We can
modify the internal operation of the list totally, and there is no need to modify the user (main program) of the list at all.
*/

#include <iostream>
#include "dynlist.h"
#include "time.h"

using namespace std;

// Application
int main () {
    LinkedList<Time> list;
    Time       item;
    int        i = 0;

    cout << "Enter items (hh mm)? ";
    cin >> item;
    while (!(item == Time(0, 0))) {
        list.insert(item);
        //list.insert_to_begin(item);
        //list.insert_to_end(item);
        cin >> item;
    }
    //Print the contents of the list
    for (i = 1; i <= list.size(); i++)
        cout << "\n " << i << "th item was " << list[i];
    cout << "\nDelete list items (hh mm)? ";
    cin >> item;
    while (!(item == Time(0, 0))) {
        if(list.find_pos(item, &i)) {
            cout << "\nThe position of the item in list is " << i << "." << endl;
            list.del(i);
        } else
            cout << "\nItem not found.";
        cin >> item;
    }

    //Print the contents of the list
    for (i = 1; i <= list.size(); i++)
        cout << "\n " << i << "th item was " << list[i];
    cout << endl;

    return 0;
}
