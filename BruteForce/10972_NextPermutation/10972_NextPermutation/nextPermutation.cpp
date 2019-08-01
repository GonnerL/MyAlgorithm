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
		scanf("%d", &permutation[i]);
	}
	if (next_permutation(permutation,permutation+N)) {
		for (int i = 0; i < N; i++) {
			printf("%d ", permutation[i]);
		}
	}
	else {
		printf("-1");
	}

	free(permutation);
	return 0;

}