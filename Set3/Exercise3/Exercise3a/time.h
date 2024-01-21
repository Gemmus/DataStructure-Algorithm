using namespace std;

class Time {

    friend ostream& operator<<(ostream &o, Time t);
    friend istream& operator>>(istream &i, Time &t);

public:
    explicit Time(int hours0 = 0, int minutes0 = 0);
    Time(const Time &t);
    ~Time() = default;
    void read(const string &str0);
    [[nodiscard]] bool lessThan(Time &t2);
    [[nodiscard]] Time subtract(const Time &t3) const;
    void display() const;
    Time operator-(const Time &right) const;
    Time operator+(const Time &right) const;
    bool operator<(Time &t);
    bool operator==(const Time& t4) const;

private:
    int minutes;
};