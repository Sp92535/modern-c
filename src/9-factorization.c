#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void factor(size_t n);

int main(int argc, char const *argv[])
{
    factor(atoi(argv[1]));
    return EXIT_SUCCESS;
}

void factor(size_t n)
{
    printf("[ 1 ");
    bool prime[n + 1];
    for (size_t i = 0; i <= n; i++)
        prime[i] = true;

    for (size_t i = 2; i <= n; i++)
    {
        if (!prime[i])
            continue;
        if (n % i == 0)
            printf("%ld ", i);
        while (n > 0 && n % i == 0)
            n /= i;
        for (size_t j = 2 * i; j <= n; j += i)
            prime[i] = false;
    }
    printf("]\n");
}
