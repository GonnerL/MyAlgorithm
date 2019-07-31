#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int** board;
int bestScore = 4;


int main() {
	int N, M;
	
	scanf("%d %d", &N, &M);
	board = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		board[i] = (int*)malloc(sizeof(int) * M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	}



	if (bestScore == 4000) printf("%d",bestScore);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//1
			if (i + 3 <= N-1) {
				if (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j] > bestScore) {
					bestScore=board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
				}
			}
			//2
			if (j + 3 <= M-1) {
				if (board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3] > bestScore) {
					bestScore = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
				}
			}
			//3
			if (j + 1 <= M-1 && i + 1 <= N-1) {
				if (board[i][j] + board[i][j + 1] + board[i+1][j] + board[i+1][j+1] > bestScore) {
					bestScore = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
				}
			}
			//4
			if (i + 2 <= N - 1 && j + 1 <= M - 1){
				if (board[i][j] + board[i+1][j] + board[i + 2][j] + board[i + 2][j + 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
				}
			}
			//5
			if (i + 1 <= N - 1 && j - 2 >= 0) {
				if (board[i][j] + board[i + 1][j] + board[i+1][j-1] + board[i+1][j - 2] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 1][j - 2];
				}
			}
			//6
			if (i + 2 <= N - 1 && j + 1 <= M - 1) {
				if (board[i][j] + board[i + 1][j+1] + board[i + 2][j+1] + board[i][j + 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i][j + 1];
				}
			}
			//7
			if (i + 1 <= N - 1 && j + 2 <= M - 1) {
				if (board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i][j + 2] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i][j + 2];
				}
			}
			//8
			if (i + 2 <= N - 1 && j - 1 >= 0) {
				if (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1];
				}
			}
			//9
			if (i + 1 <= N - 1 && j + 2 <= M - 1) {
				if (board[i][j] + board[i][j+1] + board[i][j+2] + board[i + 1][j + 2] > bestScore) {
					bestScore = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
				}
			}
			//10
			if (i + 2 <= N - 1 && j + 1 <= M - 1) {
				if (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1];
				}
			}
			//11
			if (i + 1 <= N - 1 && j + 2 <= M - 1) {
				if (board[i][j] + board[i + 1][j] + board[i + 1][j+1] + board[i + 1][j + 2] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
				}
			}
			//12
			if (i + 2 <= N - 1 && j + 1 <= M - 1) {
				if (board[i][j] + board[i + 1][j] + board[i + 2][j+1] + board[i + 1][j + 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 2][j + 1] + board[i + 1][j + 1];
				}
			}
			//13
			if (i + 1 <= N - 1 && j + 2 <= M - 1) {
				if (board[i][j] + board[i][j+1] + board[i + 1][j+1] + board[i + 1][j + 2] > bestScore) {
					bestScore = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
				}
			}
			//14
			if (i + 2 <= N - 1 && j - 1 >=0) {
				if (board[i][j] + board[i + 1][j] + board[i+1][j-1] + board[i + 2][j - 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1];
				}
			}
			//15
			if (i + 1 <= N - 1 && j + 1 <= M - 1&&j-1>=0) {
				if (board[i][j] + board[i + 1][j] + board[i + 1][j-1] + board[i][j + 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i][j + 1];
				}
			}
			//16
			if (i + 1 <= N - 1 && j + 2 <= M - 1) {
				if (board[i][j] + board[i + 1][j+1] + board[i][j+1] + board[i][j + 2] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i][j + 2];
				}
			}
			//17
			if (i + 2 <= N - 1 && j + 1 <= M - 1) {
				if (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
				}
			}
			//18
			if (i + 2 <= N - 1 && j - 1 >= 0) {
				if (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1];
				}
			}
			//19
			if (i + 1 <= N - 1 && j + 1 <= M - 1&&j-1>=0) {
				if (board[i][j] + board[i + 1][j] + board[i + 1][j+1] + board[i + 1][j - 1] > bestScore) {
					bestScore = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j - 1];
				}
			}
		}
	}
	printf("%d\n", bestScore);
	free(board);
	return 0;
}