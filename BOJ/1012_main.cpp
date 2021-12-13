#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 50

void insertQueue(queue <pair<int, int>>& pr_queue, int p_aryCabbage[][MAX_SIZE], bool p_aryCheck[][MAX_SIZE], const int& p_iWidth, const int& p_iHeight, int p_iX, int p_iY) {
	if (p_iX < 0 || p_iX >= p_iWidth ||
		p_iY < 0 || p_iY >= p_iHeight ||
		p_aryCabbage[p_iY][p_iX] == 0 ||
		p_aryCheck[p_iY][p_iX] == true) {
		return;
	}

	pr_queue.push(make_pair(p_iY, p_iX));
}

int BFS(const vector<pair<int, int>> p_vecCabbage, int p_aryCabbage[][MAX_SIZE], const int& p_iWidth, const int& p_iHeight) {
	int iResult = 0;
	bool aryCheck[MAX_SIZE][MAX_SIZE] = { false, };

	for (const auto& cabbage : p_vecCabbage) {
		// 해당 좌표를 방문한 적이 있으면 NEXT.
		if (aryCheck[cabbage.first][cabbage.second] == true) {
			continue;
		}

		iResult++;

		queue <pair<int, int>> queueCabbage;
		queueCabbage.push(make_pair(cabbage.first, cabbage.second));

		while (!queueCabbage.empty()) {
			int iY = queueCabbage.front().first;
			int iX = queueCabbage.front().second;
			queueCabbage.pop();

			// 해당 좌표를 방문한 적이 있으면 NEXT.
			if (aryCheck[iY][iX] == true) {
				continue;
			}

			aryCheck[iY][iX] = true;


			insertQueue(queueCabbage, p_aryCabbage, aryCheck, p_iWidth, p_iHeight, iX + 1, iY);
			insertQueue(queueCabbage, p_aryCabbage, aryCheck, p_iWidth, p_iHeight, iX, iY + 1);
			insertQueue(queueCabbage, p_aryCabbage, aryCheck, p_iWidth, p_iHeight, iX - 1, iY);
			insertQueue(queueCabbage, p_aryCabbage, aryCheck, p_iWidth, p_iHeight, iX, iY - 1);
		}
	}

	return iResult;
};

int main() {
	int iCount = 0;
	cin >> iCount;

	vector <int> vecResult;
	for (int i = 0; i < iCount; i++) {
		int iWidth = 0;
		int iHeight = 0;
		int iCntCabbage = 0;
		cin >> iWidth;
		cin >> iHeight;
		cin >> iCntCabbage;

		vector <pair<int, int>> vecCabbage;
		int aryCabbage[MAX_SIZE][MAX_SIZE] = { 0, };
		for (int j = 0; j < iCntCabbage; j++) {
			int iX = 0;
			int iY = 0;
			cin >> iX;
			cin >> iY;

			aryCabbage[iY][iX] = 1;
			vecCabbage.push_back(make_pair(iY, iX));
		}

		vecResult.push_back(BFS(vecCabbage, aryCabbage, iWidth, iHeight));
	}

	for (const auto& result : vecResult) {
		cout << result << "\n";
	}

	return 0;
}