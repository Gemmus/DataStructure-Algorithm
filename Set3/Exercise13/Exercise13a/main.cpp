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
#include <cmath>
#include <chrono>

using namespace std;

class Item {
    friend ostream& operator<<(ostream &os, const Item &item) {
        os << setw(5) << right << item.index << setw(6) << right << item.value << setw(6) << right << item.weight;
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

    [[nodiscard]] int indexGetter() const {
        return index;
    }

    [[nodiscard]] int valueGetter() const {
        return value;
    }

    [[nodiscard]] int weightGetter() const {
        return weight;
    }


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
    file.close();
}

void fullEnumerator(const vector<Item>& srcVector, const int& C, vector<Item>& destVector, int& opt_value, int& opt_weight) {
    auto size = (int64_t)srcVector.size();
    auto total_combo = (int64_t)pow(2, size); // Total number of possible solutions

    opt_value = 0;
    opt_weight = 0;

    for (int64_t i = 0; i < total_combo; ++i) {
        vector<Item> current_combo;
        int current_value = 0;
        int current_weight = 0;

        for (int64_t j = 0; j < size; ++j) {
            if (i & (1 << j)) {            // Checking if jth bit is set in the binary representation of i
                current_combo.push_back(srcVector[j]);
                current_value += srcVector[j].valueGetter();
                current_weight += srcVector[j].weightGetter();
            }
        }

        // Checking if the current solution is feasible and better than the current optimal solution
        if (current_weight <= C && current_value > opt_value) {
            opt_value = current_value;
            opt_weight = current_weight;
            destVector = current_combo;
        }

        // Output progress every 1,000,000 solutions evaluated
        if (i % 10000000 == 0) {
            double progress = ((double)i / (double)total_combo) * 100;
            cout << (int)progress << "% -> ";
        } else if (i == (total_combo - 1)) {
            cout << "100%" << endl;
        }
    }
}

int main() {

    /* Initialization of exec time measurement */
    auto start = chrono::high_resolution_clock::now();

    /* Locals */
    const string file_path = "hard33.txt";
    int C, N; // C: capacity N: total numbers of items
    int opt_value, opt_weight;
    vector<Item> items;
    vector<Item> knapsack;

    /* Read from files and put data into array */
    readFile(file_path, items, N, C);

    /* Showcasing file content */
    /*
    cout << setw(3) << right << N << endl;
    for(Item item : items) {
        cout << item << endl;
    }
    cout << C << endl;
     */

    /* Brute force search function call and print */

    fullEnumerator(items, C, knapsack, opt_value, opt_weight);
    cout << "Optimal solution found: <" << opt_value << "> <" << opt_weight << ">" << endl;
    for (Item item : knapsack) {
        cout << "<" << item.indexGetter() << "> ";
    }
    cout << endl;

    /* Termination of exec time measurement and print */
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::minutes>(end - start);
    cout << "Execution time: " << duration.count() << " min" << endl;

    return 0;
}
