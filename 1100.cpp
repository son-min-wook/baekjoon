#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char map[8][8];
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> map[i];
	}
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j=j+2) {
				if (map[i][j] == 'F')
					count += 1;
			}
		}
		else {
			for (int j = 1; j < 8; j=j+2) {
				if (map[i][j] == 'F')
					count += 1;
			}
		}
	}
	cout << count;
	return 0;
	//endlÇÏ¸é ÁÙÀÌ ¶³¾îÁü cout <<  cin >>
}

/*#include <iostream>
#include <cstdio>
using namespace std;
char Map[8][9];
int main() {
	for (int i = 0; i < 8; i++)
		scanf("%s", Map[i]);
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && Map[i][j] == 'F')
				cnt++;
		}
	printf("%d\n", cnt);
	return 0;

}*/