using namespace std;

class Measurements {

public:
    explicit Measurements(double *data0 = nullptr, int size0 = 0);
    Measurements(const Measurements& measurement0);
    ~Measurements();
    Measurements& operator=(const Measurements& right);
    bool read(const char *filename);
    void print();
    double mean();
    void inc(double increment);

private:
    double *data;
    int size;
};