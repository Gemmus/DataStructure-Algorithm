/* Exercise 1c. (Re-usability of component. Extra exercise, 0,25p bonus)

Now reuse the previous time component in a different application without modifying it. Remember that you need to use the
time component like components are usually used: you use only it's interface information (information in the header file)
in the application (in main function) and then you link ("plug in") the component as a black box (different source file).

In a long run race the number of runners is 10 at maximum. When all the runners have done their run, the running time of
the runner is stored to the system in the order of runner’s contest number (the order in the participant list). Because
of this, the times are not in order.

Write a program which first reads those times and then searches the smallest time (the winner). Finally, the program
prints out all the times in the same order which they are entered to the system and the difference to the winner is also
calculated and shown.

How many times you have? 5
Give the time 1 (hh mm)? 1 23
Give the time 2 (hh mm)? 2 10
Give the time 3 (hh mm)? 1 32
Give the time 4 (hh mm)? 1 45
Give the time 5 (hh mm)? 2 13

Result list:
 1: 01:23 00:00
 2: 02:10 00:47
 3: 01:32 00:09
 4: 01:45 00:22
 5: 02:13 00:50

Remark 1. To be reusable in many applications, the class needs a good selection of
operation functions. We have implemented only a few of them. Necessary operations for
the time component are for example comparison (see the exercise 1b) and constructing
the time with given parameters.
*/

#include <iostream>
#include <sstream>

using namespace std;

class Time {
    friend ostream& operator<<(ostream &o, Time t) {
        t.display();
        return o;
    }

    friend istream& operator>>(istream &i, Time &t) {
        t.read("");
        return i;
    }
public:
    explicit Time(int minutes0 = 0) {
        minutes = minutes0;
    }

    Time(const Time &t) {
        minutes = t.minutes;
    }

    ~Time() = default;

    void read(const string &str0) {
        string input;
        int aux_hours, aux_minutes;
        bool received_valid = false;

        cout << str0;

        while (!received_valid) {
            getline(cin, input);
            istringstream is(input);
            if (is >> aux_hours >> aux_minutes) {
                if (aux_hours >= 0 && aux_hours <= 23 && aux_minutes >= 0 && aux_minutes <= 59) {
                    received_valid = true;
                } else {
                    cout << "Invalid time. Please enter valid time (hh mm): ";
                }
            } else {
                cout << "Invalid input. Please enter correct format (hh mm): ";
            }
        }

        minutes = aux_minutes + 60 * aux_hours;
    }

    [[nodiscard]] bool lessThan(Time &t2) {
        if (minutes < t2.minutes) {
            return true;
        }
        return false;
    }

    [[nodiscard]] Time subtract(const Time &t3) const {
        Time difference;
        difference.minutes = minutes - t3.minutes;
        return difference;
    }

    void display() const {
        int hours = abs(minutes / 60);
        int temp_min = abs(minutes % 60);
        if (hours < 10) {
            cout << "0";
        }
        cout << hours << ":";

        if (temp_min < 10) {
            cout << "0";
        }
        cout << temp_min;
    }

    Time operator-(const Time &right) const {
        Time diff = this->subtract(right);
        diff.minutes *= -1;
        return diff;
    }

    Time operator+(const Time &right) const {
        Time sum = *this;
        sum.minutes += right.minutes;
        return sum;
    }

    bool operator<(Time &t) {
        return lessThan(t);
    }

private:
    int minutes;
};

int main(){

    int runner_num;
    cout << "How many times you have? ";
    cin >> runner_num;

    while (runner_num <= 0) {
        cout << "Invalid input. How many times you have? ";
        cin >> runner_num;
    }
    cin.ignore(1);

    Time runners[runner_num];

    for (int i = 0; i < runner_num; i++) {
        runners[i].read("Give the time " + to_string(i + 1) + " (hh mm)? ");
    }

    Time winner = runners[0];
    for (int i = 1; i < runner_num; i++) {
        if (runners[i] < winner) {
            winner = runners[i];
        }
    }

    cout << endl << "Result list:" << endl;

    for (int i = 0; i < runner_num; i++) {
        cout << " " << i + 1 << ": " << runners[i] << " " << runners[i] - winner << endl;
    }

    return 0;
}
