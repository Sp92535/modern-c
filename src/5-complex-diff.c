#include <stdio.h>
#include <complex.h>
#include<math.h>
#include <stdlib.h>

double complex F(double complex (*func_ptr)(double complex), double complex x, double complex h);
double complex diff_csin(double complex x);

int main()
{

    double complex z = 13 + 53 * I;
    double complex h = 0.001 + 0 * I;

    double complex true_diff = diff_csin(z);
    double complex calculated_diff = F(&csin, z, h);

    printf("z = %f + %fi\n",creal(z),cimag(z));
    printf("True derivative f'(z) = %f + %fi\n",creal(true_diff),cimag(true_diff));
    printf("Calculated derivative F'(z) = %f + %fi\n",creal(calculated_diff),cimag(calculated_diff));


    return EXIT_SUCCESS;
}

double complex F(double complex (*func_ptr)(double complex), double complex z, double complex h)
{
    double complex num = (*func_ptr)(z + h) - (*func_ptr)(z - h);
    double complex den = (*func_ptr)(2 * h);
    return num / den;
}

double complex diff_csin(double complex z)
{
    return ccos(z);
}
