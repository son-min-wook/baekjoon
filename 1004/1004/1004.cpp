#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int i,ex, pla = 0,count = 0,start[2],end[2],sample[3];
	scanf("%d", &ex);
	int *arr = (int*)malloc(sizeof(int)*ex);
	for (i = 0; i < ex; i++) {
		scanf("%d %d %d %d", &start[0], &start[1], &end[0], &end[1]);
		scanf("%d", &pla);
		for (int j = 0; j < pla; j++) {
			scanf("%d %d %d", &sample[0], &sample[1], &sample[2]);
			if (sqrt(pow(sample[0] - start[0], 2) + pow(sample[1] - start[1], 2)) < sample[2] || sqrt(pow(sample[0] - end[0], 2) + pow(sample[1] - end[1], 2)) < sample[2]) {
				count++;
				if (sqrt(pow(sample[0] - start[0], 2) + pow(sample[1] - start[1], 2)) < sample[2] && sqrt(pow(sample[0] - end[0], 2) + pow(sample[1] - end[1], 2)) < sample[2])
					count = count - 1;
			}
		}
		arr[i] = count;
		count = 0;
	}
	for (int k = 0; k < ex; k++)
		printf("%d\n", arr[k]);
	return 0;
}