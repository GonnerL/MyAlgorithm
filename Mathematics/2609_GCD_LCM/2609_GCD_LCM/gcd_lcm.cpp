#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int a, b, gcd, lcm;
	do {
		scanf("%d %d", &a, &b);
	} while (a < 1 || a>10000 || b < 1 || b>10000);
	gcd = 1;
	lcm = a * b;
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a % b == 0) gcd = b;
	else {
		while (a % b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
			gcd = b;
		}
	}

	lcm /= gcd;
	printf("%d %d\n", gcd, lcm);
	return 0;

}