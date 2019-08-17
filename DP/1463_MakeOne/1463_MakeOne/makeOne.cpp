#include <stdio.h>
#include <iostream>
#include <memory.h>
#define MAX_SIZE 1000001
using namespace std;

int n;
void solve(int x);
int d[MAX_SIZE];

int main() {
	cin >> n;
	memset(d, 0, sizeof(d));
	solve(n);
	printf("%d\n", d[n]);
	return 0;
}

void solve(int x) {
	d[1] = 0;
	for (int i = 2; i <= x; i++) {
		if (d[i] > 0) continue;
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0) {
			int temp = d[i / 3] + 1;
			if (temp < d[i]) d[i] = temp;
		}
		if (i % 2 == 0) {
			int temp = d[i / 2] + 1;
			if (temp < d[i]) d[i] = temp;
		}
	}
}