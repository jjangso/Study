#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	vector<int> vecDwarf(9);
	for (int i = 0; i < 9; i++) {
		cin >> vecDwarf[i];
	}
	sort(vecDwarf.begin(), vecDwarf.end());

	vector<int> vecResult(7);
	do {
		int iSum = 0;
		for (int i = 6; i >=0 ; i--) {
			iSum += vecDwarf[i];
			vecResult[i] = vecDwarf[i];
		
			if (iSum > 100) {
				break;
			}
		}

		if (iSum == 100) {
			break;
		}

	} while (next_permutation(vecDwarf.begin(), vecDwarf.end()));

	for (const auto& height : vecResult) {
		cout << height << endl;
	}

	return 0;
}