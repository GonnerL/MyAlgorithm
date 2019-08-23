#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int n;
long long solve(int x);

int main() {
	cin >> n;
	int i = 1;
	while (true) {
		if (n < pow(10,i)) {
			printf("%lld\n", solve(i));
			return 0;
		}
		i++;
	}
	return 0;
}

long long solve(int x) {
	long long answer = 0;
	if (x == 1) return n;
	else answer += 9;
	for (int i = 2; i <= x-1; i++) {
		answer += (long long)((9 * pow(10, i-1))*i);
	}
	answer += (long long)(x * (n - pow(10, x - 1)+1));
	return answer;
}