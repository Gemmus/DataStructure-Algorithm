/*    Exercise 13c. (Optional, Improve greedy algorithm with a heuristic, 0,25p)

We can modify the greedy algorithm to include heuristic to provide solutions within x percent of optimal for x < 100.
First we place a subset of at most k objects into the knapsack. If this subset has weight greater than c, we discard it.
Otherwise, the remaining capacity is filled by considering the remaining objects in decreasing order of vi/wi. The best
solution obtained considering all possible subsets with at most k objects is the solution generated by the heuristic.

The solution produced by this modified greedy algorithm is k –optimal. That is, if we remove k objects from the solution
and put back up to k, the new solution is no better than the original. Further, the value of a solution obtained in this
manner comes within 100/(k+1) percent of optimal. When k=1, the solutions are guaranteed to have value within 50% of
optimal; when k=2, they are quaranteed to have value within 33,33% of optimal; and so on. The run time of the heuristic
increases with k. The number of subsets to be tried is O(nk), and O(n) time is spent on each. Also, O(nlogn) time is
needed to order the objects by vi/wi. So the total time taken is O(nk+1) when k>0.

Implement this heuristic when k=1. In this case you put one item first at time to the knapsack, and after that run the
original greedy algorithm for the remaining items. Then finally you select the best solution of those previous selections.
Compare the performance of this heuristic to the original greedy algorithm (hard33.txt file should give 22340 value
units which is 0,65% less than the optimal solution, 22486 value units, a substantial improvement to the normal greedy
algorithm; hard200.txt file should give the value of 136724 with normal greedy algorithm, and 136972 with this heuristic algorithm).
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

void greedyHeuristic(const vector<Item>& srcVector, const int& C, vector<Item>& destVector, int& opt_value, int& opt_weight) {
    vector<Item> sortedVector = srcVector;

    // Sorting vector based on value / weight (highest value density first)
    sort(sortedVector.begin(), sortedVector.end(), [](const Item& left, const Item& right) {
        return ((double)left.valueGetter() / left.weightGetter()) > ((double)right.valueGetter() / right.weightGetter());
    });


    for (int i = 0; i < sortedVector.size(); i++) {
        vector<Item> knapsack;
        int knapsack_value = 0;
        int knapsack_weight = 0;

        // Add the current item to the knapsack
        knapsack.push_back(sortedVector[0]);
        knapsack_value += sortedVector[0].valueGetter();
        knapsack_weight += sortedVector[0].weightGetter();

        // Run the normal greedy algorithm on the remaining items
        for (int j = 1; j < sortedVector.size(); j++) {
            if (knapsack_weight + sortedVector[j].weightGetter() <= C) {
                knapsack.push_back(sortedVector[j]);
                knapsack_value += sortedVector[j].valueGetter();
                knapsack_weight += sortedVector[j].weightGetter();
            }
            // Update the optimal solution if the current knapsack is better
            if (knapsack_value > opt_value) {
                opt_value = knapsack_value;
                opt_weight = knapsack_weight;
                destVector = knapsack;
            }
        }
    }

}

int main() {

    /* Initialization of exec time measurement */
    auto start = chrono::high_resolution_clock::now();

    /* Mode selection: brute force = 1, greedy = 2, greed heuristic = 3 */
    const int mode = 3;

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
        case 1:      // Brute force search function call
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
        case 2:      // Greedy search function call
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
        case 3:      // Greedy search function call
            greedyHeuristic(items, C, knapsack, opt_value, opt_weight);
            sort(knapsack.begin(), knapsack.end(), [] (const Item&left, const Item&right) {
                return left.indexGetter() < right.indexGetter();
            });
            cout << "Feasible solution (greedy with heuristic) found: <" << opt_value << "> <" << opt_weight << "> " << endl;
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