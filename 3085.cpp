#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
int n, maxnum=0;
char map[50][50];
int search_right(int i,int j) {
	int count = 0;
	for (int q = j; q < n; q++) {
		if (map[i][j] == map[i][q])
			count++;
		else
			return count;
	}
	return count;
}
int search_down(int  i, int j) {
	int count = 0;
	for (int q = i; q < n; q++) {
		if (map[i][j] == map[q][j])
			count++;
		else
			return count;
	}
	return count;
}
int maxi(int a, int b) {
	return a > b ? a : b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 2; k++) {
				int di = i + dx[k];
				int dj = j + dy[k];
				if (di<0 || dj<0 || di>n - 1 || dj>n - 1)
					continue;
				else {
					//printf("%d %d\n", di, dj);
					char temp = 0;
					temp = map[i][j];
					map[i][j] = map[di][dj];
					map[di][dj] = temp;           //변환완료
					int right, down,m;
					for (int z = 0; z < n; z++) {
						for (int x = 0; x < n; x++) {
							right = search_right(z, x);
							down = search_down(z, x);
							//printf("right: %d down: %d\n", right, down);
							m = maxi(right, down);
							if (m > maxnum) {
								maxnum = m;
								/*for (int b = 0; b < n; b++)
									printf("%s\n", map[b]);
								printf("\n");*/
							}
						}
					}
					temp = map[i][j];
					map[i][j] = map[di][dj];
					map[di][dj] = temp;           //원상복귀
				}
			}
		}
	}
	printf("%d\n", maxnum);
	return 0;
}

