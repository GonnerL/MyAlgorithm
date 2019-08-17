#include <stdio.h>
#include <iostream>
using namespace std;
#define modulo 1000000009
#define MAX_SIZE 100001
int t;
int n;
long long d[MAX_SIZE][4] = { 0, };
void solve();

int main() {
	cin >> t;
	solve();
	for (int i = 0; i < t; i++) {
		long long answer = 0;
		cin >> n;
		for (int j = 1; j <= 3; j++) {
			answer += d[n][j];
		}
		printf("%lld\n", answer%modulo);
	}
	return 0;
}

void solve() {
	d[1][1] = 1; d[2][2] = 1; 
	d[3][3] = 1; d[3][1] = 1; d[3][2] = 1;
	for (int i = 4; i < MAX_SIZE; i++) {
		d[i][1] = (d[i - 1][2] + d[i - 1][3])%modulo;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % modulo;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % modulo;
	}
}