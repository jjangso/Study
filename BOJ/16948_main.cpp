#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct POS
{
	int iX = 0;
	int iY = 0;
	
	POS() {};
	POS(int p_iX, int p_iY) : iX(p_iX), iY(p_iY) {};
};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int iSize = 0;
	cin >> iSize;

	POS iStartPos, iEndPos;
	cin >> iStartPos.iX >> iStartPos.iY >> iEndPos.iX >> iEndPos.iY;

	vector<POS> vecMove = { POS(-2, -1), POS(-2, 1), POS(0, -2), POS(0, 2), POS(2, -1), POS(2, 1) };
	vector<vector<bool>> vecVisit(iSize, vector<bool>(iSize, false));
	queue<pair<int, POS>> queuePos;
	queuePos.push({ 0, iStartPos });

	int iResult = -1;
	while (!queuePos.empty()) {
		int iCount = queuePos.front().first;
		POS pos = queuePos.front().second;
		queuePos.pop();

		if (pos.iX == iEndPos.iX && pos.iY == iEndPos.iY) {
			iResult = iCount;
			break;
		}

		if (vecVisit[pos.iX][pos.iY]) {
			continue;
		}
		vecVisit[pos.iX][pos.iY] = true;

		for (const auto& move : vecMove) {
			POS posNext(pos.iX + move.iX, pos.iY + move.iY);
			if (posNext.iX < 0 || posNext.iX >= iSize ||
				posNext.iY < 0 || posNext.iY >= iSize ||
				vecVisit[posNext.iX][posNext.iY] ) {
				continue;
			}
			queuePos.push({ iCount + 1, posNext });
		}
	}
	
	cout << iResult << endl;
	return 0;
};