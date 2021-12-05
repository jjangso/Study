#include <iostream>
#include <vector>
using namespace std;

class Country {
public:
	Country(int p_iCtry1, int p_iCtry2)
	{
		this->iCtry1 = p_iCtry1;
		this->iCtry2 = p_iCtry2;
	}

	int iCtry1 = 0;
	int iCtry2 = 0;
};

// 부모 노드 탐색
int getParent(vector<int>& pr_vecParent, int p_iParent) {
	if (pr_vecParent[p_iParent] == p_iParent) return p_iParent;

	return pr_vecParent[p_iParent] = getParent(pr_vecParent, pr_vecParent[p_iParent]);
};

// 같은 부모를 가지는지 확인
bool find(vector<int>& pr_vecParent, int p_iCtry1, int p_iCtry2) {
	int iCtry1 = getParent(pr_vecParent, p_iCtry1);
	int iCtry2 = getParent(pr_vecParent, p_iCtry2);

	return iCtry1 == iCtry2;
}

// 부모 노드를 병합.
void unionParent(vector<int>& pr_vecParent, int p_iCtry1, int p_iCtry2) {
	p_iCtry1 = getParent(pr_vecParent, p_iCtry1);
	p_iCtry2 = getParent(pr_vecParent, p_iCtry2);

	// 숫자가 더 작은 부모로 병합.
	p_iCtry1 < p_iCtry2 ? pr_vecParent[p_iCtry2] = p_iCtry1 : pr_vecParent[p_iCtry1] = p_iCtry2;
}

int main()
{
	int iCount = 0;				// 테스트 케이스.
	scanf("%d", &iCount);

	vector <int> vecResult;
	for (int i = 0; i < iCount; i++) {
		int iCountry = 0;		// 국가의 수.
		int iAirplane = 0;		// 비행기의 수.
		scanf("%d", &iCountry);
		scanf("%d", &iAirplane);

		// 초기화.
		vector <int> vecParent;
		vector < Country> vecCountry;
		for (int j = 0; j < iCountry; j++) {
			vecParent.push_back(j);
		}

		for (int j = 0; j < iAirplane; j++) {
			int iCtry1 = 0;
			int iCtry2 = 0;
			scanf("%d", &iCtry1);
			scanf("%d", &iCtry2);

			vecCountry.push_back(Country(iCtry1, iCtry2));
		}

		// 거리 합 계산.
		int iSum = 0;
		for (int j = 0; j < vecCountry.size(); j++) {
			int iCtry1 = vecCountry[j].iCtry1 - 1;
			int iCtry2 = vecCountry[j].iCtry2 - 1;
			if (!find(vecParent, iCtry1, iCtry2)) {
				// 동일한 부모를 가르치지 않는 경우, 즉 사이클이 발생하지 않으면.
				iSum++;
				unionParent(vecParent, iCtry1, iCtry2);
			}
		}
		vecResult.push_back(iSum);
	}

	// 결과 출력.
	for (const auto& result : vecResult) {
		cout << result << "\n";
	}

	return 0;
}