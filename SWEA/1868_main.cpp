#include<iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 300

int getMine(char p_aryMap[][MAX_SIZE], const int& p_iLine, int p_iX, int p_iY) {
	if (p_iX < 0 || p_iX >= p_iLine ||
		p_iY < 0 || p_iY >= p_iLine) {
		return 0;
	}

	return p_aryMap[p_iX][p_iY] == '*' ? 1 : 0;
};

int getMineCnt(char p_aryMap[][MAX_SIZE], const int& p_iLine, int p_iX, int p_iY) {
	int iMineCnt =
		getMine(p_aryMap, p_iLine, p_iX - 1, p_iY) +
		getMine(p_aryMap, p_iLine, p_iX - 1, p_iY + 1) +
		getMine(p_aryMap, p_iLine, p_iX, p_iY + 1) +
		getMine(p_aryMap, p_iLine, p_iX + 1, p_iY + 1) +
		getMine(p_aryMap, p_iLine, p_iX + 1, p_iY) +
		getMine(p_aryMap, p_iLine, p_iX + 1, p_iY - 1) +
		getMine(p_aryMap, p_iLine, p_iX, p_iY - 1) +
		getMine(p_aryMap, p_iLine, p_iX - 1, p_iY - 1);
	return iMineCnt;
};

bool insertQueue(queue <pair<int, int>>& pr_queue, char p_aryMap[][MAX_SIZE], bool p_aryCheck[][MAX_SIZE], const int& p_iLine, int p_iX, int p_iY, bool p_bCheckZero) {
	if (p_iX < 0 || p_iX >= p_iLine ||
		p_iY < 0 || p_iY >= p_iLine ||
		p_aryMap[p_iX][p_iY] == '*' ||
		p_aryCheck[p_iX][p_iY] == true) {
		return true;
	}

	if (!p_bCheckZero) {
		pr_queue.push(make_pair(p_iX, p_iY));
		return true;
	}

	if (getMineCnt(p_aryMap, p_iLine, p_iX, p_iY) != 0) {
		return true;
	}

	pr_queue.push(make_pair(p_iX, p_iY));
	return false;
}

int BFS(const vector<pair<int, int>> p_vecMap, char p_aryMap[][MAX_SIZE], const int& p_iLine) {
	int iResult = 0;
	bool aryCheck[MAX_SIZE][MAX_SIZE] = { false, };

	for (const auto& pos : p_vecMap) {
		// 해당 좌표를 방문한 적이 있으면 NEXT.
		if (aryCheck[pos.first][pos.second] == true) {
			continue;
		}

		iResult++;

		queue <pair<int, int>> queueMap;
		queueMap.push(make_pair(pos.first, pos.second));

		bool bIsFirst = true;
		while (!queueMap.empty()) {
			int iX = queueMap.front().first;
			int iY = queueMap.front().second;
			queueMap.pop();

			// 해당 좌표를 방문한 적이 있으면 NEXT.
			if (aryCheck[iX][iY] == true) {
				continue;
			}
			aryCheck[iX][iY] = true;

			if (p_aryMap[iX][iY] == '.') {
				p_aryMap[iX][iY] = getMineCnt(p_aryMap, p_iLine, iX, iY) + '0';
			}

			if (!bIsFirst && p_aryMap[iX][iY] != '0') {
				continue;
			}

			bool checkZero = bIsFirst && p_aryMap[iX][iY] != '0' ? true : false;
			bIsFirst = false;

			if (!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX - 1, iY, checkZero) ||
				!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX - 1, iY + 1, checkZero) ||
				!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX, iY + 1, checkZero) ||
				!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX + 1, iY + 1, checkZero) ||
				!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX + 1, iY, checkZero) ||
				!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX + 1, iY - 1, checkZero) ||
				!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX, iY - 1, checkZero) ||
				!insertQueue(queueMap, p_aryMap, aryCheck, p_iLine, iX - 1, iY - 1, checkZero))
			{
				continue;
			}
		}
	}

	return iResult;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int iLine = 0;
		cin >> iLine;

		vector <pair<int, int>> vecMap;
		char aryMap[MAX_SIZE][MAX_SIZE] = { 0, };
		for (int x = 0; x < iLine; x++) {
			cin >> aryMap[x];

			for (int y = 0; y < iLine; y++) {
				if (aryMap[x][y] == '.') {
					vecMap.push_back(make_pair(x, y));
				}
			}
		}

		cout << "#" << test_case << " " << BFS(vecMap, aryMap, iLine) << "\n";
	}
	return 0;
}