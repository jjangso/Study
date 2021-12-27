#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int iCost = 0;
	cin >> iCost;

	int iResult = -1;
	int iDiv = iCost / 5;
	for (int i = iDiv; i >= 0; i--) {
		int iSub = iCost - (i * 5);
		if (iSub % 2 == 0) {
			iResult = i + (iSub / 2);
			break;
		}
	}

	cout << iResult << "\n";

	return 0;
}