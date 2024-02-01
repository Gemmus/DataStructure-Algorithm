/*   Exercise 8a. (STL Algorithms, 0.5p)

Create a program, which has a list of times1 (using your old class Time). First enter times to that list from the keyboard
in a random order. Then order those time entries in a standard way (later time is “bigger”, e.g. 11:03 is bigger than 10:54),
and print that ordered list of times.

After that (in the same program) calculate the difference between successive times and print out the same array of times
and their time differences like

Enter times (terminate with 0 0):? 12 43 8 22 17 45 2 20 0 0
Unsorted times:
12:43
08:22
17:45
02:20

Sorted times:
02:20
08:22
12:43
17:45

Time differences:
02:20
08:22 06:02
12:43 04:21
17:45 05:02

Note: use the standard sort() and adjacent_difference() algorithms for the sorting operation (you may also need back_inserter()).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "time.h"

using namespace std;

int main() {
    vector<Time> times;
    Time time;

    cout << "Enter times (terminate with 0 0):\n";
    cin >> time;

    while (!(time == Time(0, 0))) {
        times.push_back(time);
        cin >> time;
    }

    cout << "\nUnsorted times:" << endl;
    for (const auto& item : times) {
        cout << item << endl;
    }

    cout << "\nSorted times:" << endl;
    sort(times.begin(), times.end());
    for (const auto& item : times) {
        cout << item << endl;
    }

    cout << "\nTime differences:" << endl;
    vector<Time> differences;
    adjacent_difference(times.begin(), times.end(), back_inserter(differences));
    cout << times[0] << endl;
    for (int i = 1; i < times.size(); i++) {
        cout << times[i] << " " << differences[i] << endl;
    }

    return 0;
}
