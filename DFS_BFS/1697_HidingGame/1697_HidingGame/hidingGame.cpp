#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100001

int board[MAX_SIZE];
int N, K;
void bfs();

int main() {
	fill(board, board + MAX_SIZE, 100001);
	cin >> N >> K;
	board[N] = 1;
	bfs();
	printf("%d\n", board[K]-1);
	return 0;
}

void bfs() {
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int curP = q.front();
		q.pop();
		if (curP * 2 < MAX_SIZE) {
			if (board[curP * 2] > board[curP]+1) {
				board[curP * 2] = board[curP] + 1;
				q.push(curP * 2);
				if (q.back() == K) return;
			}
		}
		if (curP + 1 < MAX_SIZE) {
			if (board[curP+1]>board[curP]+1) {
				board[curP + 1] = board[curP] + 1;
				q.push(curP + 1);
				if (q.back() == K) return;
			}
		}
		if (curP - 1 >= 0) {
			if (board[curP-1]>board[curP]+1) {
				board[curP - 1] = board[curP] + 1;
				q.push(curP - 1);
				if (q.back() == K) return;
			}
		}
	}
}