#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int a,b,c;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		else
			printf("%d\n", a + b);
	}
	return 0;
	//endl«œ∏È ¡Ÿ¿Ã ∂≥æÓ¡¸ cout <<  cin >>
}
