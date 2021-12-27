#include <iostream>
#include <vector>

using namespace std;

int main() {
	int iHome = 0;
	cin >> iHome;

	vector<vector<int>> vecHome(iHome);
	for (int i = 0; i < iHome; i++) {
		vector<int> vecCost(3, 0);
		for (int j = 0; j < 3; j++) {
			int iCost = 0;
			cin >> iCost;

			vecCost[j] = iCost;
		}
		vecHome[i] = vecCost;
	}

	vector<pair<int, int>> vecCompare = { make_pair(1, 2), make_pair(0, 2), make_pair(0, 1) };
	int iResult = 0;
	for (int i = iHome - 2; i >= 0; i--) {
		int iNext = i + 1;
		for (int j = 0; j < vecCompare.size(); j++) {
			int iCost1 = vecHome[iNext][vecCompare[j].first];
			int iCost2 = vecHome[iNext][vecCompare[j].second];

			vecHome[i][j] += iCost1 <= iCost2 ? iCost1 : iCost2;

			if (i == 0) {
				if (j == 0) {
					iResult = vecHome[i][j];
				}
				else {
					iResult = iResult <= vecHome[i][j] ? iResult : vecHome[i][j];
				}
			}
		}
	}

	cout << iResult << "\n";
	return 0;
}