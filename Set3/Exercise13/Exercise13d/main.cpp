/*    Exercise 13d. (Optional extra, Multithread brute force search, 1p)

Many processors on modern PC contains more than one processor core. Normally your programs are single threaded and do
not exploit all the available processing power of the multicore processor1. If you implement your program using multiple
threads (a lightweight process, having the same stack), you can utilize processor’s additional processing performance.

Creating a new thread in Java can be done easily by inheriting the Thread class, implementing run() method and creating
a class and calling start() method. Waiting for the thread to terminate can be done with join() method.
Runtime.getRuntime().availableProcessors() method can be used to find out how many effective threads can be created for your system.

In order to speed up the brute force search, you can divide the search space to separate ranges and then search those
subranges in different threads. E.g. if you have 33 items on your knapsack, the search space is from 000000000000000000000000000000000 –
111111111111111111111111111111111. If you have four processors (or cores) available on your system, you can divide the
search space to four ranges
00XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,
01XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,
10XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,
11XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX where X denotes 0 or 1. Because those subspaces are smaller (two bits smaller), time
to walk through the whole subspace is shorter.

After all subspaces are searched (in parallel), you must combine the results. In this case this means to find the largest
value from the largest value of subspaces. This is then the final answer of the whole problem.

With this parallel computation technique you can speed up the search process. If you have four threads (in four core system),
the execution time of the search is one quarter of the original time2.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>

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

void bruteForceSearch(const vector<Item>& srcVector, const int& C, vector<Item>& destVector, int& opt_value, int& opt_weight, int start, int end) {
    auto size = (int64_t)srcVector.size();
    auto total_combo = (int64_t)pow(2, size); // Total number of possible solutions

    opt_value = 0;
    opt_weight = 0;

    for (int64_t i = start; i < end; ++i) {
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
    }
}

int main() {

    /* Initialization of exec time measurement */
    auto start_T_measurement = chrono::high_resolution_clock::now();

    /* Locals */
    const string file_path = "easy20.txt";
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
    int64_t num_threads = thread::hardware_concurrency(); // Number of available threads
    vector<thread> threads(num_threads);
    vector<int> opt_values(num_threads);
    vector<int> opt_weights(num_threads);
    vector<vector<Item>> knapsacks(num_threads);

    int64_t partition_size = pow(2, N) / num_threads;
    for (int64_t i = 0; i < num_threads; ++i) {
        int64_t start = i * partition_size;
        int64_t end = (i == num_threads - 1) ? pow(2, N) : (i + 1) * partition_size;
        threads[i] = thread(bruteForceSearch, ref(items), C, ref(knapsacks[i]), ref(opt_values[i]), ref(opt_weights[i]), start, end);
    }

    for (auto& th : threads) {
        th.join();
    }

    /* Combine results */
    for (int64_t i = 0; i < num_threads; ++i) {
        if (opt_values[i] > opt_value) {
            opt_value = opt_values[i];
            opt_weight = opt_weights[i];
            knapsack = knapsacks[i];
        }
    }

    cout << "Optimal solution found: <" << opt_value << "> <" << opt_weight << ">" << endl;
    for (Item item : knapsack) {
        cout << "<" << item.indexGetter() << "> ";
    }
    cout << endl;

    /* Termination of exec time measurement and print */
    auto end_T_measurement = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::minutes>(end_T_measurement - start_T_measurement);
    cout << "Execution time: " << duration.count() << " min" << endl;

    return 0;
}
