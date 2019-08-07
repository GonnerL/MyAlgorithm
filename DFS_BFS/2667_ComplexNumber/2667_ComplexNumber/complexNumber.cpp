#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int apart[26][26] = { 0, };
int apartNum[25*25];
int check[26][26] = { 0, };
int N;
int apartNo = 0;

void dfs(int y,int x);

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &apart[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (apart[i][j] == 1&&check[i][j]==0) {
				dfs(i, j);
				apartNo++;
			}
		}
	}
	printf("%d\n", apartNo);
	sort(apartNum, apartNum + apartNo);
	for (int i = 0; i < apartNo; i++) {
		printf("%d\n", apartNum[i]);
	}
}

void dfs(int y, int x) {
	apartNum[apartNo]++;
	check[y][x] = 1;
	if (y - 1 >= 0) {
		if (apart[y - 1][x] != 0 && check[y-1][x]==0) {
			check[y - 1][x] = 1;
			dfs(y - 1, x);
		}
	}
	if (y + 1 <= N - 1) {
		if (apart[y + 1][x] != 0 && check[y+1][x] == 0) {
			check[y + 1][x] = 1;
			dfs(y + 1, x);
		}
	}
	if (x + 1 <= N - 1) {
		if (apart[y][x + 1] != 0 && check[y][x+1] == 0) {
			check[y][x + 1] = 1;
			dfs(y, x + 1);
		}
	}
	if (x - 1 >= 0) {
		if (apart[y][x - 1] != 0 && check[y][x-1] == 0) {
			check[y][x - 1] = 1;
			dfs(y, x - 1);
		}
	}
}