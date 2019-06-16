#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int a,b,c;
	cin >> a;
	while (a--) {
		scanf("%d,%d", &b, &c);
		cout << b+ c<<'\n';
	}
	return 0;
	//endlÇÏ¸é ÁÙÀÌ ¶³¾îÁü cout <<  cin >>
}
