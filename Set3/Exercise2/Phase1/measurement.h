using namespace std;

class Measurements {

public:
    explicit Measurements(double *data0 = nullptr, int size0 = 0);
    Measurements(const Measurements& measurement0);
    ~Measurements();
    bool read(const char *filename);
    void print();
    double mean();

private:
    double *data;
    int size;
};
