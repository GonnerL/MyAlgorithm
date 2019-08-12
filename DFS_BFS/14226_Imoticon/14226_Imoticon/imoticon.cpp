#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <queue>
using namespace std;

int S;
int display[1001][1001];

void findS();

int main() {
	memset(display, -1, sizeof(display));
	cin >> S;
	display[1][0] = 0;
	findS();
	return 0;
}

void findS() {
	queue<pair<int,int>> q;
	q.push(make_pair(1, 0));
	while (!q.empty()) {
		int imo = q.front().first;
		int clip = q.front().second;
		q.pop();
		if (display[imo][imo]==-1) {
			display[imo][imo] = display[imo][clip] + 1;
			q.push(make_pair(imo, imo));
		}
		if (clip != 0 && clip + imo <= S) {
			if(display[imo+clip][clip]==-1){
				display[imo + clip][clip] = display[imo][clip] + 1;
				q.push(make_pair(imo + clip, clip));

			}
		}
		if (imo - 1 >= 0) {
			if (display[imo - 1][clip] == -1) {
				display[imo - 1][clip] = display[imo][clip] + 1;
				q.push(make_pair(imo - 1, clip));
			}
		}
	}
	int answer = -1;
	for (int i = 1; i <= S; i++) {
		if (answer==-1||answer > display[S][i]) {
			answer = display[S][i];
		}
	}
	printf("%d\n", answer);
}