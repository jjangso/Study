#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int search(const vector<int>& p_vecSnack, const int& p_iChild, int p_iStart, int p_iEnd) {
	if (p_iStart == p_iEnd) {
		return p_iStart;
	}

	int iMid = (p_iStart + 1 == p_iEnd) ? p_iEnd : (p_iStart + p_iEnd) / 2;
	int iCount = 0;
	for (const auto& snack : p_vecSnack) {
		if (snack < iMid) {
			// 가운데 값보다 과자의 길이가 짧으면.
			break;
		}

		iCount += (snack / iMid);

		if (iCount >= p_iChild) {
			break;
		}
	}

	return iCount < p_iChild ? search(p_vecSnack, p_iChild, p_iStart, (iMid - 1)) : search(p_vecSnack, p_iChild, iMid, p_iEnd);
};

int main() {
	int iChildCnt = 0;
	int iSnackCnt = 0;
	cin >> iChildCnt;
	cin >> iSnackCnt;

	int iSum = 0;
	vector <int> vecSnack;
	for (int i = 0; i < iSnackCnt; i++) {
		int iSnack = 0;
		cin >> iSnack;
		vecSnack.push_back(iSnack);

		iSum += iSnack;
	}

	sort(vecSnack.begin(), vecSnack.end(), greater<int>());

	int iResult = 0;
	if (iSum == iChildCnt) {
		iResult = 1;
	}
	else if (iSum > iChildCnt) {
		iResult = search(vecSnack, iChildCnt, 1, vecSnack[0]);
	}

	cout << iResult << "\n";
	return 0;
}