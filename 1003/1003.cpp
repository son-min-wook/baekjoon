#include <stdio.h>
#include <stdlib.h>
int fib[40];
int leng = 1;
int fi(int a, int b) {
	fib[leng + 1] = fib[a] + fib[b];
	leng++;
	return 0;
}
int main()
{
	fib[0] = 0;
	fib[1] = 1;
	int fibd, ex, i = 0;
	scanf("%d", &ex);
	int *arr = (int*)malloc(sizeof(int)*ex);
	for (i = 0; i < ex; i++) {
		scanf("%d", &fibd);
		arr[i] = fibd;
		if (fibd > leng) {
			for (int j = leng - 1; j < fibd - 1; j++)
				fi(j, j + 1);
		}
	}
	for (i = 0; i < ex; i++) {
		if (arr[i] == 1)
			printf("0 1\n");
		else if (arr[i] == 0)
			printf("1 0\n");
		else
			printf("%d %d\n", fib[arr[i] - 1], fib[arr[i]]);
	}
	return 0;
}