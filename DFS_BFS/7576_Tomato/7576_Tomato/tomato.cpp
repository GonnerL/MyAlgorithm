#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int N, M;
int day = 0;
int zero = 0;

int storage[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<pair<int, int>> nextQ;
queue<pair<int, int>> startQ;
void bfs();

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> storage[i][j];
			if (storage[i][j] == 1) {
				startQ.push(make_pair(i, j));
			}
			else if (storage[i][j] == 0) zero++;
		}
	}
	if (startQ.size() == 0) {
		printf("-1\n");
		return 0;
	}
	if (zero == 0) {
		printf("0\n");
		return 0;
	}
	bfs();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (storage[i][j] == 0) day = -1;
		}
	}
	printf("%d\n", day);
	return 0;
}

void bfs() {
	while (!startQ.empty()) {
		int curX = startQ.front().second;
		int curY = startQ.front().first;
		startQ.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextY<0 || nextX<0 || nextX>N - 1 || nextY>M - 1) continue;
			if (storage[nextY][nextX] == 0) {
				storage[nextY][nextX] = 1;
				nextQ.push(make_pair(nextY, nextX));
			}
		}
	}
	if (nextQ.size() != 0) {
		day++;
		nextQ.swap(startQ);
		bfs();
	}
}