#include <stdio.h>
#include <iostream>
#define mod 10007
using namespace std;

int n,answer=0;
int d[1001][10];
void solve();

int main() {
	cin >> n;
	solve();
	printf("%d\n", answer%mod);
	return 0;
}

void solve() {
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += (d[i - 1][k])%mod;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		answer += d[n][i];
	}
}