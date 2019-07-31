#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int dwarves[9];
bool checkDwarves[9];
int realDwarves[7];
int sum = 0;


void initCheckDwarves(int i, int j);
void findDwarvesSet();
int checkSum();

int main() {
	
	for (int i = 0; i < 9; i++) {
		scanf("%d", &dwarves[i]);
	}
	findDwarvesSet();
	sort(realDwarves, realDwarves + 7);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", realDwarves[i]);
	}
	return 0;
}
void findDwarvesSet() {
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			initCheckDwarves(i, j);
			if (checkSum() == 0) {
				return;
			}
			sum = 0;
		}
	}
}

void initCheckDwarves(int i, int j) {
	for (int k = 0; k < 9; k++) {
		if (k == i || k == j) checkDwarves[k] = false;
		else checkDwarves[k] = true;
	}
}

int checkSum() {
	int k = 0;
	for (int i = 0; i < 9; i++) {
		if (checkDwarves[i] == true) {
			sum += dwarves[i];
			realDwarves[k++] = dwarves[i];
		}
	}
	if (sum == 100) {
		return 0;
	}
	else return -1;
}