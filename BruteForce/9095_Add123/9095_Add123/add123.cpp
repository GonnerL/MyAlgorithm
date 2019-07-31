#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int T;
	int* numbers;
	int* answers;

	scanf("%d", &T);
	numbers = (int*)malloc(sizeof(int) * T);
	answers = (int*)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &numbers[i]);
		answers[i] = 0;
	}
	for (int i = 0; i < T; i++) {
		for (int x1 = 1; x1 <= 3; x1++) {
			if (x1 == numbers[i]) answers[i]++;
			for (int x2 = 1; x2 <= 3; x2++) {
				if (x1 + x2 == numbers[i]) answers[i]++;
				for (int x3 = 1; x3 <= 3; x3++) {
					if (x1 + x2 + x3== numbers[i]) answers[i]++;
					for (int x4 = 1; x4 <= 3; x4++) {
						if (x1 + x2 + x3 + x4== numbers[i]) answers[i]++;
						for (int x5 = 1; x5 <= 3; x5++) {
							if (x1 + x2 + x3 + x4 + x5 == numbers[i]) answers[i]++;
							for (int x6 = 1; x6 <= 3; x6++) {
								if (x1 + x2 + x3 + x4 + x5 + x6 == numbers[i]) answers[i]++;
								for (int x7 = 1; x7 <= 3; x7++) {
									if (x1 + x2 + x3 + x4 + x5 + x6 + x7 == numbers[i]) answers[i]++;
									for (int x8 = 1; x8 <= 3; x8++) {
										if (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 == numbers[i]) answers[i]++;
										for (int x9 = 1; x9 <= 3; x9++) {
											if (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 == numbers[i]) answers[i]++;
											for (int x10 = 1; x10 <= 3; x10++) {
												if (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 == numbers[i]) answers[i]++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < T; i++) {
		printf("%d\n", answers[i]);
	}
	free(answers);
	free(numbers);
	return 0;

}