// XIE JAROD 28710097

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getElapsedTime(clock_t start, clock_t end)
{
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

long long getElapsedTimeInMicroseconds(struct timespec start, struct timespec end)
{
    return (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_nsec - start.tv_nsec) / 1000LL;
}

// Structure to represent a term in a polynomial
typedef struct
{
    int coefficient;
    int exponent;
} Term;

// Function to multiply two polynomials
Term *multiplyPolynomials(const Term *poly1, int size1, const Term *poly2, int size2, int *resultSize)
{
    // Allocate memory for the result polynomial
    *resultSize = size1 * size2;
    Term *result = (Term *)malloc((*resultSize) * sizeof(Term));

    // Initialize result polynomial
    for (int i = 0; i < *resultSize; i++)
    {
        result[i].coefficient = 0;
        result[i].exponent = 0;
    }

    // Multiply each term of poly1 with each term of poly2
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            int coeff = poly1[i].coefficient * poly2[j].coefficient;
            int exp = poly1[i].exponent + poly2[j].exponent;

            // Add the result to the corresponding term in the result polynomial
            result[i * size2 + j].coefficient += coeff;
            result[i * size2 + j].exponent += exp;
        }
    }

    return result;
}

Term *assembleLikeTerms(const Term *poly, int size, int *newSize)
{
    // Allocate memory for the result polynomial
    Term *result = (Term *)malloc(size * sizeof(Term));

    // Initialize result polynomial
    for (int i = 0; i < size; i++)
    {
        result[i].coefficient = 0;
        result[i].exponent = 0;
    }

    // Traverse the input polynomial and accumulate terms with the same exponent
    for (int i = 0; i < size; i++)
    {
        int exp = poly[i].exponent;
        result[exp].coefficient += poly[i].coefficient;
        result[exp].exponent = exp;
    }

    // Filter out terms with zero coefficients
    *newSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (result[i].coefficient != 0)
        {
            (*newSize)++;
        }
    }

    // Resize the result polynomial to remove unused space
    result = (Term *)realloc(result, (*newSize) * sizeof(Term));

    return result;
}

// Function to display a polynomial
void displayPolynomial(const Term *poly, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (poly[i].coefficient == 0)
        {
            continue;
        }
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        if (i < size - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *file = fopen("Time_NAIVE_MULT.txt", "a");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Remove quote to try with small polynomial (dont forget to remove quote for free)
    /*
    Term poly1[] = {{2, 2}, {3, 1}, {4, 0}};
    Term poly2[] = {{1, 1}, {5, 0}};

    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);
    printf("Example of 2 polynomial to multiply\n");
    displayPolynomial(poly1, size1);
    displayPolynomial(poly2, size2);
    printf("Multiplication of the 2 polynomial\n");
    int resultSize;
    Term *result = multiplyPolynomials(poly1, size1, poly2, size2, &resultSize);

    printf("Result before assembling like terms: ");
    displayPolynomial(result, resultSize);

    // Assemble like terms
    int newSize;
    Term *assembledResult = assembleLikeTerms(result, resultSize, &newSize);

    // Display the assembled result
    printf("Result after assembling like terms: ");
    displayPolynomial(assembledResult, newSize);
    */

    // BENCHMARKING PART !!!
    int n = atoi(argv[1]); // DONT FORGET TO WRITE IN THE TERMINAL THE NUMBER
    Term poly3[n];
    Term poly4[n];
    // Remplir le tableau avec des nombres entre 1 et 10
    for (int i = 0; i < n; i++)
    {
        poly3[i].coefficient = rand() % 10;
        poly3[i].exponent = i;

        poly4[i].coefficient = rand() % 10;
        poly4[i].exponent = i;
    }

    int size3 = sizeof(poly3) / sizeof(poly3[0]);
    int size4 = sizeof(poly4) / sizeof(poly4[0]);

    // Multiply polynomials
    int resultSize2;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    Term *result2 = multiplyPolynomials(poly3, size3, poly4, size4, &resultSize2);
    clock_gettime(CLOCK_MONOTONIC, &end);

    long long elapsedTime = getElapsedTimeInMicroseconds(start, end);
    printf("itération %d\n", n);
    // printf("Time taken by FFT_mult: %lld microseconds\n", elapsedTime);
    fprintf(file, "%d %lld\n", n, elapsedTime);
    // Free dynamically allocated memory
    // free(result);
    free(result2);
    // free(assembledResult);
    return 0;
}