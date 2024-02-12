/*    Exercise 13b. (Optional, Implement Greedy 0/1 knapsack resolving algorithm, 0,25p)

Greedy search can be applied to the 0/1 Knapsack problem, but it does not guarantee to give an optimal solution.

Remember that a greedy search has the form:
    "While solution not constructed select best remaining element and try adding it in."

What is the sense of “best” here? I.e. what is the criterion by which the items should be ordered?

Write a program that implements the greedy method for the 0/1 problem. In your implementation, first sort the items by
your criterion so that you don't have to search through all of them each step. One quite useful criterion could be value
density vi/wi (so we will be greedy on value density).

Output upon termination, the program should output the following:
Feasible solution (not necessarily optimal) found: <value> <weight>
<item> <item> <item> ...

Run your greedy algorithm code on the two problem instances, easy.20.txt and hard33.txt.
Compare the results of brute force search for hard33.txt (optimal solution for hard33.txt should be 22486 value units,
and greedy solution should have 19388 value units; about 14% less than the optimal).
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <chrono>
#include <algorithm>

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

    /* Showcasing file content */
    /*
    cout << setw(3) << right << N << endl;
    for(Item item : items) {
        cout << item << endl;
    }
    cout << C << endl;
     */
}

void fullEnumerator(const vector<Item>& srcVector, const int& C, vector<Item>& destVector, int& opt_value, int& opt_weight) {
    auto size = (int64_t)srcVector.size();
    auto total_combo = (int64_t)pow(2, size); // Total number of possible solutions

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

void greedy(const vector<Item>& srcVector, const int& C, vector<Item>& destVector, int& opt_value, int& opt_weight) {
    vector<Item> sortedVector = srcVector;
    int current_weight = 0;
    int future_weight;

    // Sorting vector based on value / weight (highest value density first)
    sort(sortedVector.begin(), sortedVector.end(), [](const Item& left, const Item& right) {
        return ((double)left.valueGetter() / left.weightGetter()) > ((double)right.valueGetter() / right.weightGetter());
    });

    for (const Item& each : sortedVector) {  // TODO: For testing, needs removal
        cout << each << endl;
    }

    // Adding elements based on density until available capacity no longer fits next item
    for (const auto& each : sortedVector) {
        future_weight = current_weight + each.weightGetter();
        cout << each.indexGetter() << ": " << current_weight << " + "  << each.weightGetter()<< " = " << future_weight << " ";
        if (future_weight <= C) {
            cout << "true" << endl;
            current_weight += each.weightGetter();
            opt_weight = current_weight;
            opt_value += each.valueGetter();
            destVector.push_back(each);
        } else {
            cout << endl;
        }
    }
}

int main() {

    /* Initialization of exec time measurement */
    auto start = chrono::high_resolution_clock::now();

    /* Mode selection: brute force = 1, greedy = 2, greed */
    const int mode = 2;

    /* Locals */
    const string file_path = "hard33.txt";
    int C, N; // C: capacity N: total numbers of items
    int opt_value = 0;
    int opt_weight = 0;
    vector<Item> items;
    vector<Item> knapsack;

    /* Read from files and put data into array */
    readFile(file_path, items, N, C);

    /* Calling correct function based on selected mode */
    switch(mode) {
        case 1:
            /* Brute force search function call */
            fullEnumerator(items, C, knapsack, opt_value, opt_weight);
            sort(knapsack.begin(), knapsack.end(), [] (const Item&left, const Item&right) {
                return left.indexGetter() < right.indexGetter();
            });
            cout << "Optimal solution found: <" << opt_value << "> <" << opt_weight << "> " << endl;
            for (Item item : knapsack) {
                cout << "<" << item.indexGetter() << "> ";
            }
            cout << endl;
            break;
        case 2:
            /* Greedy search function call */
            greedy(items, C, knapsack, opt_value, opt_weight);
            sort(knapsack.begin(), knapsack.end(), [] (const Item&left, const Item&right) {
                return left.indexGetter() < right.indexGetter();
            });
            cout << "Feasible solution (not necessarily optimal) found: <" << opt_value << "> <" << opt_weight << "> " << endl;
            for (Item item : knapsack) {
                cout << "<" <<item.indexGetter() << "> ";
            }
            cout << endl;
            break;
        default:
            cout << "Invalid mode." << endl;
            break;
    }

    /* Termination of exec time measurement and print */
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::minutes>(end - start);
    cout << "Execution time: " << duration.count() << " min" << endl;

    return 0;
}
