#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n = 0,i=0,creat=0,t=0;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		t = i;
		creat = i;
		while (t != 0) {
			creat = creat + t % 10;    //1의자리더함
			t = t / 10;
		}
		if (creat == n) {
			printf("%d\n",i);
				break;
		}
		creat = 0;
	}
	if (i == n)
		printf("0");
}