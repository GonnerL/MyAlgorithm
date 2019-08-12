#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define MAX_SIZE 100001

int N, K;
int dist[100001];
queue<int> currentQ;
queue<int> nextQ;

void bfs();

int main() {
	memset(dist, -1, sizeof(dist));
	cin >> N >> K;
	bfs();
	printf("%d\n", dist[K]);
	return 0;
}

void bfs() {
	dist[N] = 0;
	currentQ.push(N);
	while (!currentQ.empty()) {
		int current = currentQ.front();
		currentQ.pop();
		if (current * 2 < K*2&&current*2<MAX_SIZE) {
			if (dist[current * 2] == -1) {
				currentQ.push(current * 2);
				dist[current * 2] = dist[current];
				//printf("push : %d, distance : %d\n", current * 2, dist[current * 2]);
				if (current * 2 == K) return;
			}
		}
		if (current +1<MAX_SIZE) {
			if (dist[current +1]==-1) {
				nextQ.push(current + 1);
				dist[current + 1] = dist[current] + 1;
				//printf("push : %d, distance : %d\n", current +1, dist[current +1]);
				if (current +1 == K) return;
			}
		}
		if (current - 1 >= 0) {
			if (dist[current - 1] == -1) {
				nextQ.push(current - 1);
				dist[current - 1] = dist[current] + 1;
				//printf("push : %d, distance : %d\n", current -1, dist[current -1]);
				if (current -1 == K) return;
			}
		}
		if (currentQ.empty()) {
			//printf("%d\n", nextQ.front());
			currentQ.swap(nextQ);
		}
	}
}