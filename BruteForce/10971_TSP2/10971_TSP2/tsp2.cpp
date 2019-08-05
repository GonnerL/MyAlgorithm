#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)

void initBoard();

int N;
int leastSum = 4000000;
int* permutation;
int** W;

int main() {
	scanf("%d", &N);
	W = (int**)malloc(sizeof(int*) * N);
	permutation = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		W[i] = (int*)malloc(sizeof(int) * N);
		permutation[i] = i;
	}

	initBoard();
	sort(permutation, permutation + N);

	do {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				if (W[permutation[i]][permutation[0]] != 0) {
					sum += W[permutation[i]][permutation[0]];
					if (sum < leastSum) {
						leastSum = sum;
					}
				}
			}
			else {
				if (W[permutation[i]][permutation[i + 1]] != 0) {
					sum += W[permutation[i]][permutation[i + 1]];
				}
				else i=N;
			}
		}
	} while (next_permutation(permutation, permutation + N));
	
	printf("%d", leastSum);
	free(permutation);
	free(W);
	return 0;
}

void initBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
}