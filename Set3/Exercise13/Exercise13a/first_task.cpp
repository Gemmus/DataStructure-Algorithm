/*    Exercise 13a. (Extra exercise, Implement brute force 0/1 knapsack resolving algorithm, 1p)

In an 0/1 knapsack problem an instance consists of a set of N items with weights wi and values vi, for i=1 to N, and an
integer, C, the carrying capacity of the knapsack. A solution to the problem is a subset of items having a total weight
less than or equal to C that is maximal in total value (among all such subsets). The problem above is "0/1" because we
either do carry an item: "1"; or we don't: "0".

First task: Input/Output
Write a program that reads in a knapsack problem instance text file written in the form
N
1 v1 w1
2 v2 w2
. . .
. . .
N vN wN
C

Test your code by reading in the knapsack problem instance easy20.txt and then write the instance to the screen for
visual inspection.

Second task: Full Enumeration (brute force search)
The 0/1 problem can be solved by a full enumeration of the search space. Every binary string of length N represents a
valid candidate solution.

Adding to your code from the previous part, write a program that loops through every possible binary value of length N
and evaluates the value and weight of each of these solutions. Note that your solution should work with an arbitrary
large value of N (e.g. 200).

Output upon termination, the program should output the following:
Optimal solution found: <value> <weight>
<item> <item> <item> ...

where the items are the indexes of the items to be placed in the knapsack, listed in ascending index order.

You could also get the program to output something to show its progress, i.e. the fraction of the search space it has
enumerated. E.g. every 1,000,000 solutions evaluated it could output a line like "Y % of the search space enumerated so far".

Run your code on easy20.txt. You should get the answer in very short time even your program tried 220=1048576 different
combinations of items. The correct answer (optimal solution) is 726 value units and combined weight is 519.

Then run your code on hard33.txt. Now there are 233=8589934592 combinations (213=8192 times more). Running time is about
14-15 minutes with Intel i5-6600K 3.5 GHz, compiled with fully optimization).

You may be tempted to try easy200.txt. Running brute force search algorithm requires about 6,11045 years to complete
(the remaining time for the universe is estimated to be 26x10^9 years).
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Item {
    friend ostream& operator<<(ostream &os, const Item &item) {
        os << setw(5) << right << item.index << setw(5) << right << item.value << setw(5) << right << item.weight;
        return os;
    }

    friend istream& operator>>(istream &is, Item &item) {
        is >> item.index >> item.value >> item.weight;
        return is;
    }

public:
    explicit Item(const int& index0 = 0, const int& value0 = 0, const int& weight0 = 0) {
        index = index0;
        value = value0;
        weight = weight0;
    }

    ~Item() = default;

private:
    int index;
    int value;
    int weight;
};

void readFile(const string& filePath, vector<Item>& items, int& N, int& C) {
    Item item;
    ifstream file(filePath);

    file >> N;
    items.reserve(N);
    for (int i = 0; i < N; i++) {
        file >> item;
        items.push_back(item);
    }
    file >> C;
}

int main() {
    const string file_path = "easy200.txt";
    int C, N; // C: capacity N: total numbers of items
    vector<Item> items;
    readFile(file_path, items, N, C);

    /* Showcasing file content */
    cout << setw(3) << right << N << endl;
    for(const auto& each : items) {
        cout << each << endl;
    }
    cout << C << endl;

    return 0;
}
