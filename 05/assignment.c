#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>  // MPIライブラリをインクルード

#define N 500000000

int main(int argc, char* argv[])
{
    long long i;
    long long count = 0;
    double x, y;
    int rank;

    // MPIの初期化とプロセスIDの取得
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // 各プロセスのIDを取得

    // ランダムシードをプロセスIDに基づいて設定
    srand(time(NULL) * (rank + 1));

    for (i = 0; i < N; i++) {
        x = rand() / (double)RAND_MAX;
        y = rand() / (double)RAND_MAX;

        if (x * x + y * y <= 1.0) {
            count += 1;
        }
    }

    // 計算結果の表示
    printf("Process %d: pi = %.10f\n", rank, count * 4.0 / (double)N);

    // MPIの終了処理
    MPI_Finalize();

    return 0;
}

