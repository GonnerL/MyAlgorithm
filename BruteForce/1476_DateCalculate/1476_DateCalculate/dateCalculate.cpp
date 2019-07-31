#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	if (E == S && S == M) printf("%d\n", E);
	else {
		int x = 0;
		while (true) {
			if ((15 * x + E) % 28 == S && (15 * x + E) % 19 == M) {
				break;
			}
			if (S == 28 || M == 19) {
				if (S == 28 && M == 19 && (15 * x + E) % 28 == 0 && (15 * x + E) % 19 == 0) {
					break;
				}
				else if (S != 28 && M == 19 && (15 * x + E) % 28 == S && (15 * x + E) % 19 == 0) {
					break;
				}
				else if (S == 28 && M != 19 && (15 * x + E) % 28 == 0 && (15 * x + E) % 19 == M) {
					break;
				}
			}
			x++;
		}
		printf("%d\n", 15 * x + E);
	}

	return 0;
}