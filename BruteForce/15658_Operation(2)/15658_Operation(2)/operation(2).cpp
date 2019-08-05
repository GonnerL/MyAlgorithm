#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int N;
vector<pair<int, int>> record;

void searchCases(vector<int> operators, vector<int> operands, int index, int result);
vector<pair<int, int>> findMaxMin();

int main() {
	cin >> N;
	vector<int> operands(N);
	vector<int> operators(4);
	for (int i = 0; i < N; i++) {
		cin >> operands[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	searchCases(operators, operands, 1, operands[0]);
	vector<pair<int, int>> answer = findMaxMin();
	printf("%d\n", answer[0].first);
	printf("%d\n", answer[0].second);

	
	return 0;
	
}

void searchCases(vector<int> operators, vector<int> operands, int index, int result) {
	if (index>=N) {
		record.push_back(make_pair(result, result));
		return;
	}
	if (operators[0] > 0) {
		operators[0]--;
		searchCases(operators, operands, index + 1, result+operands[index]);
		operators[0]++;
	}
	if (operators[1] > 0) {
		operators[1]--;
		searchCases(operators, operands, index + 1, result - operands[index]);
		operators[1]++;
	}
	if (operators[2] > 0) {
		operators[2]--;
		searchCases(operators, operands, index + 1, result * operands[index]);
		operators[2]++;
	}
	if (operators[3] > 0) {
		operators[3]--;
		searchCases(operators, operands, index + 1, result / operands[index]);
		operators[3]++;
	}
	
}

vector<pair<int, int>> findMaxMin() {
	vector<pair<int, int>> temp;
	int max = record[0].first;
	int min = record[0].second;
	int size = record.size();
	for (int i = 1; i < size; i++) {
		if (record[i].first > max) {
			max = record[i].first;
		}
		if (record[i].second < min) {
			min = record[i].second;
		}
	}
	temp.push_back(make_pair(max, min));

	return temp;
}