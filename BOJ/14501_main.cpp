#include <iostream>
#include <vector>

using namespace std;

struct Consult {
	int iDays = 0;
	int iCost = 0;

	Consult(const int p_iDays, const int p_iCost) : iDays(p_iDays), iCost(p_iCost) {};
};

int main(int argc, char** argv)
{
	int iCount = 0;
	cin >> iCount;

	vector<Consult> vecDay;
	for (int i = 0; i < iCount; i++) {
		int iDays = 0; int iCost = 0;
		cin >> iDays >> iCost;

		vecDay.push_back(Consult(iDays, iCost));
	}

	int iResult = 0;
	vector<int> vecResult(iCount, 0);
	for (int i = (iCount - 1); i >= 0; i--) {
		int iNextDay = i + vecDay[i].iDays;
		if (iNextDay > iCount) {
			vecResult[i] = 0;
			continue;
		}

		int iMax = 0;
		for (int j = iNextDay; j < iCount; j++) {
			if (iMax < vecResult[j]) {
				iMax = vecResult[j];
			}
		}
		vecResult[i] = iMax + vecDay[i].iCost;

		if (iResult < vecResult[i]) {
			iResult = vecResult[i];
		}
	}

	cout << iResult << "\n";

	return 0;
}