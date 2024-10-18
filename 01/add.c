#include <stdio.h>
#include <stdlib.h>

#define N 10000000000

int main()
{
    long long i;
    long long total = 0;

    for (i = 0; i < N; i++) {
        total += i;
    }

    printf("total = %lld\n", total);
    return 0;
}