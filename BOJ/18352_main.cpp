#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Dijkstra(const vector<vector<int>>& p_vecCity, const int& p_iDist, const int& p_iStart) {
	vector<int> vecDist(p_vecCity.size(), -1);

	queue<pair<int, int>> queueCity;
	queueCity.push(make_pair(p_iStart, 0));

	while (!queueCity.empty()) {
		int iCity = queueCity.front().first;
		int iDist = queueCity.front().second;
		queueCity.pop();

		if (vecDist[iCity] != -1 &&
			vecDist[iCity] <= iDist) {
			continue;
		}
		vecDist[iCity] = iDist++;

		if (vecDist[iCity] > p_iDist) {
			continue;
		}

		for (const auto& city : p_vecCity[iCity]) {
			if (vecDist[city] != -1 &&
				vecDist[city] <= iDist) {
				continue;
			}
			queueCity.push(make_pair(city, iDist));
		}
	}

	bool bExist = false;
	for (int i = 1; i < vecDist.size(); i++) {
		if (vecDist[i] == p_iDist) {
			cout << i << "\n";
			bExist = true;
		}
	}

	if (bExist == false) {
		cout << "-1" << endl;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int iCityCnt, iRoadCnt, iDist, iStart;
	cin >> iCityCnt >> iRoadCnt >> iDist >> iStart;

	vector<vector<int>> vecCity(iCityCnt + 1);
	for (int i = 0; i < iRoadCnt; i++) {
		int iStart, iEnd;
		cin >> iStart >> iEnd;

		vecCity[iStart].push_back(iEnd);
	}

	Dijkstra(vecCity, iDist, iStart);

	return 0;
}