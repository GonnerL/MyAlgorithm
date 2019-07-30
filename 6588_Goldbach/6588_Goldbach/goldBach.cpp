#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_SIZE 1000001
int numList[MAX_SIZE];
int findPrimeSet(int n);

int main() {
	int n;
	for (int i = 2; i * i <= MAX_SIZE; i++) {
		if (numList[i] == 0) {
			for (int j = i + i; j <= MAX_SIZE; j = j + i) {
				numList[j] = -1;
			}
		}
	}
	do {
		scanf("%d", &n);
		if (n == 0) break;
		int answer = findPrimeSet(n);
		if (answer != -1) printf("%d = %d + %d\n", n, answer, n - answer);
		else  printf("Goldbach's conjecture is wrong.");
	} while (n != 0);
}

int findPrimeSet(int num) {
	int answer = -1;
	for(int i = 2 ; i <= num/2; i++) {
		if (numList[i]+numList[num-i]==0) {
			answer = i;
			break;
		}
	}
	return answer;
}