#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct CITY {
	int iCost = 0;
	map<int, int> mapBus;
};

int Dijkstra(const vector<CITY>& p_vecCity, const int& p_iStart, const int& p_iEnd) {
	vector<int> vecCost(p_vecCity.size(), -1);
	
	queue<pair<int, int>> queueCity;
	queueCity.push(make_pair(p_iStart, 0));

	while (!queueCity.empty()) {
		int iCity = queueCity.front().first;
		int iCost = queueCity.front().second;
		queueCity.pop();

		if (vecCost[iCity] != -1 &&
			vecCost[iCity] <= iCost) {
			continue;
		}
		vecCost[iCity] = iCost;

		if (iCity == p_iEnd) {
			continue;
		}

		for (const auto& bus : p_vecCity[iCity].mapBus) {
			int iNextCity = bus.first;
			int iNextCost = bus.second + iCost;
			if (vecCost[iNextCity] != -1 &&
				vecCost[iNextCity] <= iNextCost) {
				continue;
			}
			queueCity.push(make_pair(iNextCity, iNextCost));
		}
	}

	return vecCost[p_iEnd];
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int iCityCnt, iBusCnt;
	cin >> iCityCnt >> iBusCnt;
	
	vector<CITY> vecCity(iCityCnt+1);
	for (int i = 0; i < iBusCnt; i++) {
		int iStart, iEnd, iCost;
		cin >> iStart >> iEnd >> iCost;

		auto iter = vecCity[iStart].mapBus.find(iEnd);
		if (iter != vecCity[iStart].mapBus.end()) {
			if ((*iter).second > iCost) {
				(*iter).second = iCost;
			}
		}
		else {
			vecCity[iStart].mapBus.insert(make_pair(iEnd, iCost));
		}
	}

	int iStart, iEnd;
	cin >> iStart >> iEnd;

	cout << Dijkstra(vecCity, iStart, iEnd) << endl;
	return 0;
}