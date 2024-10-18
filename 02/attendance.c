#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a, *b, *c;
	int i;

	srand(0);

	a = (int *)malloc(3 * sizeof(int));
	b = (int *)malloc(3 * sizeof(int));
	c = (int *)malloc(3 * sizeof(int));

	for (i = 0; i < 3; i++){
		a[i] = rand() % 100;
		b[i] = rand() % 100;
		printf("a[%d] = %d, b[%d] = %d\n", i, a[i],i, b[i]);
	}

	for (i = 0; i < 3; i++){
		c[i] = a[i] + b[i];
		printf("c[%d] = a[%d] + b[%d] = %d\n", i, i, i, c[i]);
	}
	
	free(a);
	free(b);
	free(c);

	return 0;

}
