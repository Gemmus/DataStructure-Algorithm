/* Extra exercise 4b. (Converting infix notation to postfix notation, 0.25 bonus)
Warning! This is quite demanding exercise.

Phase 1

Make an application which converts infix-equations to postfix-format. Operands are onedigit positive integer numbers and
operators are ‘+’, ‘-‘, ‘*’ and ‘/’. There are no parenthesis allowed in this phase. First the application reads one line
of characters (max 80 characters) containing an infix-equation and then converts that to the matching postfix format.
It is useful to implement a function void infixTopostfix(char *infix, char *postfix) that creates postfix equation in
string from the given infix string.

One example how the application should work
         Infix to postfix converter

         Give an infix equation at one line
         1+2*3
         Equivalent postfix equation is 123*+

Hint 1: In the lecture we studied how the infix to postfix conversion can be done. Small recap here: Infix equation is
processed from the left to the right, symbol-by-symbol. When we encounter an operand it is appended to the postfix
equation directly. For handling operators we need an operator stack. When we encounter an operator (in the infix notation)
we should check if there exist higher-priority operators in the stack. If there are, then operators are pop’d from the
stack and appended to the postfix equation until there are no higher priority operators left on the stack. Then the just
read operator is push’d to the stack. After we have scanned the whole input infix equation, remaining operators on the
stack are appended to the postfix equation.

Hint 2: It would be a good idea to implement a special function for operator’s precedence comparision.
*/

#include <iostream>
#include <ctype.h>
#include "stack.h"

#define MAX_LENGTH 80

using namespace std;

void infixTopostfix(char *infix, char *postfix);

int main() {

    char infix[MAX_LENGTH], postfix[MAX_LENGTH];

    cout << "Infix to postfix converter" << endl << endl;
    cout << "Give an infix equation at one line" << endl;
    cin.getline(infix, MAX_LENGTH);

    infixTopostfix(infix, postfix);

    cout << "Equivalent postfix equation is " << postfix << endl;

    return 0;
}

void infixTopostfix(char *infix, char *postfix) {
    Stack<char> stack;
    int i = 0, j = 0;
    char chr;

    while (infix[i] != '\0') {
        chr = infix[i++];
        if(isdigit(chr)) {
            postfix[j++] = chr;
        } else if ('+' == chr || '-' == chr ||'*' == chr || '/' == chr) {
            stack.push(chr);
        }
    }
    for (int k = 0; k <= stack.readTop() + 1; k++) {
        stack.pop(postfix[j++]);
    }
    postfix[j] = '\0';
}
