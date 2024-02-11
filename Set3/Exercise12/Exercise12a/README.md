 Exercise 12a (Extra exercise, performance measuring, 0.5p)

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

![alt text](https://github.com/Gemmus/DataStructure-Algorithm/blob/main/Set3/Exercise12/Exercise12a/FT_formulas.png)
