#include <stdio.h>
#include <iostream>
using namespace std;

int t;
int d[11];

void solve();

int main() {
	cin >> t;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	solve();
	for (int i = 0; i < t; i++) {
		int target;
		cin >> target;
		printf("%d\n", d[target]);
	}
	return 0;
}

void solve() {
	for (int i = 4; i < 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
}