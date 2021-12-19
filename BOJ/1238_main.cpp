#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 1000

struct Path {
	int iTime = 0;
	int iDest = 0;

	Path(int p_iTime, int p_iDest) {
		this->iTime = p_iTime;
		this->iDest = p_iDest;
	}

	bool operator < (const Path p_path) const {
		return this->iTime > p_path.iTime;
	}
};

void Dijkstra(const vector<vector<Path>>& p_vecPath, vector<int>& pr_vecResult, int p_iStart) {
	pr_vecResult = vector<int>(p_vecPath.size());

	//  초기화.
	for (int i = 0; i < p_vecPath.size(); i++) {
		pr_vecResult[i] = -1;
	}

	priority_queue <Path> queue;
	queue.push(Path(0, p_iStart));

	while (!queue.empty()) {
		Path path = queue.top();
		queue.pop();

		if (pr_vecResult[path.iDest] != -1 &&			// 목적지까지의 최소 시간이 -1 이 아니고,
			pr_vecResult[path.iDest] <= path.iTime) {	// 큐에 있던 Path 의 시간보다 같거나 크면.
			continue;
		}

		pr_vecResult[path.iDest] = path.iTime;

		for (const auto& vecPath : p_vecPath[path.iDest]) {
			int iTime = path.iTime + vecPath.iTime;
			queue.push(Path(iTime, vecPath.iDest));
		}
	}
}

int main() {
	int iTown = 0;
	int iPath = 0;
	int iDest = 0;
	cin >> iTown >> iPath >> iDest;

	vector<vector<Path>> vecPath(iTown + 1);
	for (int i = 0; i < iPath; i++) {
		int iSrc = 0;
		int iDest = 0;
		int iTime = 0;
		cin >> iSrc >> iDest >> iTime;

		vecPath[iSrc].push_back(Path(iTime, iDest));
	}

	vector<vector<int>> vecResult(iTown + 1);
	for (int i = 1; i <= iTown; i++) {
		Dijkstra(vecPath, vecResult[i], i);
	}

	int iResult = 0;
	for (int i = 1; i <= iTown; i++) {
		if (i == iDest) {
			continue;
		}

		int iTotal = vecResult[i][iDest] + vecResult[iDest][i];
		if (iTotal > iResult) {
			iResult = iTotal;
		}
	}

	cout << iResult << "\n";

	return 0;
}