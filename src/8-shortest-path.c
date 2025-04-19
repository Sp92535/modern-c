#include <stdio.h>
#include <stddef.h>
#include <math.h>
#define N 10

// We'll apply Warshall's Algorithm although it is slower

void shortest_path(size_t graph[N][N]);

int main()
{
    size_t graph[10][10] = {
        {29, __SIZE_MAX__, 37, 61, __SIZE_MAX__, 94, __SIZE_MAX__, __SIZE_MAX__, 88, 52},
        {__SIZE_MAX__, 17, 3, __SIZE_MAX__, __SIZE_MAX__, 7, 26, __SIZE_MAX__, __SIZE_MAX__, 49},
        {91, 67, __SIZE_MAX__, 85, __SIZE_MAX__, 1, __SIZE_MAX__, 0, __SIZE_MAX__, __SIZE_MAX__},
        {__SIZE_MAX__, __SIZE_MAX__, 44, 99, __SIZE_MAX__, __SIZE_MAX__, 13, 11, 10, __SIZE_MAX__},
        {36, __SIZE_MAX__, __SIZE_MAX__, 81, 96, __SIZE_MAX__, 19, __SIZE_MAX__, 65, 20},
        {__SIZE_MAX__, 77, __SIZE_MAX__, __SIZE_MAX__, 58, 92, 76, __SIZE_MAX__, __SIZE_MAX__, 33},
        {9, __SIZE_MAX__, 22, 45, __SIZE_MAX__, 40, __SIZE_MAX__, 73, __SIZE_MAX__, 97},
        {__SIZE_MAX__, __SIZE_MAX__, 59, __SIZE_MAX__, 28, 35, 86, __SIZE_MAX__, 69, __SIZE_MAX__},
        {31, 62, __SIZE_MAX__, 80, __SIZE_MAX__, __SIZE_MAX__, 43, __SIZE_MAX__, 79, 25},
        {__SIZE_MAX__, 48, __SIZE_MAX__, __SIZE_MAX__, 84, __SIZE_MAX__, 91, 18, __SIZE_MAX__, 6},
    };

    shortest_path(graph);

    size_t src = 3, dst = 5;

    printf("shortest path from %ld -> %ld = %ld\n", src, dst, graph[src][dst]);
}

void shortest_path(size_t graph[N][N])
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (j == i)
                continue;
            for (size_t k = 0; k < N; k++)
            {
                if (k == i)
                    continue;
                if (graph[i][k] < __SIZE_MAX__ && graph[j][i] < __SIZE_MAX__)
                    graph[j][k] = fmin(graph[j][k], graph[i][k] + graph[j][i]);
            }
        }
    }
}
