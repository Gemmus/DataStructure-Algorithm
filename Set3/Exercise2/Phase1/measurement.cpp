#include <iostream>
#include <fstream>
#include <sstream>
#include "measurement.h"

using namespace std;

Measurements::Measurements(double *data0, int size0) {
    size = size0;
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = data0[i];
    }
}

Measurements::Measurements(const Measurements& measurement0) {
    size = measurement0.size;
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = measurement0.data[i];
    }
}

Measurements::~Measurements(){
    delete data;
}

bool Measurements::read(const char *filename) {
    string file_line;
    double aux;

    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    getline(file, file_line);
    istringstream is1(file_line);
    is1 >> size;
    data = new double[size];

    getline(file, file_line);
    istringstream is2(file_line);

    for (int i = 0; i < size; i++) {
        if (is2 >> aux) {
            data[i] = aux;
        } else {
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}

void Measurements::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << endl;
    }
    cout << endl;
}

double Measurements::mean() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}
