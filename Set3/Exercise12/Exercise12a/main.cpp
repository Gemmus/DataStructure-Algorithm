/* Exercise 13a (Extra exercise, performance measuring, 0.5p)

Discrete Fourier transform (DFT) from time domain to frequency domain is a useful tool for various digital signal
processing (DSP) tasks1. It is defined as Figure 1, where xj is the jth input signal sample (like x[j]), fk is the kth
frequency component, and N is the number of samples used in the transformation process. DFT takes N real or complex
input samples xj and produces N complex output samples fk. The number of multiplications needed in this transform is the
number of input samples squared, i.e. complexity of this transform is O(N2). This makes the DFT unpractical for large
values of N. If the number of points is N=2n (this is called the radix-2 –algorithm), the equation can be modified, as
Figure 2 shows, where we first take N/2 samples discrete Fourier transform from the even index numbered samples
(e.g. x[0], x[2], x[4], …) and then another discrete Fourier transform from the odd numbered samples
(e.g. x[1], x[3], x[5], …), and finally combining the results by multiplying the latter transform by e^(2PI*i*k/N) and
adding results together. This is an example of divide-and-conquer algorithm design technique. With this technique the
complexity of the discrete Fourier transform can be shown to be O(Nlog2N) that is much smaller (than the original
transform) when N is large. Therefore, implementation based on this concept is called a Fast Fourier Transform (FFT).

You don’t need to bother yourself implementing this FFT; a straightforward recursive implementation of the latter
equation is given here in a file fft.cpp.

Your task is to write a program that measures the execution time (in ms) of the given Fast Fourier transform implementation
(function void fft(int n, cm x[])) using the high performance timer available in C++. In order to make your execution time
measurements reliable, you need to run the function more than once (30 times, for example). Store those individual
measurements to a suitable C++ container, discard 10 largest values2 and calculate their mean and standard deviation3.
Don’t use loops in your statistical values calculation, use containers and algorithms instead.

Mean 𝜇 and standard deviation 𝜎 can be calculated using the equations in Figure 3 (we are using unbiased sample variance here).

Hint: high_resolution_clock, accumulate, for_each, lambda function
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

using namespace std;

typedef complex<double> cx;
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

#if 0

    const int N = 8;
    cx input[N];

    // create the test input signal sequence
    for (int i = 0; i < N; i++)
        input[i] = cx(i, -i);  // linear ramp for real part, negative ramp for imaginary part

    fft(N, input);

    // display the results
    for (cx &c: input)
        cout << c << endl;

    system("PAUSE");
    /*   valid output:
        (28,-28)
        (5.65685,13.6569)
        (4.13891e-013,8)
        (-2.34315,5.65685)
        (-4,4)
        (-5.65685,2.34315)
        (-8,4.13447e-013)
        (-13.6569,-5.65685)
        Press any key to continue . . .
    */

#else

    // create the test input signal sequence
    const int N = 8;
    cx input[N];
    for (int i = 0; i < N; i++)
        input[i] = cx(i, -i);  // linear ramp for real part, negative ramp for imaginary part

    // Measure execution time of fft() 30 times, storing each measured time into vector
    const int run_func_N_times = 30;
    vector<double> execution_times;

    for (int i = 0; i < run_func_N_times; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        fft(N, input);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        execution_times.emplace_back(duration.count());
    }

    // Sorts and disregards the largest 10 values:
    sort(execution_times.begin(), execution_times.end());
    execution_times.erase(execution_times.end() - 10, execution_times.end());

    cout << "Execution times after sorting and disregarding largest 10 values: ";
    for (int i = 0; i < execution_times.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execution_times[i] << "\t";
    }

    // Calculate mean and deviation:
    double mean, std_deviation;

    mean = accumulate(execution_times.begin(), execution_times.end(), 0.0) / (double)execution_times.size();
    std_deviation = sqrt(accumulate(execution_times.begin(), execution_times.end(), 0.0,[&](const double &accumulator, const double &val) {
                                        return accumulator + pow(val - mean, 2);}) / (double)(execution_times.size() - 1));

    // Display:
    cout << "\n\nMean: " << mean << " nanoseconds" << endl;
    cout << "Standard deviation: " << std_deviation << " nanoseconds" << endl;

#endif

    return EXIT_SUCCESS;
}

