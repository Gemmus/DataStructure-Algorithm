/* Extra exercise 4b. (Converting infix notation to postfix notation, 0.25 bonus)
Warning! This is quite demanding exercise.

Phase 2

Implement a better infix to postfix converter which allows also an infinite amount of
parenthesis that control the order of evaluation. For example

        Infix to postfix converter

        Give an infix equation at one line
        (((3+6+1)*(2-4))+7)
        Equivalent postfix equation is 36+1+24-*7+
*/

#include <iostream>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_LENGTH 80

using namespace std;

int precedence(const char& ch);
bool isOperand(const char& chr);
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

int precedence(const char& chr){
    switch(chr) {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

bool isOperand(const char& chr) {
    return ('+' == chr || '-' == chr ||'*' == chr || '/' == chr);
}

void infixTopostfix(char *infix, char *postfix) {
    Stack<char> stack;
    int i = 0, j = 0;
    char chr, aux;

    stack.push('(');
    strcat(infix, ")");

    chr = infix[i];

    while (chr != '\0') {
        if (chr == '(') {
            stack.push(chr);
        } else if (isdigit(chr)) {
            postfix[j++] = chr;
        } else if (isOperand(chr)) {
            stack.pop(aux);
            while (isOperand(aux) && precedence(aux) >= precedence(chr)) {
                postfix[j++] = aux;
                stack.pop(aux);
            }
            stack.push(aux);
            stack.push(chr);
        } else if (chr == ')') {
            stack.pop(aux);
            while (aux != '(') {
                postfix[j++] = aux;
                stack.pop(aux);
            }
        }
        chr = infix[++i];
    }

    postfix[j] = '\0';
}
