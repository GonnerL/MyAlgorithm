#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main() {
	int n, t;
	int** arr;
	long* result;
	int* size;

	do {
		scanf("%d", &t);
	} while (t < 1 || t>100);
	arr = (int**)malloc(sizeof(int*) * t);
	result = (long*)malloc(sizeof(long) * t);
	size = (int*)malloc(sizeof(int) * t);
	for (int i = 0; i < t; i++) {
		do {
			scanf("%d", &n);
		} while (n < 1 || n>100);
		
		arr[i] = (int*)malloc(sizeof(int) * n);
		size[i] = n;
		for (int j = 0; j < n; j++) {
			do {
				scanf("%d", &arr[i][j]);
			} while (arr[i][j] > 1000000);
		}
	}
	long gcdSum = 0;
	int k = 0;
	while (k < t) {
		for (int i = 0; i < size[k]-1; i++) {
			for (int j = i + 1; j < size[k]; j++) {
				gcdSum += gcd(arr[k][i], arr[k][j]);
			}
		}
		result[k] = gcdSum;
		gcdSum = 0;
		k++;
	}
	for (int i = 0; i < t; i++) {
		printf("%ld\n", result[i]);
	}

	free(arr);
	free(result);
	free(size);
	return 0;
}