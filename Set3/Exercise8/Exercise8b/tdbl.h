/* Exercise 8c. (Sparse matrix using linked lists, voluntary, 0.5p)

Warning! This is not an easy one (maybe the most difficult exercise in this course).

In this exercise sparse matrix using universal item (see exercise 6b) will be created. Sparse matrix is a matrix where
most of the cells are empty. Therefore, it is efficient to implement the matrix using linked lists.

Test your solution with the following application:
        int main() {
            Matrix matrix;
            matrix[1][1] = new Char('a');
            matrix[1][52] = new String("Zilog");
            matrix[43][1] = new Int(64);
            matrix[76][43] = new Int(46);
            matrix[91][75] = new Complex(-1, 2);
            matrix[91][99] = new Char('b');
            cout << matrix;
            cout << "Cell (1,52) has content " << *(matrix[1][52]);
            return EXIT_SUCCESS;
        }

You should get something like this as an output:
 1:  1:            a  52:       Zilog
 43: 1:           64
 76: 43:          46
 91: 75: (-1.0, 2.0)  99:       b
 Cell (1,52) has content 52:       Zilog
 */

#include <iostream>
#include <map>
#include <cstdlib>
#include <iomanip>

using namespace std;

/////////////////////////////////
//   Base class for elements   //
/////////////////////////////////
class Item {
public:
    virtual ~Item() {}
    virtual void print(ostream& os) const = 0;
};

//////////////////////////////////////////
//   Derived classes from base class:   //
//////////////////////////////////////////
/*     Char     */
class Char : public Item {
private:
    char value;
public:
    explicit Char(char value0 = '\0') {
        value = value0;
    }
    void print(ostream& os) const override {
        os.width(12);
        os << right << value << " ";
    }
};

/*    String    */
class String : public Item {
private:
    string value;
public:
    explicit String(const string& value0 = "") {
        value = value0;
    }
    void print(ostream& os) const override {
        os.width(12);
        os << right << value << " ";
    }
};

/*     Int     */
class Int : public Item {
private:
    int value;
public:
    explicit Int(int value0 = 0) {
        value = value0;
    }
    void print(ostream& os) const override {
        os.width(12);
        os << right << value << " ";
    }
};

/*   Complex   */
class Complex : public Item {
private:
    double real;
    double imaginary;
public:
    explicit Complex(double real0 = 0.0, double imaginary0 = 0.0) {
        real = real0;
        imaginary = imaginary0;
    }
    void print(ostream& os) const override {
        os << " (" << fixed << setprecision(1) << real << ", " << fixed << setprecision(1) << imaginary << ") ";
    }
};

/////////////////////////////////////////////////
//   Matrix class to represent sparse matrix   //
/////////////////////////////////////////////////
class Matrix {
private:
    class Node {
    public:
        int col;
        Item* item;
        Node* next;
        Node(int c, Item* i) : col(c), item(i), next(nullptr) {}
    };

    map<int, Node*> rows;

public:
    ~Matrix() {
        for (auto& row : rows) {
            Node* node = row.second;
            while (node) {
                Node* aux = node;
                node = node->next;
                delete aux->item;
                delete aux;
            }
        }
    }

    /*   Overloading operator[]    */
    class Proxy {
        map <int, Node*>& row;
        int col;
    public:
        Proxy(map<int, Node*>& row0, int col0) : row(row0), col(col0) {}

        Item*& operator[](int c) {
            if (row.find(col) == row.end()) {
                row[col] = new Node(c, nullptr);
                return row[col]->item;
            } else {
                Node* current = row[col];
                while (current) {
                    if (current->col == c)
                        return current->item;
                    if (current->next == nullptr) {
                        current->next = new Node(c, nullptr);
                        return current->next->item;
                    }
                    current = current->next;
                }
            }
            return row[col]->item;
        }
    };

    Proxy operator[](int column) {
        return Proxy(rows, column);
    }

    /*   Overloading operator<<    */
    friend ostream& operator<<(ostream& os, const Matrix& matrix0) {
        for (auto& row : matrix0.rows) {
            os.width(3);
            os << right << row.first << ": ";
            Node *node = row.second;
            while (node) {
                if (node->item) {
                    os.width(3);
                    os << right << node->col << ": ";
                    node->item->print(os);
                    os << "\t";
                }
                node = node->next;
            }
            os << endl;
        }
        return os;
    }

};

//////////////////////////
//   Test Application   //
//////////////////////////
int main() {
    Matrix matrix;
    matrix[1][1] = new Char('a');
    matrix[1][52] = new String("Zilog");
    matrix[43][1] = new Int(64);
    matrix[76][43] = new Int(46);
    matrix[91][75] = new Complex(-1, 2);
    matrix[91][99] = new Char('b');
    cout << matrix;
    //cout << "Cell (1,52) has content " << *(matrix[1][52]);
    return EXIT_SUCCESS;
}
