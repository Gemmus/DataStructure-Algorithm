/*
The Fibonacci numbers Fn are defined recursively as follows:
 F0 = 1
 F1 = 1
 Fn = Fn-1 + Fn-2
a) Write a recursive function, which calculates a Fibonacci number Fn. The function receives n as a
parameter. (3p)
b) How many times does the function call itself, when n = 5 ? (1p)
c) What is the maximum number of parameters n simultaneously allocated on the processor stack
(when n = 5). (2p)
*/

// a)
#include <iostream>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 5;
    std::cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << std::endl;
    return 0;
}

// b)  15
//                              #1 Fibonacci(5) calls Fibonacci(4) and Fibonacci(3).
//              #2 F(4) calls F(3)         and  F(2)                                  #3 F(3) calls F(2) and F(1)
//    #4 F(3) calls F(2) and F(1)              #5 F(2) calls F(1) and F(0)            #6 F(2) calls F(1) and F(0)    #7 F(1) = 1
//  #8 F(2) calls F(1) and F(0) #9 F(1) = 1    #10 F(1) = 1       #11 F(0) = 1        #12 F(1) = 1  #13 F(0) = 1
//  #14 F(1) = 1  #15 F(0) = 0

// c) 6
