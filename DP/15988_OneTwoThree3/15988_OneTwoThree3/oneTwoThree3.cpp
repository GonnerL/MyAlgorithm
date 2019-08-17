#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000001
using namespace std;

int t;
long d[MAX_SIZE];

void solve();

int main() {
	cin >> t;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	solve();
	for (int i = 0; i < t; i++) {
		long target;
		cin >> target;
		printf("%d\n", d[target]);
	}
	return 0;
}

void solve() {
	for (int i = 4; i < MAX_SIZE; i++) {
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3])% 1000000009;
	}
}