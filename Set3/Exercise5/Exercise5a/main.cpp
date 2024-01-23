/*  Exercise 5a. (Automatically expanding simple queue)

The simplest way to implement a queue is to use an array as a storage for queued elements. In the enqueue() operation a
new item is always put as the last element and the number of elements is incremented. In the dequeue() operation an item
is always taken from the beginning of the array (index 0) and all other items are moved forward in the array. This is not
the most efficient way, because data needs to be moved in each dequeue() operation. But anyway, it is very easy to
understand, because it behaves like the real queue of persons in the bank for example (all people take one step forward,
when one customer moves to get the service). We saw the data definition and basic principles of how operation functions
of this kind of queue can be implemented. You can find this kind of working queue (queue.h) and a test program (main.cpp)
from the Oma-portal. This queue uses fixed sized array, so that the program gives an error message, if you try to enqueue
data when the queue is full.

It is possible to modify the queue to automatically expand its size when needed. Dynamic memory (e.g. new and delete
–operations) is needed here. Start for example with the queue size of 5 (when the queue is initialized allocate space
for five elements) and every time when more space is needed, automatically increase the size of the array by 5 for
example. In order to increase the size you need to do the following tasks:
        1. Create a new array with larger size
        2. Copy all elements from the old (smaller) array to the new (larger) array
        3. Release (delete) the old array from the memory
        4. Switch to use the new array (copy address of the new array to the place of array
           pointer)
        5. Update the new size information of the new array
To make testing easy, put an output like "size is increased and is now xx items" to the enqueue() operation, when size
is increased to make it easier to follow the working of your program. Do not also use global variables in your solution,
and don’t ever decrease the size of the array in enqueue() operation.

The most important principle here is that expanding really is automatic. It is automatic for the user of the queue. The
use of the queue is as easy as before. The only difference for the user is that enqueue() function never returns false,
because enqueue() operation always succeeds (assuming that the operating system has infinite amount of memory available).

Download the program queue.h and main.cpp from the Oma portal and compile and run them so that you understand how they work.
After that do all modifications needed to make the queue automatically expandable.

Remark 1. Do not modify the main program (main), because you still can use it to test your more advanced queue. This also
means that you must not modify the prototypes of the operation functions of the queue. The implementation of operation
functions of course needs modifications because we need to move to use dynamic array instead of fixed size array.
*/

/* simple test program to test the queue implementation */
#include <iostream>
#include <conio.h>
#include "queue.h"

using namespace std;

// Application
int main() {
    Queue<char> queue;
    bool        succeed;
    char        chr;

    cout << "\nEnter a letter to be queued ";
    cout << "\nor digit 1 to dequeue a letter";
    cout << "\nor Return to quit a program\n";

    chr = _getche();
    while (chr != '\n' && chr != '\r') {
        if (isalpha(chr)) {
            succeed=queue.enqueue(chr);
            queue.print();
            if (!succeed)
                printf("\nEnqueue operation failed\n");
        }
        if (chr == '1') {
            succeed = queue.dequeue(chr);
            if  (succeed) {
                cout << "\na letter dequeued " << chr << " ";
                queue.print();
            } else
                cout << "\nDequeue operation failed\n ";
        }
        chr = _getche();
    }

    return 0;
}
