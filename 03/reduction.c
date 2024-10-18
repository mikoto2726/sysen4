#include <omp.h>  // OpenMP用のヘッダー
#include <stdio.h>
#include <stdlib.h>

#define N 10000000

int main()
{
    long long i;
    long long total = 0;

    // 実行開始時刻を記録
    double start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:total)
    for (i = 0; i < N; i++) {
        total += i;
    }

    // 実行終了時刻を記録
    double end_time = omp_get_wtime();

    printf("total = %lld\n", total);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}

