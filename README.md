README

----------

# XIE JAROD 28710097

## MODEL PROJECT FOR SORBONNE UNIVERSITY 2023/2024

# Polynomial Multiplication with FFT

## Overview

This project implements polynomial multiplication using the Fast Fourier Transform (FFT) algorithm in C. The algorithm leverages the FFT to efficiently compute the product of two polynomials.

## Table of Contents

-   [Usage](#usage)
-   [Dependencies](#dependencies)
-   [Building](#building)
-   [Example](#example)

## Usage

To use this project, follow the steps below:

1.  Open the folder in any system that can run C.
2.  Type `make` in the terminal to build the project.
3.  Run the executable: `./FFT_poly` for a quick example.
4.  Run the executable: `./FFT_poly n` (with `n` being the size of the two polynomials to multiply).
    -   The program will generate two random polynomials of degree `n-1` and compute their product, recording the time in `Time_FFT_MULT.txt`.
5.  Run the executable: `./naive_poly n` to multiply two random polynomials of degree `n-1` with the naive algorithm, recording the time in `Time_NAIVE_MULT.txt`.
6.  Type: `python graph.py` to create a graph from your tests of `FFT_poly` and `naive_poly`. You can see the graph in the folder "Graph of time", it only keep the last one you create
7.  For simple use you can run this on your terminal to multiply 2 polynomial of size 1 to 10000
    
    -   `for i in {1..10000};do ./FFT_poly $i; done`
    
    -   `for i in {1..10000};do ./naive_poly $i; done`
8.  WARNING : Pc might crash for size after 10 000 for the naive\_poly.c and after 1 000 000 for the FFT\_poly

## Dependencies

This project has the following dependencies:

-   C Standard Library
-   `Complex.h` from the folder

## Building

To build the project, use the provided Makefile. Simply run:

```bash
make

```

This will compile the source code and generate the executable.

## Example

An example of how to use the polynomial multiplication function is provided in the `FFT_poly.c` file. You can run the example after building the project.

```bash
./FFT_poly 10

```

----------
