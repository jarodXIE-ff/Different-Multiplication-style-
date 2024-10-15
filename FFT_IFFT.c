// XIE JAROD 28710097

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "complex.h"
#include "FFT_IFFT.h"

int main()
{
    int N = 10; // You can change this to any size
    int M = 1;
    while (M < N)
        M *= 2;
    // Fill the array with some data
    Complex *x = (Complex *)malloc(M * sizeof(Complex));
    printf("Vector to use in FFT:\n");
    for (int i = 0; i < M; i++)
    {
        if (i < N)
        {
            Complex c = {(double)i, 0};
            x[i] = c;
            print(x[i]);
        }
        else
        {
            Complex c = {0, 0};
            x[i] = c;
        }
    }

    // Compute the FFT
    FFT(x, M, 0);

    // Print the results
    printf("FFT...\n");
    printf("Real Output\tImaginary Output\n");
    for (int i = 0; i < M; i++)
    {

        printf("%f\t%f\n", x[i].real, x[i].imag);
    }
    printf("\n\n");

    IFFT(x, M);
    printf("IFFT...\n");
    printf("Real Output\tImaginary Output\n");
    for (int i = 0; i < M; i++)
    {

        printf("%f\t%f\n", x[i].real, x[i].imag);
    }
    // Free the memory
    free(x);
    return 0;
}