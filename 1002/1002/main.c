#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int example = 0, i = 0;
	float *x1, *y1, *r1, *x2, *y2, *r2;
	float *length;
	scanf("%d", &example);
	x1 = (float*)malloc(sizeof(float)*example);
	y1 = (float*)malloc(sizeof(float)*example);
	r1 = (float*)malloc(sizeof(float)*example);
	x2 = (float*)malloc(sizeof(float)*example);
	y2 = (float*)malloc(sizeof(float)*example);
	r2 = (float*)malloc(sizeof(float)*example);
	length = (float*)malloc(sizeof(float)*example);
	for (i = 0; i < example; i++) {
		scanf("%f %f %f %f %f %f", &x1[i], &y1[i], &r1[i], &x2[i], &y2[i], &r2[i]);
		length[i] = sqrt(pow(x2[i] - x1[i], 2.0) + pow(y2[i] - y1[i], 2.0));
	}
	for (i = 0; i<example; i++) {
		if (r1[i] + length[i] < r2[i] || r2[i] + length[i] < r1[i])
			printf("0\n");
		else if (length[i] == 0 && r1[i] == r2[i]) {
			if (r1[i] == 0)
				printf("1\n");
			else
				printf("-1\n");
		}
		else if (length[i] == 0 && r1[i] != r2[i])
			printf("0\n");
		else if (length[i] + r2[i] == r1[i] || length[i] + r1[i] == r2[i])
			printf("1\n");
		else {
			if (length[i] < r1[i] + r2[i])
				printf("2\n");
			else if (length[i] == r1[i] + r2[i])
				printf("1\n");
			else
				printf("0\n");
		}
	}
}

