#include <iostream>
#include <sstream>

using namespace std;

/////////////////////////////////// JARKKO ////////////////////////////////////
#define exercise1C // Define selected task (exercise1A, exercise1B, exercise1C)
///////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////
//              Exercise 1A               //
////////////////////////////////////////////

#ifdef exercise1A

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

#endif

////////////////////////////////////////////
//              Exercise 1B               //
////////////////////////////////////////////

#ifdef exercise1B

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

# endif

////////////////////////////////////////////
//              Exercise 1C               //
////////////////////////////////////////////

#ifdef exercise1C

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

#endif
