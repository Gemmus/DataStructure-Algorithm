/*  Extra Exercise 5b. (Automatically expanding circular buffer queue, 0.25p)

In the simple queue implementation data needs to be moved in each dequeue() operation. Therefore, the implementation is
not very efficient. To improve the operation of the queue, implement the queue using the circular buffer technique
presented in the lectures. Notice that this implementation must also be automatically expanding, i.e. when the space for
the queue fills, more space will be allocated (this is not so easy task in this case).

Use the given (below) test application to measure the time it takes for the dequeue() operation. For a very high-performance
system, this test application does not give accurate measurements. For the Metropolia Virtual Machine system, accuracy of
the performance measurement is enough. Measure the time consumed in the dequeue() operation function in the original simple
array and this circular queue implementations. Then calculate how many times better the circular implementation is compared
to the array implementation. Ensure also that your program works by checking that the last item value is ok.

Remark 1. Efficient memory allocation would need also automatically shrinking mode. When there is about 20% free space in
the queue, some memory should be released (not required in this exercise).

Remark 2. Parameter N is chosen for the Metropolia's virtual machine. It may need to be increased in higher performance environments.
*/

/*
 * Performance measurement application for the queue.
 *
 * Not a very accurate measurement system if the dequeue() function is relative short (compared to the time consumed in for-loop).
 *
 * In order to run this program in Visual Studio 2012 select
 * Debug-Start-without-Debugging (or pressing Ctrl-F5)
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

//#include "circ_arr.h"

#include "queue.h"


using namespace std;

#define N 100000 // number of elements inserted/retrieved from the queue, must be even

int main() {
    Queue<int> queue;
    int item;
    clock_t tic, tac;
    double duration;
    int i;
    // first we play a little with the queue to test that it really works
    cout << "Fill the queue with " << N << " items\n";
    item = 0;
    for (i = 0; i < N; i++) {
        if (!queue.enqueue(item++)) {
            cerr << "Enqueue failed\n";
            exit(1);
        }
    }
    cout << "Remove half of them\n";
    for (i = 0; i < N/2; i++) {
        if (!queue.dequeue(item)) {
            cerr << "Dequeue failed\n";
            exit(1);
        }
    }
    cout << "Add then new " << N/2 << " items to the queue\n";
    item++;
    for (i = 0; i < N/2; i++) {
        if (!queue.enqueue(item++)) {
            cerr << "Enqueue failed\n";
            exit(1);
        }
    }
// then we deque elements and measure the execution time
    cout << "Then dequeue them\n";
    tic = clock();
    for (i = 0; i < N; i++)
        queue.dequeue(item);
    tac = clock();
    cout << "Last item value " << item << " (should be " << N-1 << ")\n";
    cout << "(tic " << tic << ", tac " << tac << ")\n";
    duration = (double)(tac - tic) / CLOCKS_PER_SEC;
    cout << "\ndequeue took " << duration / (double)N*1e6 << " us to run\n";
}