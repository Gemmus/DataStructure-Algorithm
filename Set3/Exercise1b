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
        int aux_hours, aux_minutes;

        cout << str0 << endl;

        cout << "Please enter the hours: ";
        cin >> aux_hours;
        while (aux_hours < 0 || aux_hours > 23) {
            cout << "Invalid input, please enter the correct hours: ";
            cin >> aux_hours;
        }

        cout << "Please enter the minutes: ";
        cin >> aux_minutes;
        while (aux_minutes < 0 || aux_minutes > 59) {
            cout << "Invalid input, please enter the correct minutes: ";
            cin >> aux_minutes;
        }

        minutes = aux_minutes + 60 * aux_hours;
    }

    bool lessThan(const Time &t2) const {
        if (minutes < t2.minutes) {
            return true;
        }
        return false;
    }

    Time subtract(const Time &t3) const {
        Time difference;
        difference.minutes = minutes - t3.minutes;
        return difference;
    }

    void display() const {
#if 0
        int hours = 0;
        int temp_min = minutes;

        while (temp_min > 59) {
            temp_min -= 60;
            hours++;
        }
#else
        int hours = minutes / 60;
        int temp_min = minutes % 60;
#endif
        if (hours < 10) {
            cout << "0";
        }
        cout << hours << ":";

        if (temp_min < 10) {
            cout << "0";
        }
        cout << temp_min;
        //cout << setiosflags(ios::right); out << setfill('0') << setw(2) << hours;
        //cout << ":" << setfill('0') << setw(2) << minutes
    }

    Time operator-(const Time &right) const {
        return this->subtract(right);
    }

    Time operator+(const Time &right) const {
        Time sum = *this;
        sum.minutes += right.minutes;
        return sum;
    }

    bool operator<(const Time &t) const {
        return lessThan(t);
    }

private:
    int minutes;
};

int main(){
    Time start, end, duration;

    cout << "Enter starting time "; cin >> start;
    cout << "Enter ending time "; cin >> end;
    duration = start < end ? end - start : start - end;
    cout << "Duration " << duration << endl;
    cout << "Starting time was " << end - duration << endl;
    cout << "Ending time was " << start + duration << endl;
    return 0;
}
