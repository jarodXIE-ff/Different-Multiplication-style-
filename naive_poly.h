// XIE JAROD 28710097

#ifndef NAIVE_POLY_H
#define NAIVE_POLY_H

typedef struct
{
    int coefficient;
    int exponent;
} Term;

Term *multiplyPolynomials(const Term *poly1, int size1, const Term *poly2, int size2, int *resultSize);
Term *assembleLikeTerms(const Term *poly, int size, int *newSize);
void displayPolynomial(const Term *poly, int size);

#endif