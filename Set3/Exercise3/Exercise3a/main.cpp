/*  Exercise 3a. (Container implementation is independent of the item type to be stored, 1p)

If your class Time from the exercise 1 does not have the compare function (operator==), write and test it first. 
Overload also the read operator (>>) and implement a constructor with initial values as parameters, 
e.g. Time(int hour = 0, int min = 0).
 
At the lectures, we studied the simple list implementation using templates. The application was using the list to store 
characters. Now we use the same list (available as a list.h file from Oma) to store Time values.
 
From the Oma-portal you'll find a program main.cpp. This file contains the source code for a small application to test 
the Time valued list. Test first your Time class with the given test program main.cpp. Then implement a new operation 
function for the list.h container, bool insert_to_begin(T item)which adds a new item to the beginning of the list container.
After that change the line list.insert_to_end(item) to list.insert_to_begin(item) in order to test your new function.
 
Remark. Use your time as a component. This means that you should include the header file
time.h and add time.cpp to the application project.
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
        list.insert_to_begin(item);
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
