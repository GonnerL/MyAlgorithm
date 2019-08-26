#include <stdio.h>
#include <iostream>
using namespace std;

int n, s;
int a[100001];
int ans = 0;
long long sum = 0;
void search();

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	search();
	printf("%d\n", ans);
	return 0;
}

void search() {
	int r = 0; int l = 0; int cnt = 1;
	sum += a[r];
	while (r < n && r >= l) {
		if (sum >= s) {
			if (cnt < ans || ans == 0) {
				ans = cnt;
			}
			sum -= a[l++];
			cnt--;
		}
		else if (sum < s) {
			sum += a[++r];
			cnt++;
		}
	}
}