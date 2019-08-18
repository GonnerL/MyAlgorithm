#include <stdio.h>
#include <iostream>
using namespace std;

int n;
long long d[91];

int main() {
	cin >> n;
	d[0] = 0; d[1] = 1; d[2] = 1;
	for (int i = 3; i <= 90; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	printf("%lld\n", d[n]);
	return 0;
}