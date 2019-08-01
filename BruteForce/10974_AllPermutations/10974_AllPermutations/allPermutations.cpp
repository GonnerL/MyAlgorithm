#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int* permutation;

int main() {
	int N;
	scanf("%d", &N);
	permutation = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		permutation[i] = i + 1;
	}
	sort(permutation, permutation + N);
	do {
		for (int i = 0; i < N; i++) {
			printf("%d ", permutation[i]);
		}
		printf("\n");
	} while (next_permutation(permutation, permutation + N));

	free(permutation);
	return 0;

}