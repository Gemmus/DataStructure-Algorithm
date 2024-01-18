/*  Exercise 1b (Function/operator overloading. Extra exercise, 0,25p)

Modify your Time class from the mandatory exercise in such a way the following program works
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
    Time start, end, duration;

    cout << "Enter starting time "; cin >> start;
    cout << "Enter ending time "; cin >> end;
    duration = start < end ? end - start : start - end;
    cout << "Duration " << duration << endl;
    cout << "Starting time was " << end - duration << endl;
    cout << "Ending time was " << start + duration << endl;
    return 0;
}
