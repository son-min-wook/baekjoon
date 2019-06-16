#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	int a;
	scanf("%d", &a);
	while (a--) {
		int b;
		string str,cop;
		cin>>b>>str;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < b; j++) {
				cop = cop + str[i];
			}
		}
		cout << cop << '\n';
	}
	return 0;
	//endlÇÏ¸é ÁÙÀÌ ¶³¾îÁü cout <<  cin >>
}
