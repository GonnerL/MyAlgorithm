#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> vertex[20001];
int color[20001];

int K;

void solve(int node,int index);
bool isBinary(int v);

int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			vertex[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			int from, to;
			cin >> from >> to;
			vertex[from].push_back(to);
			vertex[to].push_back(from);
		}
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				solve(1,i);
			}
		}
		if (isBinary(V) == true) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}

void solve(int node, int index) {
	color[index] = node;
	for (int i = 0; i < vertex[index].size(); i++) {
		int y = vertex[index][i];
		if (color[y] == 0) {
			solve(3 - node, y);
		}
	}
}

bool isBinary(int v) {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < vertex[i].size(); j++) {
			if (color[vertex[i][j]] == color[i]) {
				return false;
			}
		}
	}
	return true;
}