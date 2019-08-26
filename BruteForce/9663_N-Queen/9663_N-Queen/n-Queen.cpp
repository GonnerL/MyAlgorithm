#include <stdio.h>
#include <iostream>
using namespace std;

bool check_col[15];
bool check_dig[30];
bool check_dig2[30];
bool board[15][15];

int n;
int ans = 0;

void search(int row);
bool checking(int row, int col);

int main() {
	cin >> n;
	search(0);
	printf("%d\n", ans);

	return 0;
}

void search(int row) {
	if (row == n) {
		ans += 1;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (checking(row,i)) {
			check_col[i] = true;
			check_dig[row - i+n] = true;
			check_dig2[row + i] = true;
			board[row][i] = true;
			search(row + 1);
			check_col[i] = false;
			check_dig[row - i+n] = false;
			check_dig2[row + i] = false;
			board[row][i] = false;
		}
	}
}

bool checking(int row, int col) {
	if (check_col[col]) return false;
	if (check_dig[row - col + n]) return false;
	if (check_dig2[row + col]) return false;
	return true;
}