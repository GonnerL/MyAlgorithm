#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

vector<char> password;
void solve(vector<char>& strings, int index, int selected);
bool check();

int L, C;

int main() {
	scanf("%d %d", &L, &C);
	vector<char> strings(C);
	for (int i = 0; i < C; i++) {
		cin >> strings[i];
	}
	sort(strings.begin(),strings.end());
	solve(strings, 0, 0);
	return 0;
}

void solve(vector<char> &strings, int index, int selected) {
	if (selected == L&&check()==true) {
		for (int passwords : password) {
			printf("%c", passwords);
		}
		cout << "\n";
		return;
	}
	if (index >= C) return;

	password.push_back(strings[index]);
	solve(strings, index + 1, selected + 1);
	password.pop_back();
	solve(strings, index + 1, selected);
}

bool check(){
	int za = 0;
	int mo = 0;
	for (int i = 0; i < L; i++) {
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' ||
			password[i] == 'o' || password[i] == 'u') mo++;
		else za++;
	}
	if (za >= 2 && mo >= 1) return true;
	else return false;
}