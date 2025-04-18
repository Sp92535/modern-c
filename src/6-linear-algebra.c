#include <stdio.h>
#include <stdlib.h>

#define NS 3
#define MS 4

double dot_v2v(size_t N, const double[static N], const double[static N]);
void dot_m2v(size_t M, size_t N, const double[M][N], const double[static N], double[M]);
void printArr(double arr[], size_t n);

int main()
{

    // dot product
    size_t N = NS;

    double v1[] = {1, 2, 3};
    double v2[] = {5, 9, 7};

    printf("Dot product %f\n", dot_v2v(N, v1, v2));

    // vec to matrix
    size_t M = MS;
    double mat[MS][NS] = {
        {2, 3, 6},
        {9, 74, 21},
        {4, 6, 6},
        {9, 14, 65},
    };

    double res[M];
    dot_m2v(M, N, mat, v2, res);

    printArr(res, M);

    return EXIT_SUCCESS;
}

double dot_v2v(size_t N, const double v1[static N], const double v2[static N])
{
    double res = 0;
    for (size_t i = 0; i < N; i++)
    {
        res += v1[i] * v2[i];
    }
    return res;
}

void dot_m2v(size_t M, size_t N, const double mat[M][N], const double vec[static N], double res[M])
{
    for (size_t i = 0; i < M; i++)
    {
        res[i] = dot_v2v(N, vec, mat[i]);
    }
}

// utility to print array
void printArr(double arr[], size_t n)
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("]\n");
}