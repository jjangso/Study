#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 300

class Night
{
public:
	Night(int p_iX, int p_iY, int p_iCount) {
		this->m_iX = p_iX;
		this->m_iY = p_iY;
		this->m_iCount = p_iCount;
	}

	int m_iX = 0;
	int m_iY = 0;
	int m_iCount = 0;
};

int BFS(const int& p_iX, const int& p_iY, const int& p_iDestX, const int& p_iDestY, const int& p_iLine)  {
	int iResult = 0;
	bool aryCheck[MAX_SIZE][MAX_SIZE] = { false, };
	queue <Night> queueNight;
	queueNight.push(Night(p_iX, p_iY, 0));
	
	while (!queueNight.empty()) {
		Night night = queueNight.front();
		queueNight.pop();

		// 현재 나이트의 x, y 좌표를 이미 방문한 적이 있으면 NEXT.
		if (aryCheck[night.m_iX][night.m_iY] == true) {
			continue;
		}

		aryCheck[night.m_iX][night.m_iY] = true;

		// 현재 나이트의 x, y 좌표와 목적지 x, y 좌표가 동일하면 종료. 
		if (night.m_iX == p_iDestX && night.m_iY == p_iDestY) {
			iResult = night.m_iCount;
			break;
		}

		int iX = night.m_iX - 2;
		int iY = night.m_iY + 1;
		if (iX >= 0 && iY < p_iLine) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}

		iX = night.m_iX - 1;
		iY = night.m_iY + 2;
		if (iX >= 0 && iY < p_iLine) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}

		iX = night.m_iX + 1;
		iY = night.m_iY + 2;
		if (iX < p_iLine && iY < p_iLine) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}

		iX = night.m_iX + 2;
		iY = night.m_iY + 1;
		if (iX < p_iLine && iY < p_iLine) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}

		iX = night.m_iX + 1;
		iY = night.m_iY - 2;
		if (iX < p_iLine && iY >= 0 ) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}

		iX = night.m_iX + 2;
		iY = night.m_iY - 1;
		if (iX < p_iLine && iY >= 0) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}

		iX = night.m_iX - 1;
		iY = night.m_iY - 2;
		if (iX >= 0 && iY >= 0) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}

		iX = night.m_iX - 2;
		iY = night.m_iY - 1;
		if (iX >= 0 && iY >= 0) {
			queueNight.push(Night(iX, iY, night.m_iCount + 1));
		}
	}

	return iResult;
};

int main() {
	int iCount = 0;
	cin >> iCount;

	vector <int> vecResult;
	for (int i = 0; i < iCount; i++) {
		int iLine = 0;
		cin >> iLine;

		int iX = 0;
		int iY = 0;
		cin >> iX;
		cin >> iY;

		int iDestX = 0;
		int iDestY = 0;
		cin >> iDestX;
		cin >> iDestY;

		vecResult.push_back(BFS(iX, iY, iDestX, iDestY, iLine));
	}

	for (const auto& result : vecResult) {
		cout << result << "\n";
	}

	return 0;
}