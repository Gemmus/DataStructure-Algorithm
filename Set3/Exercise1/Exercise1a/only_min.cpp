/*  Exercise 1a (Using a class, 0.5p)

We need to write an application, which reads two times (times are represented by two int numbers: hours and minutes)
from the keyboard. Then the program finds out which time is later. After that it calculates the time difference between
these times. Finally, the program displays the smaller (earlier) time and the time difference (duration) in the format
        starting time was 11:22
        duration was 1:04

The main function that does these things looks as follows:
int main() {
    Time time1, time2, duration;
    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1.lessThan(time2)) {
        duration = time2.subtract(time1);
        cout << "Starting time was ";
        time1.display();
    } else {
        duration = time1.subtract(time2);
        cout << "Starting time was ";
        time2.display();
    }
    cout << "Duration was ";
    duration.display();
    return 0;
}

Now you need to define and implement class Time so that the program starts working. As can be seen from the main
function, class Time has the following member functions:
1. read that is used to read time (minutes and hours) from the keyboard.
2. lessThan that is used to compare two times.
3. subtract that is used to calculate time difference between two times.
4. display that is used to display time in the format hh:mm.
*/

#include <iostream>
#include <sstream>

using namespace std;

class Time {
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

    [[nodiscard]] bool lessThan(const Time &t2) const {
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
        cout << temp_min << endl;
    }

private:
    int minutes;
};

int main() {
    Time time1, time2, duration;
    time1.read("Enter time 1: ");
    time2.read("Enter time 2: ");
    if (time1.lessThan(time2)) {
        duration = time2.subtract(time1);
        cout << "Starting time was ";
        time1.display();
    } else {
        duration = time1.subtract(time2);
        cout << "Starting time was ";
        time2.display();
    }
    cout << "Duration was ";
    duration.display();
    return 0;
}
