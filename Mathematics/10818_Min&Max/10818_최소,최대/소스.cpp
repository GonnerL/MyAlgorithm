#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int times;
	int max=-1000000;
	int min=1000000;
	int* arr;
	do {
		scanf("%d", &times);
	} while (times < 1 || times>1000000);
	arr = (int*)malloc(sizeof(int) * times);
	for (int i = 0; i < times; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	printf("%d %d", min, max);
	free(arr);
	return 0;
}