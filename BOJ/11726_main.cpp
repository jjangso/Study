#include <iostream>
#include <vector>

using namespace std;

int main() {
	int iCount = 0;
	cin >> iCount;
	vector<long long> vecResult = { 1, 2 };

	if (iCount > 2) {
		for (int i = 2; i < iCount; i++) {
			long long llNum = (vecResult[i - 2] + vecResult[i - 1]) % 10007;
			vecResult.push_back(llNum);
		}
	}

	cout << vecResult[iCount - 1] << "\n";
	return 0;
}