/* Exercise 6b. (Extra, Universality of the dynamically allocated linked list, 0.25p)

Warning: this exercise requires good knowledge of C++ polyformism (i.e. this is quite a demanding exercise).

In this exercise we demonstrate that it is possible to store different kind of data items to
the given dynlist.h list template implementation. This utilization of the linked list rely on
the C++ polyformism concept where one pointer can point to different kind of objects if
they are related (inheriting classes can be pointed by the parent class pointer).
Now the object to be stored to the linked list is as follows
class NodeData {
    friend ostream& operator<< (ostream& stream, const NodeData *p);
    public:
    virtual ostream& print(ostream &stream) const = 0;
    virtual bool operator<(NodeData *) = 0;
};

And the main program is
int main() {
    LinkedList<NodeData *> list;
    list.insert_to_end(new String("First complex number")).insert_to_end(new Complex(1, 3));
    list.insert_to_end(new String("Second complex number")).insert_to_end(new Complex(5, 9));
    list.print();
}

Your task is to make the given main function given NodeData class, and given dynlist.h
linked list implementation work together by defining the missing String and Complex
classes and output operator for the NodeData. String class stores strings (you can use the
standard C++ string class for that) and Complex stores complex values (real and
imaginary part represented by two float numbers).
*/

#include <iostream>
#include <string>
#include "dynlist.h"

using namespace std;

class NodeData {
    friend ostream& operator<< (ostream& stream, const NodeData *p) {
        return p->print(stream);
    }
public:
    virtual ostream& print(ostream &stream) const = 0;
    virtual bool operator<(NodeData *) = 0;
};

class String : public NodeData {
public:
    String(const string& string0) {
        data = string0;
    }

    ostream& print(ostream& stream) const override {
        return stream << data << endl;
    }

    bool operator<(NodeData* other) override {
        return false;
    }

private:
    string data;
};

class Complex : public NodeData {
public:
    Complex(int real0, int imaginary0) {
        real = real0;
        imaginary = imaginary0;
    }

    ostream& print(ostream& stream) const override {
        if (imaginary < 0) {
            return stream << real << " + " << imaginary * -1 << "i" << endl;
        } else {
            return stream << real << " + " << imaginary << "i" << endl;
        }
    }

    bool operator<(NodeData* other) override {
        return false;
    }

private:
    int real;
    int imaginary;
};

// Application
int main() {
    LinkedList<NodeData *> list;
    list.insert_to_end(new String("First complex number")).insert_to_end(new Complex(1, 3));
    list.insert_to_end(new String("Second complex number")).insert_to_end(new Complex(5, 9));
    list.print();
    return 0;
}
