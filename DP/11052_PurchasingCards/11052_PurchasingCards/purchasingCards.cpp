#include <stdio.h>
#include <iostream>
using namespace std;

int n;
int price[10001];

void solve();

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
	}
	solve();
	printf("%d\n", price[n]);
	return 0;
}

void solve() {
	price[0] = 0; 
	for (int i = 2; i <= n; i++) {
		int front = i - 1; int rear = 1;
		while (front >= rear) {
			if (price[front] + price[rear] > price[i]) {
				price[i] = price[front] + price[rear];
			}
			front--; rear++;
		}
	}
}