/*   Exercise 10 (Function objects, 1p)

Modify and improve the random number generator from the lecture slides to create a lotto program in the following ways:

First generate a set of 7 individual lotto numbers (in range 1 - 37) using the scheme shown at the lecture. Then print
them. In the exercise 10 you used for loop to display numbers from the container. Do it now without a loop by using the
output stream iterator.

After generating and printing lotto numbers, generate another, separate lotto number sequence and display it.

Then compare those lotto number sequences and print similar numbers (still without a loop, using for_each() algorithm
instead) as a list (smallest first, here we have numbers 1, 11 and 24 in both of the lists):

First lotto row: 1 12 24 36 11 15 32
Second lotto row: 24 7 29 11 18 35 1
Same numbers:
#1: 1
#2: 11
#3: 24

Hint: set_intersection() algorithm may be useful to find out similar numbers
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#define MIN 1
#define MAX 37
#define LOTTO_N 7

using namespace std;

class RandomGenerator {
public:
    RandomGenerator(int min0, int max0) {
        min = min0;
        max = max0;
    }

    int operator()() {
        int number;
        do {
            number = rand() % max + min;
        } while(find(numbers.begin(), numbers.end(), number) != numbers.end());
        numbers.push_back(number);
        return number;
    }

private:
    int min;
    int max;
    vector<int> numbers;
};

class CountPrinter {
public:
    CountPrinter() {
        count = 0;
    }

    void operator()(int num) {
        cout << "\n#" << ++count << ": " << num;
    }

private:
    int count;
};

int main() {
    srand(time(nullptr));

    vector<int> lottoVector1(LOTTO_N);
    vector<int> lottoVector2(LOTTO_N);
    vector<int> matching;

    // Generating Lotto1 numbers:
    generate(lottoVector1.begin(), lottoVector1.end(), RandomGenerator(MIN, MAX));
    cout << "First lotto row: ";
    copy(lottoVector1.begin(), lottoVector1.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    // Generating Lotto2 numbers:
    generate(lottoVector2.begin(), lottoVector2.end(), RandomGenerator(MIN, MAX));
    cout << "Second lotto row: ";
    copy(lottoVector2.begin(), lottoVector2.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    // Matching numbers of lotto1 and lotto2:
    sort(lottoVector1.begin(), lottoVector1.end());
    sort(lottoVector2.begin(), lottoVector2.end());
    set_intersection(lottoVector1.begin(), lottoVector1.end(), lottoVector2.begin(), lottoVector2.end(), back_inserter(matching));
    cout << "Same numbers:";
    for_each(matching.begin(), matching.end(), CountPrinter());
    cout << endl;

    return 0;
}
