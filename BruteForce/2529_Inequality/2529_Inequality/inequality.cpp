#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
bool firstCheck;
bool check[10];
vector<char> symbol;
vector<string> answer;
void search(int index, string number);
bool checkValid(char a, char b, char comparer);

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		char sym; cin >> sym;
		symbol.push_back(sym);
	}
	string number;
	search(0, number);
	cout << answer.front() << '\n' << answer.back();
	return 0;
}

void search(int index, string number) {
	if (index == k+1) {
		answer.push_back(number);
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if (index==0||checkValid(number[index-1],i+'0',symbol[index-1])) {
			if (check[i]==false) {
				check[i] = true;
				search(index + 1, number + to_string(i));
				check[i] = false;
			}
		}
	}
}

bool checkValid(char a, char b, char comparer) {
	if (a == b) return false;
	if (comparer == '>') {
		if (a < b) return false;
	}
	else {
		if (a > b) return false;
	}
	return true;
}