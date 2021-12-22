#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int iRupee = 0;
	int iX = 0;
	int iY = 0;

	Pos(const int& p_iRupee, const int& p_iX, const int& p_iY) {
		this->iRupee = p_iRupee;
		this->iX = p_iX;
		this->iY = p_iY;
	}

	bool operator < (const Pos& p_path) const {
		return this->iRupee > p_path.iRupee;
	}
};

struct Move {
	int iX = 0;
	int iY = 0;

	Move(int p_iX, int p_iY) {
		this->iX = p_iX;
		this->iY = p_iY;
	}
};

int Dijkstra(const vector<vector<int>>& p_vecRupee, const int& p_iSize) {
	vector<Move> vecMove = { Move(-1, 0), Move(0, 1), Move(1, 0), Move(0, -1) };
	vector<vector<int>> vecResult(p_iSize);
	for (int i = 0; i < p_iSize; i++) {
		vector<int> vec(p_iSize, -1);
		vecResult[i] = vec;
	}

	priority_queue <Pos> queue;
	queue.push(Pos(p_vecRupee[0][0], 0, 0));

	while (!queue.empty()) {
		Pos pos = queue.top();
		queue.pop();

		if (vecResult[pos.iX][pos.iY] != -1 &&			// 목적지까지의 최소 Rupee 가 -1 이 아니고,
			vecResult[pos.iX][pos.iY] <= pos.iRupee) {	// 큐에 있던 Pos 의 Rupee 보다 같거나 크면.
			continue;
		}

		vecResult[pos.iX][pos.iY] = pos.iRupee;

		for (const auto& move : vecMove) {
			int iX = pos.iX + move.iX;
			int iY = pos.iY + move.iY;

			if (iX < 0 || iX >= p_iSize ||
				iY < 0 || iY >= p_iSize) {
				continue;
			}

			int iRupee = pos.iRupee + p_vecRupee[iX][iY];
			queue.push(Pos(iRupee, iX, iY));
		}
	}

	return vecResult[p_iSize - 1][p_iSize - 1];
}

int main() {
	int iCount = 1;
	while (true) {
		int iSize = 0;
		cin >> iSize;

		if (iSize == 0) {
			break;
		}

		vector<vector<int>> vecRupee(iSize);
		for (int iX = 0; iX < iSize; iX++) {
			vector<int> vec(iSize);
			for (int iY = 0; iY < iSize; iY++) {
				int iRupee = 0;
				cin >> iRupee;
				vec[iY] = iRupee;
			}
			vecRupee[iX] = vec;
		}

		cout << "Problem " << iCount++ << ": " << Dijkstra(vecRupee, iSize) << "\n";
	}
	return 0;
}