#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int arr[9];
	int max = 1;
	int maxIndex = 0;
	
		do {
			scanf("%d", &arr[i]);
		} while (arr[i] < 100);
		if (arr[i] > max) {
			max = arr[i];
			maxIndex = i;
	printf("%d\n%d", max, maxIndex);
	return 0;

}