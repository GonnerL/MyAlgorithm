#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int sea[50][50] = { 0, };
bool check[50][50] = { false, };
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int dy[] = { 0, 0,1,-1,1,1,-1,-1 };

int w, h;
int num = 0;

void search(int y, int x);
bool isValid(int y, int x);

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> sea[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (sea[i][j] == 1 && check[i][j] == false) {
					search(i, j);
					num++;
				}
			}
		}
		printf("%d\n", num);
		num = 0;
		memset(check, false, sizeof(check));
		memset(sea, 0, sizeof(sea));
	}
}

void search(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isValid(ny,nx) && check[ny][nx] == false && sea[ny][nx]==1) {
			search(ny, nx);
		}
	}
}

bool isValid(int y, int x) {
	if (x >= 0 && y >= 0 && x <= w - 1 && y <= h - 1) {
		return true;
	}
	return false;
}