#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>
#pragma warning(disable:4996)
using namespace std;

int r, c;
char forest[51][51];
char message[] = "KAKTUS";
int dist[51][51];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };
int destY, destX;
queue<pair<int, int>> q;
deque<pair<int, int>> water;

void inputCondition();
void bfsWater();
void bfsBiber();

int main() {
	inputCondition();
	bfsWater();
	bfsBiber();
	if (dist[destY][destX] == 1000) printf("%s\n", message);
	else printf("%d\n", dist[destY][destX]);
	return 0;
}

void inputCondition() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> forest[i][j];
			dist[i][j] = 1000;
			if (forest[i][j] == 'S') {
				dist[i][j] = 0;
				q.push(make_pair(i, j));
			}
			else if (forest[i][j] == 'D') {
				destY = i; destX = j;
			}
			else if (forest[i][j] == '*') {
				water.push_front(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
}

void bfsWater() {
	while (!water.empty()) {
		int waterY = water.front().first;
		int waterX = water.front().second;
		water.pop_front();
		for (int i = 0; i < 4; i++) {
			int nextY = waterY + dy[i];
			int nextX = waterX + dx[i];
			if (nextY<1 || nextY>r || nextX<1 || nextX>c) continue;
			char target = forest[nextY][nextX];
			if (dist[nextY][nextX] > dist[waterY][waterX]+1 && target=='.') {
				dist[nextY][nextX] = dist[waterY][waterX] + 1;
				water.push_back(make_pair(nextY, nextX));
			}
		}
	}
}

void bfsBiber() {
	while (!q.empty()) {
		int currentY = q.front().first;
		int currentX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];
			if (nextY<1 || nextX<1 || nextY>r || nextX>c) continue;
			char target = forest[nextY][nextX];
			if (dist[currentY][currentX] + 1 < dist[nextY][nextX] && (target == '.'||target=='D')) {
				dist[nextY][nextX]=dist[currentY][currentX]+1;
				q.push(make_pair(nextY, nextX));
			}
		}
	}
}