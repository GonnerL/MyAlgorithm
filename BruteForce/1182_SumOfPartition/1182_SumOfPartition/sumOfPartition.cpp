#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;
int modified = 0;
int N, S;
vector<int> numbers;
void findSum(vector<int>& permutation, int sum, int index,int modified);

int main() {
	cin >> N >> S;
	vector<int> permutation(N);
	for (int i = 0; i < N; i++) {
		cin >> permutation[i];
	}
	findSum(permutation, 0, 0,0);
	cout << num;
	return 0;
}

void findSum(vector<int> &permutation, int sum, int index, int modified) {
	if (sum == S&&numbers.size()!=0&&modified==1) {
		num++;
	}
	if (index >= N) return;
	numbers.push_back(permutation[index]);
	findSum(permutation, sum + permutation[index], index + 1,1);
	numbers.pop_back();
	findSum(permutation, sum, index + 1,0);
}