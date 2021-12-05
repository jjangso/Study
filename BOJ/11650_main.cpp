#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	int iCount = 0;
	scanf("%d", &iCount);

	map <int, set<int>> mapPoint;
	for (int i = 0; i < iCount; i++) {
		int iX = 0, iY = 0;
		scanf("%d", &iX);
		scanf("%d", &iY);

		auto iter = mapPoint.find(iX);
		if (iter == mapPoint.end()) {
			// 동일한 x 좌표가 존재하지 않을 때.
			set<int> setPoint;
			setPoint.insert(iY);
			mapPoint.insert(make_pair(iX, setPoint));
		}
		else {
			// 동일한 x 좌표가 존재할 때.
			(*iter).second.insert(iY);
		}
	}
	
	auto it_s = mapPoint.begin();
	auto it_e = mapPoint.end();
	for (; it_s != it_e; it_s++) {
		for (const auto& y : (*it_s).second) {
			cout << (*it_s).first << " " << y << "\n";
		}
	}

	return 0;
}