#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> current;
int N;
int maxProfit = 0;
void getMaxProfit(vector<int>& t, vector<int>& p, int sum, int index);

int main() {
	cin >> N;
	vector<int> t(N);
	vector<int> p(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> p[i];
	}
	getMaxProfit(t, p, 0, 0);
	cout << maxProfit;
	return 0;
}

void getMaxProfit(vector<int> &t, vector<int> &p,int sum, int index) {
	if (index > N) return;
	if (sum > maxProfit) {
		maxProfit = sum;
	}
	if (index >= N) return;

	
	
	
	getMaxProfit(t, p, sum + p[index], index + t[index]);
	getMaxProfit(t, p, sum, index + 1);
}