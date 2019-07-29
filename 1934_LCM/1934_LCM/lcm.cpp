#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int gcd(int a, int b);

int main() {
	int T;
	int* arr;
	do {
		scanf("%d", &T);
	} while (T < 1 || T>1000);
	arr = (int*)malloc(sizeof(int) * T*2);
	for (int i = 0; i < 2*T; i=i+2) {
		scanf("%d %d", &arr[i], &arr[i + 1]);
	}
	for (int i = 0; i < 2 * T; i = i + 2) {
		printf("%d\n", arr[i] * arr[i + 1] / gcd(arr[i], arr[i + 1]));
	}
	free(arr);
}

int gcd(int a, int b) {
	int gcd = 1;
	if (a % b == 0) return b;
	else {
		while (a % b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		gcd = b;
	}
	return gcd;
}