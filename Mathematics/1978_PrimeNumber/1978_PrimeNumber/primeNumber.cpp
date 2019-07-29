#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

bool isPrimeNumber(int num);

int main() {
	int N;
	int* arr;
	int primeNum = 0;
	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (isPrimeNumber(arr[i]) == true) primeNum++;
	}
	printf("%d", primeNum);
	free(arr);
	return 0;
	
}

bool isPrimeNumber(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= num/2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}