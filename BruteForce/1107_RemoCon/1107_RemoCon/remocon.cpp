#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int n, m;
bool broken[10];
int possible(int c);


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int brokenNum;
		cin >> brokenNum;
		broken[brokenNum] = true;
	}
	int answer = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		int len = possible(i);
		if (len > 0) {
			int press = abs(n - i);
			if (press + len < answer) {
				answer = press + len;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}

int possible(int c) {
	if (c == 0) {
		if (broken[c] == true) return 0;
		else return 1;
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10] == true) return 0;
		c /= 10;
		len++;
	}
	return len;
}