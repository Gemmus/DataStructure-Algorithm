/*     Exercise 2. (Assignment(=), shallow copy and deep copy, 1p)

Phase 2: Second test case (Structure assignment)

First implement one new operation function: void inc(double increment);
which adds the value increment to every measurement value in m.

After you have implemented the new operating function, use the following test
application.

int main(int argc, char *argv[]) {
    Measurements m1, m2;

    if (m1.read(filename)) {
        m1.print();
        m2 = m1;
        m2.inc(0.1);
        cout << "Mean m1 is " << m1.meanMeasurements() << endl;
        cout << "Mean m2 is " << m2.meanMeasurements() << endl;
    }
    else
        cout << "Can't open the file '" << filename << "'" << endl;
    return 0;
}

This application writes to the console
.
.
.
0.934011
0.129906
0.568824
0.469391
0.011902
0.337123
Mean m1 is 0.627994
Mean m2 is 0.627994

This is incorrect (the first mean should be 0.527994). What is the reason for this, and how
to fix it? (Note: using the STL vector data structure is not allowed)
Hint: you need one additional operation function to the Measurements class
*/

#include <iostream>
#include "measurement.h"

using namespace std;

const static char *filename = "mea.dat";

int main(int argc, char *argv[]) {
    Measurements m1, m2;

    if (m1.read(filename)) {
        m1.print();
        m2 = m1;
        m2.inc(0.1);
        cout << "Mean m1 is " << m1.mean() << endl;
        cout << "Mean m2 is " << m2.mean() << endl;
    }
    else
        cout << "Can't open the file '" << filename << "'" << endl;
    return 0;
}
