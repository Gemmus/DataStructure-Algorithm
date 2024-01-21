/*     Exercise 2. (Assignment(=), shallow copy and deep copy, 1p)

Phase 1: First test case (simple structure assignment)

Define a class Measurements (measurement.h and measurement.cpp files), which
should contain floating point value array and information how many measurements
there are on the array. Implement the following operation functions for this datatype:

        bool read(const char *filename);
        void print();
        double mean();

read reads measurement values from the given file; file format is <number_of_values>
<value> <value> ... (look the given measurement datafile mea.dat), print prints to the
console all the measurements, and mean returns the mean of the given measurements.

The implementation of the class measurement should use dynamic memory because we
don’t know beforehand (at the compile time) how many items there will be on the
measurement file. You can reserve space from the dynamic memory by using a new
operator. This function will return a pointer to the newly created memory block.

Notice: the given measurement file should give 0.527944 as the mean.

*/

#include <iostream>
#include "measurement.h"

using namespace std;

const static char *filename = "mea.dat";

int main(int argc, char *argv[]) {

    Measurements m;

    if (m.read(filename)) {
        m.print();
        cout << "Mean is " << m.mean() << endl;
    }
    else {
        cout << "Can't open the file '" << filename << "'" << endl;
    }

    return 0;
}
