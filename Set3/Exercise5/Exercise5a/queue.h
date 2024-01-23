/* standard array queue implementation */
#include <iostream>

using namespace std;

// The interface of queue
#define MAXN 5
template <class T>
class Queue {
private:
    T   *array;
    int number_of_items;

public:
    Queue();
    Queue(const Queue& q0);
    ~Queue();
    bool enqueue(T item);
    bool dequeue(T &item);
    void print();
};

// The implementation of queue
template <class T>
Queue<T>::Queue() {
    array = new T[MAXN];
    number_of_items = 0;
}

template <class T>
Queue<T>::Queue(const Queue &q0) {
    number_of_items = q0.number_of_items;
    if (number_of_items % 5 != 0) {
        array = new T[((number_of_items % 5) + 1) * MAXN];
    } else {
        array = new T[number_of_items];
    }
    for (int i = 0; i < number_of_items; i++) {
        array[i] = q0.array[i];
    }
}

template <class T>
Queue<T>::~Queue() {
    delete array;
}

template <class T>
bool Queue<T>::enqueue(T item) {
    if (number_of_items != 0 && number_of_items % 5 == 0) {
        Queue aux = *this;
        delete array;
        array = new T[number_of_items + MAXN];
        for (int i = 0; i < number_of_items; i++) {
            array[i] = aux.array[i];
        }
        array[number_of_items++]= item;
        cout << "\n\nSize is increased and is now " << number_of_items << " items.";
    } else {
        array[number_of_items++] = item;
    }
    return (true);
}

template <class T>
bool Queue<T>::dequeue(T &item) {
    int i;
    if (number_of_items == 0)
        return(false);
    else {
        item = array[0];
        for (i = 0; i < number_of_items-1; i++)
            array[i] = array[i+1];
        number_of_items--;
        return (true);
    }
}

template <class T>
void Queue<T>::print() {
    int i;

    cout << "\n\nQueue now: \n";
    for (i = 0; i < number_of_items; i++) {
        cout << " " << array[i] << "";
    }
    cout << "\n\n";
}
