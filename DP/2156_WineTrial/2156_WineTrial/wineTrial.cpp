#include <stdio.h>
#include <iostream>
using namespace std;

int n;
int wine[10001];
int drink[10001][3];

void solve();
int max(int a, int b,int c);

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	solve();
	return 0;
}

void solve(){
	drink[1][1] = wine[1];
	for (int i = 2; i <= n; i++) {
		drink[i][0] = max(drink[i-1][0],drink[i - 1][1], drink[i - 1][2]);
		drink[i][1] = drink[i - 1][0] + wine[i];
		drink[i][2] = drink[i - 1][1] + wine[i];
	}
	int max = drink[n][0];
	for (int i = 1; i <= 2; i++) {
		if (drink[n][i] > max) max = drink[n][i];
	}
	printf("%d\n", max);
}

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c) return a;
		else return c;
	}
	else {
		if (b > c) return b;
		else return c;
	}
}