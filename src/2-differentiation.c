#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double F(double (*func_ptr)(double), double x, double h);
double diff_sin(double x);

int main()
{

	double x[] = {0, 1, 2, 3, 4, 5, 6, 7};
	double h = 0.001;

	for (int i = 0; i < 8; i++){
		printf("f(%f) = sin(%f) = %f  \t| ", x[i], x[i], sin(x[i]));
		printf("calculated F(%f): %f  \t| ", x[i], F(&sin, x[i], h));
		printf("true F(%f): %f\n", x[i], diff_sin(x[i]));
	}

	return EXIT_SUCCESS;
}

double F(double (*func_ptr)(double), double x, double h)
{
	double num = (*func_ptr)(x + h) - (*func_ptr)(x - h);
	double den = (*func_ptr)(2 * h);
	return num / den;
}

double diff_sin(double x)
{
	return cos(x);
}
