#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int N, M;
int components = 0;
vector<int> points[1001];
bool check[1001];

void findComponents(int start);

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		points[from].push_back(to);
		points[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			findComponents(i);
			components++;
		}
	}
	cout << components;
	return 0;
}

void findComponents(int start) {
	check[start] = true;
	for (int i = 0; i < points[start].size(); i++) {
		int y = points[start][i];
		if (check[y] == false) {
			findComponents(y);
		}
	}
}