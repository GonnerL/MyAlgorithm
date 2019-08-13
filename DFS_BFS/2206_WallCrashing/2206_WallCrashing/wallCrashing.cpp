#include <iostream>
#include <stdio.h>
#include <queue>
#include <tuple>
#pragma warning(disable:4996)
#define MAX_ROUTE 100002
using namespace std;

int N, M,answer;
int map[1001][1001];
int dist[1001][1001][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<tuple<int, int, int>> q;
void bfs();

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
		}
	}
	bfs();
	printf("%d\n", answer);
	return 0;
}

void bfs() {
	dist[1][1][0] = 1;
	q.push(make_tuple(1,1,0));
	while (!q.empty()) {
		int currentX, currentY, currentWall;
		tie(currentY, currentX, currentWall) = q.front(); 
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = currentX + dx[i];
			int nextY = currentY + dy[i];
			if (nextX<1 || nextX>M || nextY<1 || nextY>N) continue;
			if (map[nextY][nextX] == 1&&currentWall==0 && dist[nextY][nextX][currentWall]==-1) {
				dist[nextY][nextX][1] = dist[currentY][currentX][currentWall] + 1;
				q.push(make_tuple(nextY, nextX, 1));
			}
			if(map[nextY][nextX]==0&& currentWall == 0&& dist[nextY][nextX][currentWall] == -1){
				dist[nextY][nextX][currentWall] = dist[currentY][currentX][currentWall] + 1;
				q.push(make_tuple(nextY, nextX, currentWall));
			}
			if (map[nextY][nextX] == 0 && currentWall==1 && dist[nextY][nextX][currentWall] == -1) {
				dist[nextY][nextX][1] = dist[currentY][currentX][1] + 1;
				q.push(make_tuple(nextY, nextX, currentWall));
			}
			if (nextY == N && nextX == M) break;
		}
	}
	if (dist[N][M][0] == -1 && dist[N][M][1] == -1) answer = -1;
	else {
		if (dist[N][M][0] != -1 && dist[N][M][1] != -1) {
			if (dist[N][M][0] > dist[N][M][1]) answer = dist[N][M][1];
			else answer = dist[N][M][0];
		}
		else {
			if (dist[N][M][0] == -1) answer = dist[N][M][1];
			else answer = dist[N][M][0];
		}
	}
}
