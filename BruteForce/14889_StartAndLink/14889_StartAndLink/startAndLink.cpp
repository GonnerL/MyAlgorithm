#include <stdio.h>
#include <iostream>
#include <deque>
#include <math.h>
using namespace std;

int n;
int s[21][21];
int go(int index, deque<int> first, deque<int> second);
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	deque<int> first; 
	deque<int> second;
	printf("%d\n", go(1, first, second));

	return 0;
}

int go(int index, deque<int> first, deque<int> second) {
	if (index == n + 1) {
		if (first.size() > n / 2 || second.size() > n / 2) return -1;
		int t1 = 0; int t2 = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i != j) {
					t1 += s[first[i]][first[j]];
					t2 += s[second[i]][second[j]];
				}
			}
		}
		int diff = abs(t1 - t2);
		return diff;
	}
	int ans = -1;
	if (first.size() > n / 2 || second.size() > n / 2) return -1;
	first.push_back(index);
	int t1 = go(index + 1, first, second);
	if (ans == -1 || (t1!=-1&&t1 < ans)) {
		ans = t1;
	}
	first.pop_back();
	second.push_back(index);
	int t2 = go(index + 1, first, second);
	if (ans == -1 || (t2 != -1 && t2 < ans)) {
		ans = t2;
	}
	second.pop_back();
	return ans;
}