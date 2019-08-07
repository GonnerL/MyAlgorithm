#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, V;
bool check[1001];
vector<int> numbers[1001];
void bfs(int x);
void dfs(int x);

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		numbers[from].push_back(to);
		numbers[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		sort(numbers[i].begin(), numbers[i].end());
	}
	dfs(V);
	cout << '\n';
	bfs(V);
	cout << '\n';
	return 0;
}

void dfs(int x) {
	check[x] = true;
	printf("%d ", x);
	for (int i = 0; i < numbers[x].size(); i++) {
		int y = numbers[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		printf("%d ", y);
		for (int i = 0; i < numbers[y].size(); i++) {
			int next = numbers[y][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}