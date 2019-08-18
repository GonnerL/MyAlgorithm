#include <stdio.h>
#include <iostream>
#define mod 1000000000
using namespace std;

long long d[101][10];
int n;
long long answer = 0;
void solve();

int main() {
	cin >> n;
	solve();
	printf("%lld\n", answer%mod);
	return 0;
}

void solve() {
	d[1][0] = 0;
	for (int i =1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) d[i][j] = (d[i - 1][j + 1])%mod;
			else if (j == 9) d[i][j] = (d[i - 1][j - 1])%mod;
			else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1])%mod;
		}
	}
	for (int i = 0; i <= 9; i++) {
		answer += (d[n][i]);
	}
}