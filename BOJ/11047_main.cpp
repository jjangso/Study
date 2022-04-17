#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int iCount = 0;
	int iTotal = 0;
	cin >> iCount >> iTotal;

	vector<int> vecCoin(iCount);
	for (int i = (iCount - 1); i >= 0; i--) {
		cin >> vecCoin[i];
	}

	int iResult = 0;
	for (int i = 0; i < iCount; i++) {
		if (iTotal < vecCoin[i]) {
			continue;
		}

		int iDiv = iTotal / vecCoin[i];
		if (iDiv > 0) {
			iTotal -= (iDiv * vecCoin[i]);
			iResult += iDiv;
		}
	}
	cout << iResult << endl;
	return 0;
}