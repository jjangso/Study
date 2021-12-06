#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int search(const vector<int>& p_vecTree, const double& p_dLen, int p_iStart, int p_iEnd) {
	if (p_iStart == p_iEnd) {
		return p_iStart;
	}

	int iMid = (p_iStart + 1 == p_iEnd) ? p_iEnd : (p_iStart + p_iEnd) / 2;
	double iTotal = 0;
	for (const auto& tree : p_vecTree) {
		if (tree <= iMid) {
			break;
		}

		iTotal += (tree - iMid);

		if (iTotal >= p_dLen) {
			break;
		}
	}

	return iTotal < p_dLen ? search(p_vecTree, p_dLen, p_iStart, (iMid - 1)) : search(p_vecTree, p_dLen, iMid, p_iEnd);
};

int main() {
	int iCount = 0;
	double dLen = 0;
	cin >> iCount;
	cin >> dLen;

	int iSum = 0;
	vector <int> vecTree;
	for (int i = 0; i < iCount; i++) {
		int iTree = 0;
		cin >> iTree;

		if (iTree != 0) {
			iSum += iTree;
			vecTree.push_back(iTree);
		}
	}

	sort(vecTree.begin(), vecTree.end(), greater<int>());

	int iResult = 0;
	if (iSum != dLen) {
		iResult = search(vecTree, dLen, 0, vecTree[0]);
	}

	cout << iResult << "\n";

	return 0;
}