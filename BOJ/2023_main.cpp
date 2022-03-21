#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int iCount = 0;
	cin >> iCount;

	vector<int> vecNum = { 1, 3, 5, 7, 9 };
	vector<int> vecResult = { 2, 3, 5, 7 };
	for (int i = 0; i < iCount; i++) {
		queue<int> queueNum;
		if (i == 0) {
			for (const auto& result : vecResult) {
				queueNum.push(result);
			}
		}
		else {
			for (const auto& result : vecResult) {
				for (const auto& num : vecNum) {
					int iNum = (result * 10) + num;
					queueNum.push(iNum);
				}
			}
		}

		vecResult.clear();
		while (!queueNum.empty()) {
			int iNum = queueNum.front();
			queueNum.pop();

			int iSqrt = sqrt(iNum);
			bool bFind = false;
			for (int j = 3; j <= iSqrt; j++) {
				if (iNum % j == 0) {
					bFind = true;
					break;
				}
			}

			if (!bFind) {
				vecResult.push_back(iNum);
			}
		}
	}

	for (const auto& num : vecResult) {
		cout << num << "\n";
	}

	return 0;
}