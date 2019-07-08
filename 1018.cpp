#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;
int col = 0, row = 0;
int mininum = 100;
vector<vector<int>> check(int i, int j, vector<vector<char>> mapp, vector<vector<int>>resultt) {
	int w_min = 0, b_min = 0;
	for (int q = 0; q < 8; q++) {
		for (int w = 0; w < 8; w++) {
			if ((i + q) % 2 == 0) {
				if ((j + w) % 2 == 0) {
					if (mapp[i + q][j + w] == 'W')
						continue;
					else {
						w_min++;
					}
				}
				else if ((j + w) % 2 == 1) {
					if (mapp[i + q][j + w] == 'B')
						continue;
					else {
						w_min++;
					}
				}
			}
			if ((i + q) % 2 == 1) {
				if ((j + w) % 2 == 0) {
					if (mapp[i + q][j + w] == 'B')
						continue;
					else {
						w_min++;
					}
				}
				else if ((j + w) % 2 == 1) {
					if (mapp[i + q][j + w] == 'W')
						continue;
					else {
						w_min++;
					}
				}
			}
		}
	}
	b_min = 64 - w_min;
	if (b_min < w_min)
		resultt[i][j] = b_min;
	else
		resultt[i][j] = w_min;
	return resultt;
}
int main() {
	cin >> row >> col;
	vector<vector<char>> map(row, vector<char>(col, 0));
	vector<vector<int>> result(row - 7, vector<int>(col - 7, 99));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i <= row - 8; i++) {
		for (int j = 0; j <= col - 8; j++) 
			result = check(i, j, map, result);
	}
	int mini = 999;
	for (int i = 0; i <= row - 8; i++) {
		for (int j = 0; j <= col - 8; j++) {
			if (mini > result[i][j])
				mini = result[i][j];
		}
	}
	printf("%d\n", mini);
	return 0;
}
