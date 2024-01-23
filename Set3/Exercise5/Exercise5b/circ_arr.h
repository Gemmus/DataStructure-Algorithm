#include <iostream>

using namespace std;

#define MAXN 100000

template <class Titem>
class Queue {
private:
    Titem array[MAXN];
    int first;
    int last;
    int number_of_items;
public:
    Queue();
    bool enqueue(Titem item);
    bool dequeue(Titem &item);
    void print();
};

template <class Titem>
Queue<Titem>::Queue() {
    first = 0;
    last = -1;
    number_of_items = 0;
}
template <class Titem>
bool Queue<Titem>::enqueue(Titem item) {if (number_of_items >= MAXN)return(false);
    else {
        if (++last > MAXN - 1) last = 0;array[last] = item;
        number_of_items++;
        return (true);
    }
}
template <class Titem>
bool Queue<Titem>::dequeue(Titem &item) {if (number_of_items == 0)
        return(false);
    else {
        item = array[first++];
        if (first > MAXN - 1) first = 0;number_of_items--;
        return (true);
    }
}
template <class Titem>
void Queue<Titem>::print() {
    int i, n;
    cout << "\nQueue now: \n\n";for (n = 1, i=first; n <= number_of_items ; n++) {cout << " " << array[i] << " ";i++;
        if (i > MAXN-1)
            i = 0;
    }
    cout << endl << endl;
}