// XIE JAROD 28710097

#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct
{
    double real;
    double imag;
} Complex;

Complex add_c(Complex c1, Complex c2);
Complex subtract_c(Complex c1, Complex c2);
Complex multiply_c(Complex c1, Complex c2);
Complex divide_c(Complex c1, Complex c2);
void print(Complex c);
double magnitude(Complex c);
double phase_angle(Complex c);
Complex create_complex_polar(double magnitude, double phase_angle);
Complex exp_complex(Complex c);
Complex conjugate(Complex c);
Complex sqrt_complex(Complex c);
Complex pow_complex(Complex c, int n);

#endif