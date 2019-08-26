#include <stdio.h>
#include <iostream>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char board[21][21];
bool check[30];
int ans = 1;
int r, c;

void search(int row, int col, bool* check, int cnt);

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	int visit = board[0][0] - 65;
	check[visit] = true;
	search(0, 0,check,1);
	printf("%d\n", ans);
	return 0;
}

void search(int row, int col, bool* check,int cnt) {
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + row;
		int nx = dx[i] + col;
		int visit = board[ny][nx] - 65;
		if (ny < 0 || nx < 0 || check[visit]==true || ny >= r || nx >= c) continue;
		check[visit] = true;
		search(ny, nx, check, cnt + 1);
		check[visit] = false;
	}
	if (cnt > ans) ans = cnt;
}