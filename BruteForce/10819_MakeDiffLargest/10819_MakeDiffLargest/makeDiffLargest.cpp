#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)

int calculate(int* permutation);

int* permutation;
int N;
int bestSum=0;

int main() {
	scanf("%d", &N);
	permutation = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &permutation[i]);
	}
	sort(permutation, permutation + N);
	do {
		bestSum = calculate(permutation);
	} while (next_permutation(permutation, permutation + N));
	printf("%d", bestSum);
	free(permutation);
	return 0;
}

int calculate(int* permutation) {
	int sum=0;
	for (int i = 0; i < N-1; i++) {
		sum += (int)abs(permutation[i] - permutation[i + 1]);
	}
	if (sum > bestSum) return sum;
	else return bestSum;
}