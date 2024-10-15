// XIE JAROD 28710097

#ifndef FFT_IFFT_H
#define FFT_IFFT_H
#include "complex.h"

void FFT(Complex *x, int N, int invert);
void IFFT(Complex *x, int N);

#endif