/* Extra exercise 12b (Extra exercise, parallelization, 0.5p)

 'Warning! This is not an easy task.
In the divide-and-conquer technique the algorithm is structured as follows
    1. split the original data to two pieces A and B
    2. do the operation for the smaller data A
    3. do the operation for the smaller data B
    4. combine the results
Because A and B data sets are independent, phases 2 and 3 can be done easily in parallel.

Make the given fast Fourier transform function concurrent using C++ high-level parallel
interface and compare the performance of this implementation to the original non-parallel
implementation. Do the comparison with multiple values of N, e.g. from 2048 to 262144,
you may also export your measurement data to the file (csv format) where it can be read to
a spread-sheet application (like MS-Excel).

Construct your program using object oriented design rules. You should have two classes;
Measure class who has a function void measure(double &mean, double
&stdev); which is responsible to run the function to be tested, measure the execution
time and doing this a couple of times in order to calculate statistical information.

                Measure <-------- FFTTestbed

The other class, FFTTestbed inherits measurement functions from the Measure class and
gives the function to be measured to the Measure class. You should be able to use your
measurement system like this:
    const int n = 2048;
    double mean, stdev;
    void fft(int n, cm x);
    FFTTestBed *p = new FFTTestBed(fft, n);
    p->measure(mean, stdev);
    delete p;

Now your measurement system (class Measure) is versatile; you can use it to evaluate
different type of functions. FFTTestbed is the cover class to maintain the necessary
environment (e.g. setup input data for the function, testing the results, etc.) needed for
running the function. If you want to test other functions, you create another class that
inherits the class Measure, so you are reusing the class Measure.

In order to reduce the measurement errors (because we are using multitasking operating
system which can make task switches during the performance measurement) take 30
measurement and discard 10 worst time measurements. Result of the comparison depends
on the hardware used, but one simulation run (Intel i5-661, 3.33 GHz, Windows 7) can be
like this:

      N         Unopt          Unopt_br         Single       Single_br       Parallel        Paral_br
    2048:     0(± 0) ms       0(± 0) ms       0(± 0) ms      0(± 0) ms      0(± 0) ms       0(± 0) ms
    4096:     0(± 0) ms       0(± 0) ms       0(± 0) ms      0(± 0) ms      0(± 0) ms       0(± 0) ms
    8192:     3(± 9) ms      4(± 10) ms       3(± 9) ms      1(± 4) ms      0(± 0) ms       0(± 0) ms
   16384:    10(± 0) ms      10(± 0) ms      10(± 0) ms      8(± 8) ms     5(± 10) ms       3(± 9) ms
   32768:    22(± 8) ms      22(± 0) ms      21(± 4) ms     17(± 9) ms     11(± 6) ms       9(± 6) ms
   65536:    50(± 0) ms      50(± 0) ms      50(± 0) ms     38(± 9) ms     29(± 6) ms      19(± 7) ms
  131072:   110(± 0) ms     110(± 0) ms    106(± 10) ms     80(± 0) ms     63(± 9) ms      38(± 5) ms
  262144:   231(± 4) ms    236(± 10) ms     230(± 0) ms    171(± 4) ms   139(± 12) ms      82(± 1) ms
Measurements took 67s

The number in parenthesis is the 95% confidence interval (standard deviation multiplied
by two) and _br ending means special variation to the FFT-function where no dynamic
memory allocation is needed.

From the table you can immediately find out that the execution time is really N×logNdependent on the size of the input vector to be transformed (N) because
(262144×log262144)/(131072×log131072)=2,12 and 231/110=2,10.

Optimizing the recursive FFT function using Visual Studio 2012 optimizer does not
decrease the execution time of unoptimized recursive FFT (231ms) compared to optimized
version (230ms). Compiler’s optimization process is dependent on the code; unoptimized
recursive FFT without dynamic memory allocation has a running time of 236 ms and
optimized version has a running time of 171 ms, an improvement of 28%.

Parallelization of the optimized single threaded recursive FFT (230ms) decreases the
execution time to 139ms, 40% reduction in execution speed. Theoretical 50% reduction (i5-
661 processor has two cores) cannot be obtained in practice because there are overhead in
the parallelization process (thread creation/deletion times, etc.).
*/

