#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int n; int ans = 0;
bool check[4000001];
long long sum = 0;
vector<int> prime;

void findPrime();
void searchSum();

int main() {
	cin >> n;
	findPrime();
	if (n > 1) searchSum();

	printf("%d\n", ans);
	return 0;
}

void findPrime() {
	for (int i = 2; i<= n; i++) {
		if (check[i] == false) {
			int temp = i*2;
			while (temp <= n) {
				check[temp] = true;
				temp += i;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) prime.push_back(i);
	}
}

void searchSum() {
	int r = 0; int l = 0; sum = prime[0];
	while (r >= l && r<prime.size()) {
		if (sum == n) {
			ans++;
			if (r + 1 < prime.size()) sum += prime[++r];
			else return;
		}
		else if (sum< n) {
			if (r + 1 < prime.size()) sum += prime[++r];
			else return;
		}
		else {
			sum -= prime[l++];
		}
	}
}