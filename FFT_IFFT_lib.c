#include "FFT_IFFT.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void FFT(Complex *a, int n, int invert)
{
    if (n <= 1)
    {
        return;
    }

    Complex *even = malloc(n / 2 * sizeof(Complex));
    Complex *odd = malloc(n / 2 * sizeof(Complex));

    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }

    FFT(even, n / 2, invert);
    FFT(odd, n / 2, invert);

    double ang = (2.0 * M_PI / n) * (invert ? -1 : 1);
    Complex w = {cos(ang), sin(ang)};

    Complex wn = {1.0, 0.0};
    for (int i = 0; i < n / 2; i++)
    {
        Complex t = multiply_c(wn, odd[i]);
        a[i] = add_c(even[i], t);
        a[i + n / 2] = subtract_c(even[i], t);
        wn = multiply_c(wn, w);
    }

    free(even);
    free(odd);
}

void IFFT(Complex *a, int n)
{
    FFT(a, n, 1);
    {
        for (int i = 0; i < n; i++)
        {
            a[i].real /= n;
            a[i].imag /= n;
        }
    }
}