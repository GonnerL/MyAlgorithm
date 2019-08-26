#include <stdio.h>
#include <iostream>
using namespace std;
int sudoku[9][9];
bool c3[9][9];
bool c1[9][9];
bool c2[9][9];
void search(int z);
int square(int y, int x);

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j]!=0) {
				c1[i][sudoku[i][j]] = true;
				c2[j][sudoku[i][j]] = true;
				c3[square(i, j)][sudoku[i][j]] = true;
			}
		}
	}
	search(0);
	return 0;
}

void search(int z) {
	if (z == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int y = z / 9;
	int x = z % 9;
	if(sudoku[y][x] != 0) {
		search(z + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (c1[y][i] == false && c2[x][i] == false && c3[square(y, x)][i] == false) {
				c1[y][i] = c2[x][i] = c3[square(y, x)][i] = true;
				sudoku[y][x] = i;
				search(z + 1);
				c1[y][i] = c2[x][i] = c3[square(y, x)][i] = false;
				sudoku[y][x] = 0;
			}
		}
	}
}


int square(int y, int x) {
	return (y / 3) * 3 + (x / 3);
}