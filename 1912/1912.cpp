#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	char *arr = (char*)malloc(sizeof(a));
	gets_s(arr,sizeof(a));
	printf("%s ", arr);
	int *num = (int*)malloc(sizeof(a));
	*num = atoi(strtok(arr, " "));
	for (i = 0; i < a; i++) {
		printf("%d", &num[i]);
	}
	int max = arr[0];
	int result = arr[0];
	for (i = 1; i < a; i++) {
		int result_now = 0;
		if (max<0 & arr[i]>max) {
			max = arr[i];
		}
		else if (result >= 0) {
			result_now = result + arr[i];
			if (result_now > max) {
				max = result_now;
				if (result_now < 0) {
					max = result;
					result = 0;
				}
				else
					result = result_now;
			}
		}
	}
	printf("%d", max);
}