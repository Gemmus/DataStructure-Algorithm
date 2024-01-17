/* We need to write an application, which reads two times (times are represented by two int numbers: hours and minutes)
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
4. display that is used to display time in the format hh:mm.1
*/

#include <iostream>

using namespace std;

class Time {
public:
    Time(int hours0 = 0, int minutes0 = 0) {
        hours = hours0;
        minutes = minutes0;
    }

    ~Time() {}

    void read(const string &str0) {
        int aux_hours, aux_minutes;

        cout << str0 << endl;

        cout << "Please enter the hours: ";
        cin >> aux_hours;
        while (aux_hours < 0 || aux_hours > 24) {
            cout << "Invalid input, please enter the correct hours: ";
            cin >> aux_hours;
        }
        hours = aux_hours;

        cout << "Please enter the minutes: ";
        cin >> aux_minutes;
        while (aux_minutes < 0 || aux_minutes > 60) {
            cout << "Invalid input, please enter the correct minutes: ";
            cin >> aux_minutes;
        }
        minutes = aux_minutes;
    }

    bool lessThan(const Time &t2) {
        if (hours < t2.hours) {
            return true;
        } else if (hours == t2.hours) {
            if (minutes < t2.minutes) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    Time subtract(const Time &t3) {
        Time aux;
        if (minutes < t3.minutes) {
            aux.minutes = t3.minutes - minutes;
            aux.hours = hours - t3.hours- 1;
        } else {
            aux.minutes = minutes - t3.minutes;
            aux.hours = hours - t3.hours;
        }
        return aux;
    }

    void display() {
        cout << hours << ":" << minutes << endl;
    }

private:
    int hours;
    int minutes;
};

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
