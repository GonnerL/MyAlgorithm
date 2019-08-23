#include <stdio.h>
#include <iostream>
using namespace std;

int t, m, n, x, y;
int lastYear;
void searchNum();

int main() {
	cin >> t;
	while (t > 0) {
		cin >> m >> n >> x >> y;
		searchNum();
		t--;
	}
	return 0;
}

void searchNum() {
	int i = 0;
	while (true){
		int target = m + i * m;
		if (target % n == 0) {
			lastYear = target;
			break;
		}
		i++;
	}
	i = 0; int answer=-1;
	while (true) {
		int target = x + i * m;
		if (target > lastYear) break;
		if (target % n == y || (target%n==0&&y==n)) {
			answer = target;
			break;
		}
		i++;
	}
	printf("%d\n", answer);
}