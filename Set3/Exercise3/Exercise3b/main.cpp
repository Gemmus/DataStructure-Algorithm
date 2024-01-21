/*  Extra exercise 3b. (Ordered list, 0.25p)

In this exercise we add another operation function, list.insert(item), to the list.
This operation function insert an item to the list in such a way that the list is always ordered (smallest item first).
In this exercise you need to have comparison operator (operator<) implemented in your Time class.
Verify that the list is always in order.
*/

#include <iostream>
#include "time.h"
#include "list.h"

using namespace std;

//Application
int main () {
    List<Time> list;
    Time       item;
    int        i = 0;

    cout << "Enter items (hh mm)? ";
    cin >> item;
    while (!(item == Time(0, 0))) {
        //list.insert_to_begin(item);     // Exercise 3a
        //list.insert_to_end(item);       // Testing
        list.insert(item);              // Exercise 3b
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
