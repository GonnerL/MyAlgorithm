#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int N, M;
int miro[100][100];
int dist[100][100];
deque<pair<int,int>> q;

void bfs();

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &miro[i][j]);
			dist[i][j] = -1;
		}
	}
	bfs();
	printf("%d\n", dist[N-1][M-1]);
	return 0;
}

void bfs() {
	dist[0][0] = 0;
	q.push_back(make_pair(0, 0));
	while (!q.empty()) {
		int currentX = q.front().second;
		int currentY = q.front().first;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nextX = currentX + dx[i];
			int nextY = currentY + dy[i];
			if (nextX >= M || nextX < 0 || nextY>=N || nextY < 0) continue;
			if (dist[nextY][nextX] == -1) {
				if (miro[nextY][nextX] == 0) {
					dist[nextY][nextX] = dist[currentY][currentX];
					q.push_front(make_pair(nextY, nextX));
				}
				else if (miro[nextY][nextX] == 1) {
					dist[nextY][nextX] = dist[currentY][currentX] + 1;
					q.push_back(make_pair(nextY, nextX));
				}
			}
		}
	}
}