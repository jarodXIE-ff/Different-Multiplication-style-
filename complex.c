// XIE JAROD 28710097

#include <stdio.h>
#include <math.h>
#include "complex.h"

// All usefull function
Complex add_c(Complex c1, Complex c2)
{
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex subtract_c(Complex c1, Complex c2)
{
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

Complex multiply_c(Complex c1, Complex c2)
{
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

Complex divide_c(Complex c1, Complex c2)
{
    Complex result;
    double denominator = c2.real * c2.real + c2.imag * c2.imag;
    result.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
    result.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    return result;
}

void print(Complex c)
{
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

double magnitude(Complex c)
{
    return sqrt(c.real * c.real + c.imag * c.imag);
}

double phase_angle(Complex c)
{
    return atan2(c.imag, c.real);
}

Complex create_complex_polar(double magnitude, double phase_angle)
{
    Complex result;
    result.real = magnitude * cos(phase_angle);
    result.imag = magnitude * sin(phase_angle);
    return result;
}

Complex exp_complex(Complex c)
{
    Complex result;
    double exp_real = exp(c.real);
    result.real = exp_real * cos(c.imag);
    result.imag = exp_real * sin(c.imag);
    return result;
}

Complex conjugate(Complex c)
{
    Complex result;
    result.real = c.real;
    result.imag = -c.imag;
    return result;
}

Complex sqrt_complex(Complex c)
{
    double magnitude_sqrt = sqrt(magnitude(c));
    double angle_half = 0.5 * atan2(c.imag, c.real);

    Complex result;
    result.real = magnitude_sqrt * cos(angle_half);
    result.imag = magnitude_sqrt * sin(angle_half);

    return result;
}
// to compute  (z^n)
Complex pow_complex(Complex c, int n)
{
    double magnitude_pow = pow(magnitude(c), n);
    double angle_pow = n * atan2(c.imag, c.real);

    Complex result;
    result.real = magnitude_pow * cos(angle_pow);
    result.imag = magnitude_pow * sin(angle_pow);

    return result;
}