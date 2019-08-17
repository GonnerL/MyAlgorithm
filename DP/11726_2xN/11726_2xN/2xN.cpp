#include <stdio.h>
#include <iostream>
using namespace std;

int n;
int square[1001];
void solve();

int main() {
	cin >> n;
	square[1] = 1;
	square[2] = 2;
	solve();
	printf("%d\n", square[n]);
	return 0;
}

void solve() {
	for (int i = 3; i <= 1000; i++) {
		square[i] = (square[i - 1] + square[i - 2])%10007;
	}
}