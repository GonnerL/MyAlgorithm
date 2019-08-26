#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;
int ans = 0;
int a[30001];
void search();

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	search();
	printf("%d\n", ans);
	return 0;
}

void search() {
	int l, r,sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= m) {
			l = i;
			r = l; 
			break;
		}
	}
	sum = a[r];
	while (r < n && r >= l) {
		if (sum== m) {
			ans++;
			sum += a[++r];
		}
		else if (sum> m) {
			sum -= a[l++];
		}
		else if (sum< m) {
			sum += a[++r];
		}
	}
}