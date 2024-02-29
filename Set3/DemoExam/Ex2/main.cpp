/*
In a project, we manage “things”. All the data needed in managing things are included in the class
Thing. Because we can’t always process those things at the same rate as they are received, things
must be buffered, e.g. they must be placed in the queue. For that reason we have already available
the class ThingQueue and its operation functions

 ThingQueue();                              // constructor
 void deQueue(Thing &pThing);               // retrieves the thing from the queue
 void enQueue(const Tthing &thing);         // enters thing to the queue
 bool isEmpty();                            // check if the queue is empty
                                            // (result 1) or not (result 0)

We want to prioritize the management of the things. For this reason we need priority queue for the
things. Priority for the thing is given when it is entered to the queue. Possible priorities are
0,1,2,…,n-1, where the n is an integer number given in initializing the priority queue. When
retrieving things from the priority queue, things are ordered by their priorities (as needed in priority
queues) where 0 is the highest priority and n-1 the lowest priority.

One easy way to implement the priority queue is to use n (where n is the number of priorities)
ordinary queues and put those things to the internal queue based on the priority number. When
retrieving things, entry is removed from the highest priority queue which has something in it.
Your task is to implement the priority queue for the things using the above mentioned principle.
Define the class PriQueue and implement its operation functions. (6p)
        PriQueue(int n);
        void dequeuePri(Tthing &pThing);
        void enqueuePri(const Tthing &thing, int priority);
        bool isPriEmpty();
*/

#include <iostream>
#include <vector>
#include <queue>

template <class Tthing>
class PriQueue {
private:
    int numPriorities;
    std::vector<std::queue<Tthing>> queues;

public:
    PriQueue(int n) : numPriorities(n) {
        queues.resize(n);
    }

    void enqueuePri(const Tthing &thing, int priority) {
        if (priority >= 0 && priority < numPriorities) {
            queues[priority].push(thing);
        } else {
            std::cerr << "Invalid priority!" << std::endl;
        }
    }

    void dequeuePri(Tthing &pThing) {
        for (int i = 0; i < numPriorities; ++i) {
            if (!queues[i].empty()) {
                pThing = queues[i].front();
                queues[i].pop();
                return;
            }
        }
        std::cerr << "Priority queue is empty!" << std::endl;
    }

    bool isPriEmpty() {
        for (int i = 0; i < numPriorities; ++i) {
            if (!queues[i].empty()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Example usage
    PriQueue<std::string> pq(3); // Creating a priority queue with 3 priorities

    pq.enqueuePri("High priority thing", 0);
    pq.enqueuePri("Medium priority thing", 1);
    pq.enqueuePri("Low priority thing", 2);

    std::string thing;
    while (!pq.isPriEmpty()) {
        pq.dequeuePri(thing);
        std::cout << "Processing: " << thing << std::endl;
    }

    return 0;
}
