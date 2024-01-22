/* Exercise 4a. (RPN-calculator; how to use a given ADT stack)

Write an RPN-calculator program. The program can be used for simple arithmetic operations for integers (they can be one
digit integers if you like). The possible arithmetic operations are: + and - (addition and subtraction). The two other
operators user can enter are = and Q). You have to use the stack component template programmed ready for you. The
interface and the implementation are in the file stack.h, which is available from the Oma-portal.

The application you must create, reads integers and operators from the keyboard in postfix form. All numbers read are
pushed onto the stack. When arithmetic operator + or - is encountered, the corresponding calculation is performed for
operands popped from the stack. The result is pushed back onto the stack. The operation = in the input stream means
"print the result to the screen". In practice, it is: pop the topmost value from the stack and print the value to the
screen (and push it back to the stack). You must be able to continue the calculation (from the previous intermediate
result). That’s why you have to push the printed result back to the stack. The operator Q means that the content of the
stack is printed to the screen and the program terminates.

Example: If you enter the following data to your program you will get the results below:
This is an RPN calculator. Enter operands and operators:
 Input    |        Output
---------------------------------------------------
 1        |
 2        |
 3        |
 +        |
 =        |       top value is 5
 2        |
 -        |
 =        |       top value is 3
 1        |
 +        |
 =        |       top value is 4
 Q        |       stack contained
 4        |
 1        |

Hint. If you use >> operator to read characters, you get char type results1. Because you can use one-digit numbers, it
is easy to make conversion from character input to the integers (int), because codes of digits 0, 1, 2, ..., 9 are
correspondingly 48, 49, 50, ..., 57 in the used encoding system (UTF-8 or ASCII). This means that if you get input in
the form:
       cin >> input; // input is defined as: char input;

then you get the corresponding int value in the following way:
       if (isdigit(input))
            number = input - 48; // or number = input - '0'
where the variable number is declared as: int number;. isdigit() a standard macro, and it is defined in <ctype.h>
*/

#include <iostream>
#include <ctype.h>
#include "stack.h"

using namespace std;

int main() {

    Stack<int> stack;
    int digit, digit1, digit2;
    char input;
    bool not_quit = true;

    cout << "This is a RPN calculator. Enter operands and operators:" << endl;

    while (not_quit) {
        cin >> input; cin.ignore(1);
        if ('Q' == input) {
            cout << "\nQuiting. ";
            if (stack.readTop() != -1) {
                stack.print();
            } else {
                cout << "Stack is empty." << endl;
            }
            not_quit = false;
        } else if (isdigit(input)) {
            digit = input - '0';
            stack.push(digit);
        } else if ('+' == input || '-' == input) {
            if (stack.readTop() > 0) {
                stack.pop(digit1); stack.pop(digit2);
                if ('+' == input ) {
                    stack.push(digit2 + digit1);
                } else {
                    stack.push(digit2 - digit1);
                }
            } else {
                cout << "Operation " << input << "cannot be executed, not enough operands on stack." << endl << endl;
            }
        } else if ('=' == input) {
            stack.topValue();
        } else {
            cout << "Invalid input. ";
        }
    }

    return 0;
}
