#include <iostream>
#include <sstream>
#include "time.h"


using namespace std;

ostream& operator<<(ostream &o, Time t) {
    t.display();
    return o;
}

istream& operator>>(istream &i, Time &t) {
    t.read("");
    return i;
}

Time::Time(int hours0, int minutes0) {
    minutes = minutes0;
    minutes += hours0 * 60;
}

Time::Time(const Time &t) {
    minutes = t.minutes;
}

void Time::read(const std::string &str0) {
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

bool Time::lessThan(Time &t2) {
    if (minutes < t2.minutes) {
        return true;
    }
    return false;
}

Time Time::subtract(const Time &t3) const {
    Time difference;
    difference.minutes = minutes - t3.minutes;
    return difference;
}

void Time::display() const {
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

Time Time::operator-(const Time& right) const {
    Time diff = this->subtract(right);
    diff.minutes *= -1;
    return diff;
}

Time Time::operator+(const Time &right) const {
    Time sum = *this;
    sum.minutes += right.minutes;
    return sum;
}

bool Time::operator<(Time &t) {
    return lessThan(t);
}

bool Time::operator==(const Time& t4) const {
    int temp_hours = abs(minutes / 60);
    int temp_min = abs(minutes % 60);
    int comp_hours = abs(t4.minutes / 60);
    int comp_min = abs(t4.minutes % 60);
    if ((temp_hours == comp_hours )&& (temp_min == comp_min)) {
        return true;
    }
    return false;
}