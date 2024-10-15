// XIE JAROD 28710097

#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include <math.h>
#include "naive_poly.h"
#include "FFT_IFFT.h"
#include <time.h>

double getElapsedTime(clock_t start, clock_t end)
{
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

long long getElapsedTimeInMicroseconds(struct timespec start, struct timespec end)
{
    return (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_nsec - start.tv_nsec) / 1000LL;
}

void FFT_mult(const int *poly1, int size1, const int *poly2, int size2, int *result, int *resultSize)
{
    // Find the size of the FFT result (next power of 2)
    int fftSize = 1;
    while (fftSize < (size1 + size2 - 1))
    {
        fftSize *= 2;
    }

    // Allocate memory for FFT arrays
    Complex *fftPoly1 = malloc(fftSize * sizeof(Complex));
    Complex *fftPoly2 = malloc(fftSize * sizeof(Complex));

    // Initialize FFT arrays
    for (int i = 0; i < fftSize; i++)
    {
        fftPoly1[i] = (i < size1) ? (Complex){poly1[i], 0.0} : (Complex){0.0, 0.0};
        fftPoly2[i] = (i < size2) ? (Complex){poly2[i], 0.0} : (Complex){0.0, 0.0};
    }

    // Apply FFT to both polynomials
    FFT(fftPoly1, fftSize, 0);
    FFT(fftPoly2, fftSize, 0);

    // Pointwise multiplication in frequency domain
    for (int i = 0; i < fftSize; i++)
    {
        fftPoly1[i] = multiply_c(fftPoly1[i], fftPoly2[i]);
    }

    // Apply inverse FFT to obtain the result
    IFFT(fftPoly1, fftSize);

    // Find the size of the result polynomial
    *resultSize = size1 + size2 - 1;

    // Extract the real part of the result and round to the nearest integer
    for (int i = 0; i < *resultSize; i++)
    {
        result[i] = (int)round(fftPoly1[i].real);
    }

    // Free dynamically allocated memory
    free(fftPoly1);
    free(fftPoly2);
}

// Function to display a polynomial
void displayPolynomial2(const int *poly, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (poly[i] == 0)
        {
            continue;
        }

        printf("%dx^%d", poly[i], i);
        if (i < size - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *file = fopen("Time_FFT_MULT.txt", "a");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    int poly11[] = {4, 3, 2};
    int poly22[] = {5, 1};

    int size11 = sizeof(poly11) / sizeof(poly11[0]);
    int size22 = sizeof(poly22) / sizeof(poly22[0]);

    // Multiply polynomials using FFT
    int resultSize2;
    int *result2 = malloc((size11 + size22 - 1) * sizeof(int));
    printf("FFT_mult of the 2 polynomial\n");
    FFT_mult(poly11, size11, poly22, size22, result2, &resultSize2);

    // Display the original polynomials and the result
    printf("Polynomial 1: ");
    displayPolynomial2(poly11, size11);

    printf("Polynomial 2: ");
    displayPolynomial2(poly22, size22);

    printf("Result: ");
    displayPolynomial2(result2, resultSize2);
    int n = atoi(argv[1]); // CHANGE THIS FOR DIFFERENT SIZE FOR SPEED TEST

    int poly1[n];
    int poly2[n];

    for (long i = 0; i < n; i++)
    {
        poly1[i] = rand() % 10;
        poly2[i] = rand() % 10;
    }

    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    int resultSize;
    int *result = malloc((size1 + size2 - 1) * sizeof(int));

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    FFT_mult(poly1, size1, poly2, size2, result, &resultSize);
    clock_gettime(CLOCK_MONOTONIC, &end);

    long long elapsedTime = getElapsedTimeInMicroseconds(start, end);
    fprintf(file, "%d %lld\n", n, elapsedTime);
    printf("Time taken by FFT_mult: %lld microseconds\n", elapsedTime);
    // Free dynamically allocated memory
    free(result);
    free(result2);

    return 0;
}