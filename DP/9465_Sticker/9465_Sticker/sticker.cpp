#include <stdio.h>
#include <iostream>
using namespace std;

int t;
int board[3][100001];
int d[100001][3];
void solve(int n);
int max(int a, int b);

int main() {
	cin >> t;
	while(t>0) {
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> board[i][j];
			}
		}
		solve(n);
		t--;
	}
	return 0;
}

void solve(int n) {
	d[1][0] = 0; d[1][1] = board[1][1]; d[1][2] = board[2][1];
	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 1][1], d[i - 1][2]);
		d[i][1] = max(d[i][0],board[1][i] + d[i - 1][2]);
		d[i][2] = max(d[i][0],board[2][i] + d[i - 1][1]);
	}
	if (d[n][1] > d[n][2]) printf("%d\n", d[n][1]);
	else printf("%d\n", d[n][2]);
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}