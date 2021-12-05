#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortByData(pair <int, int> p_Pair1, pair <int, int> p_Pair2) {
	return p_Pair1.first < p_Pair2.first;
};

int main() {

	int iCount = 0;
	cin >> iCount;

	vector <int> vecNum(iCount, 0);
	for (int i = 0; i < iCount; i++) {
		int iNum = 0;
		cin >> iNum;

		vecNum[i] = iNum;
	}

	int iCntInput = 0;
	cin >> iCntInput;

	vector <pair<int, int>> vecPair(iCntInput);
	for (int i = 0; i < iCntInput; i++) {
		int iData = 0;
		cin >> iData;

		vecPair[i] = make_pair(iData, i);
	}

	sort(vecNum.begin(), vecNum.end());
	sort(vecPair.begin(), vecPair.end(), sortByData);

	int iCntNum = 0;
	vector <int> vecResult(iCntInput, 0);
	for (int iCntPair = 0; iCntPair < iCntInput;) {
		if (iCntNum >= iCount) {
			break;
		}

		if (vecPair[iCntPair].first == vecNum[iCntNum]) {
			vecResult[vecPair[iCntPair].second] = 1;
			iCntPair++;
			continue;
		}

		if (vecPair[iCntPair].first < vecNum[iCntNum]) {
			iCntPair++;
			continue;
		}

		if (vecPair[iCntPair].first > vecNum[iCntNum]) {
			iCntNum++;
		}
	}

	for (const auto& result : vecResult) {
		cout << result << "\n";
	}
	return 0;
}