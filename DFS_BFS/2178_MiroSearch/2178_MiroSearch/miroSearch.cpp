#include <stdio.h>
#include <queue>
#include <iostream>
#include <memory.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int board[100][100] = { 0, };
int dist[100][100] = { -1, };
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 }; //아래로,위로,오른쪽,왼쪽
int N, M;


void bfs();

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	memset(dist, -1, sizeof(dist));
	bfs();
	printf("%d\n", dist[N-1][M-1]);
	return 0;
}

void bfs() {
	int curX = 0, curY = 0;
	dist[curY][curX] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(curY, curX));
	while (!q.empty()) {
		curX = q.front().second;
		curY = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx<0 || nx>M - 1 || ny<0 || ny> N - 1) continue;
			if (dist[ny][nx] == -1 && board[ny][nx] == 1) {
				dist[ny][nx] = dist[curY][curX] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}