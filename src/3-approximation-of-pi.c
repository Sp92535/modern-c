#include <stdio.h>
#include <stdlib.h>

double lebniz(int terms);

int main()
{
    int n = 10000000;

    printf("terms :%d --> %f\n", n, lebniz(n));

    return EXIT_SUCCESS;
}

double lebniz(int terms)
{
    double quater_pi = 0.0;

    for (int i = 0; i < terms; i++)
    {
        quater_pi += i % 2 ? (1.0 / (2.0 * i + 1.0)) : -(1.0 / (2.0 * i + 1.0));
    }
    return quater_pi * 4.0;
}