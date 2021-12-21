#include<iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Path {
	int iDest = 0;
	int iLevel = 0;

	Path(int p_iDest, int p_iLevel) {
		this->iLevel = p_iLevel;
		this->iDest = p_iDest;
	}

	bool operator < (const Path& p_path) const {
		return this->iLevel > p_path.iLevel;
	}
};

int getPrime(const int& p_iNum) {
	int iResult = p_iNum;
	while (true) {
		if (iResult == 2 || iResult == 3) {
			break;
		}

		if (iResult > 3) {
			int iSqrt = sqrt(iResult);
			bool bFind = false;
			for (int i = 2; i <= iSqrt; i++) {
				if (iResult % i == 0) {
					bFind = true;
					break;
				}
			}

			if (!bFind) {
				break;
			}
		}
		iResult++;
	}
	return iResult;
};

int Dijkstra(const vector<vector<Path>>& p_vecPath, const int& p_iGym) {
	vector<int> vecResult(p_iGym);

	//  초기화.
	for (int i = 0; i < p_iGym; i++) {
		vecResult[i] = -1;
	}

	priority_queue <Path> queue;
	queue.push(Path(0, 0));

	while (!queue.empty()) {
		Path path = queue.top();
		queue.pop();

		if (vecResult[path.iDest] != -1 &&			// 목적지까지의 최소 레벨이 -1 이 아니고,
			vecResult[path.iDest] <= path.iLevel) {	// 큐에 있던 Path 의 레벨보다 같거나 크면.
			continue;
		}

		vecResult[path.iDest] = path.iLevel;

		for (const auto& vecPath : p_vecPath[path.iDest]) {
			int iLevel = (path.iLevel >= vecPath.iLevel) ? path.iLevel : vecPath.iLevel;
			queue.push(Path(vecPath.iDest, iLevel));
		}
	}

	return vecResult[p_iGym - 1];
}

int main(int argc, char** argv)
{
	int iGym = 0;
	int iPath = 0;
	cin >> iGym >> iPath;

	vector<vector<Path>> vecPath(iPath);
	for (int i = 0; i < iPath; i++) {
		int iSrc = 0;
		int iDest = 0;
		int iLevel = 0;
		cin >> iSrc >> iDest >> iLevel;

		vecPath[iSrc - 1].push_back(Path(iDest - 1, iLevel + 1));
		vecPath[iDest - 1].push_back(Path(iSrc - 1, iLevel + 1));
	}

	int iResult = Dijkstra(vecPath, iGym);
	cout << getPrime(iResult) << "\n";

	return 0;
}