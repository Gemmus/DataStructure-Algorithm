/* Extra exercise 4b. (Converting infix notation to postfix notation, 0.25 bonus)
Warning! This is quite demanding exercise.

Phase 3

Implement a calculator for one-digit integers. Modify your RPN-calculator (exercise 6a) in such a way that it can accept
string as an input, and add * and / operations to the RPN calculator. This RPN-calculator function can be declared as
follows int evaluatepostfix(char *postfix). Then give the converted postfix string from the
previous phase 2 to the RPN-calculator function and print the result, like

        Infix to postfix converter and calculator

        Give an infix equation at one line
        (1+2)*(3+4)
        Equivalent postfix equation is 12+34+*
        And it's value is 21
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
int evaluatepostfix(const char *postfix);

int main() {

    char infix[MAX_LENGTH], postfix[MAX_LENGTH];
    int result;

    cout << "Infix to postfix converter and calculator" << endl << endl;
    cout << "Give an infix equation at one line" << endl;
    cin.getline(infix, MAX_LENGTH);

    infixTopostfix(infix, postfix);
    cout << "Equivalent postfix equation is " << postfix << endl;
    result = evaluatepostfix(postfix);
    cout << "And it's value is " << result << endl;

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

int evaluatepostfix(const char *postfix) {
    Stack<int> stack;
    int i, digit1, digit2, result;

    i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            stack.push(postfix[i++] - '0');
        } else {
            stack.pop(digit1);
            stack.pop(digit2);
            switch (postfix[i++]) {
                case '+':
                    stack.push(digit2 + digit1);
                    break;
                case '-':
                    stack.push(digit2 - digit1);
                    break;
                case '*':
                    stack.push(digit2 * digit1);
                    break;
                case '/':
                    stack.push(digit2 / digit1);
                    break;
            }
        }
    }

    stack.pop(result);
    return result;
}