/* fft.c -- straightforward recursive FFT implementation
 *
 * Look for the link http://www.engineeringproductivitytools.com/stuff/T0001/PT03.HTM
 * for details about the implementation
 *
 * Written by Jarkko Vuori 2013
 */

#include <complex>
#include <numeric>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

typedef complex<double> cx;

class Measure {
public:
    virtual void measure(double &mean, double &st_dev) = 0;

protected:
    void runFunctionAndMeasure(int n, function<void(int n, cx[])> func, double &mean, double& std_dev) {
        const int num_measurements = 30;
        vector<double> execution_times;

        // Measures execution time for 30 times, storing each measured time into vector:
        for (int i = 0; i < num_measurements; i++) {
            auto start = std::chrono::high_resolution_clock::now();
            func(n, input);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            execution_times.emplace_back((double)duration.count());
        }

        // Sorts and disregards the largest 10 values:
        sort(execution_times.begin(), execution_times.end());
        execution_times.erase(execution_times.end() - 10, execution_times.end());

        // Calculates mean and deviation:
        mean = accumulate(execution_times.begin(), execution_times.end(), 0.0) / (double)execution_times.size();
        std_dev = sqrt(accumulate(execution_times.begin(), execution_times.end(), 0.0,[&](const double &accumulator, const double &val) {
            return accumulator + pow(val - mean, 2);}) / (double)(execution_times.size() - 1));
    }

    cx *input;
};

class FFTTestbed : public Measure{
public:
    FFTTestbed(void (*func)(int, cx[]), int n) {
        this->func = func;
        input = new cx[n];
        for (int i = 0; i < n; i++) {
            input[i] = cx(i, -i);
        }
    }

    ~FFTTestbed() {
        delete[] input;
    }

    void measure(double &mean, double &st_dev) override {
        runFunctionAndMeasure(N, func, mean, st_dev);
    }

private:
    void (*func)(int, cx[]);
    const int N = 8;
};

// radix-2 in-place FFT, n must be 2^k (e.g. 2,4,6,...)
void fft(int n, cx x[]) {
    const cx J(0, 1);
    const double PI = 3.14159265359;
    // check the trivial case
    if (n == 1)
        return;

    // perform two sub-transforms
    int n2 = n/2; // size of sub-transform
    cx *xe = new cx[n2];
    cx *xo = new cx[n2];
    for (int i = 0; i < n2; i++) { // perform n/2 DIF 'butterflies'
        xe[i] = x[i] + x[i+n2];	                     // even subset
        xo[i] = (x[i] - x[i+n2])*exp(-J*(2*PI*i/n)); // odd subset
    }
    fft(n2, xe);
    fft(n2, xo);

    // construct the result vector
    for (int k = 0; k < n2; k++) {
        x[2*k]   = xe[k]; // even k
        x[2*k+1] = xo[k]; // odd k
    }

    delete[] xe;
    delete[] xo;
}

int main() {

    //ofstream output_file("fft_measurements.csv");
    //output_file << "N, Mean, Standard Deviation" << endl;
    cout << setw(7) << right << " N " << setw(12) << right << "Single" << endl;

    const int min_N = 2048;
    const int max_N = 226144;
    double mean, st_dev;

    for (int N = min_N; N <= max_N; N += N) {
        auto* fftTestbed = new FFTTestbed(fft, N);
        fftTestbed->measure(mean, st_dev);
        //output_file << N << ", " << mean << st_dev << endl;
        cout << setw(7) << right <<  N << ": " << setw(4) << right << (int)mean << "(+/- " << (int)st_dev*2 << ")ms" << endl;
        delete fftTestbed;
    }

    //output_file.close();


    return EXIT_SUCCESS;
}
