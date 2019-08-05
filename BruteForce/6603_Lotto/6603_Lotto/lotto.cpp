#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int> lotto;
void findLottos(vector<int>& Lottos, int index, int selected);

int k;

int main() {
	do{
		cin >> k;
		vector<int> possibleLottos(k);
		for (int i = 0; i < k; i++) {
			cin >> possibleLottos[i];
		}
		findLottos(possibleLottos, 0, 0);
		cout << "\n";
	}while (k != 0);
	return 0;
}

void findLottos(vector<int>& Lottos, int index, int selected) {
	if (selected == 6) {
		for (int lottoNum : lotto) {
			printf("%d ", lottoNum);
		}
		cout << "\n";
		return;
	}
	int n = Lottos.size();
	if (index >=n) return;

	lotto.push_back(Lottos[index]);
	findLottos(Lottos, index + 1, selected + 1);
	lotto.pop_back();
	findLottos(Lottos, index + 1, selected);
}