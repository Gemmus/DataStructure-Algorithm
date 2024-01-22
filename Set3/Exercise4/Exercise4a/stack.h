//Interface for ADT stack
#define MAXN 80

using namespace std;

template <class T>
class Stack {
private:
    T   array[MAXN];
    int top;
public:
	Stack();
	bool push(T item);
	bool pop(T &item);
	void print();
    int readTop();
    void topValue();
};


// Implementations of operation functions
template <class T>
Stack<T>::Stack() {
    top = -1;
}

template <class T>
bool Stack<T>::push(T item) {
    if (top >= MAXN - 1)
        return(false);
    else {
        array[++top] = item;
        return (true);
    }
}

template <class T>
bool Stack<T>::pop(T &item) {
    if (top == - 1)
        return(false);
    else {
        item = array[top--];
        return (true);
    }
}

template <class T>
void Stack<T>::print() {
    int i;

    cout << "\nStack contained: ";
        for (i = top; i >= 0 ; i-- )
            //cout << endl << array[i];
            cout << " " << array[i];

	cout << endl << endl;
}

template <class T>
int Stack<T>::readTop() {
    return top;
}

template <class T>
void Stack<T>::topValue() {
    cout << "Top value is " << array[top] << endl;
}
