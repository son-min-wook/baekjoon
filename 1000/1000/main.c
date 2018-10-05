#include <stdio.h>
int main()
{
	int a = -1, b = -1;
	do {
		scanf("%d %d", &a, &b);
	} while (0 >= a || 10 <= a && 0 >= b || 10 <= b);
	printf("%d\n", a + b);
	return 0;
}