#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<long long>> vecResult(n, vector<long long>(m, 0));
	for (const auto& pos : puddles) {
		vecResult[pos[1] - 1][pos[0] - 1] = -1;
	}
	vecResult[0][0] = 1;

	for (int iY = 0; iY < n; iY++) {
		for (int iX = 0; iX < m; iX++) {
			if (iX == 0 && iY == 0) {
				continue;
			}

			if (vecResult[iY][iX] == -1) {
				continue;
			}

			long long iResult = 0;
			if (iX > 0 && vecResult[iY][iX - 1] != -1) {
				iResult += vecResult[iY][iX - 1];
			}
			if (iY > 0 && vecResult[iY - 1][iX] != -1) {
				iResult += vecResult[iY - 1][iX];
			}

			vecResult[iY][iX] = iResult % (1000000007);
		}
	}
	return vecResult[n - 1][m - 1];
}