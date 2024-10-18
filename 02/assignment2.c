#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	
	int n = 64;
	if (argc > 1){
		n = atoi(argv[1]);
	}

	int **A = (int **)malloc(n * sizeof(int *));
	int **B = (int **)malloc(n * sizeof(int *));
	int **C = (int **)malloc(n * sizeof(int *));
	
	for (int i = 0; i < n; i++){
		A[i] = (int *)malloc(n * sizeof(int));
		B[i] = (int *)malloc(n * sizeof(int));
		C[i] = (int *)malloc(n * sizeof(int));
	}

	srand(time(NULL));
	for (int i=0; i < n; i++){
		for (int j=0; j < n; j++){
			A[i][j] = rand() % 100;
			B[i][j] = rand() % 100;
			C[i][j] = 0;
		}
	}
	
	#pragma omp paralell for private(j)
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf("行列cの結果:\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < n; i++){
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);

	return 0;	
}

