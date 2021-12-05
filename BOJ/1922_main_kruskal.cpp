#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Computer {
public:
	Computer(int p_iCom1, int p_iCom2, int p_iDistance)
	{
		this->iCom1 = p_iCom1;
		this->iCom2 = p_iCom2;
		this->iDistance = p_iDistance;
	}

	int iCom1 = 0;
	int iCom2 = 0;
	int iDistance = 0;

	bool operator<(Computer& pr_Computer){
		return this->iDistance < pr_Computer.iDistance;
	}
};

// 부모 노드 탐색.
int getParent(vector<int>& pr_vecParent, int p_iParent) {
	if (pr_vecParent[p_iParent] == p_iParent) return p_iParent;

	return pr_vecParent[p_iParent] = getParent(pr_vecParent, pr_vecParent[p_iParent]);
};

// 같은 부모를 가지는지 확인.
bool find(vector<int>& pr_vecParent, int p_iCom1, int p_iCom2) {
	p_iCom1 = getParent(pr_vecParent, p_iCom1);
	p_iCom2 = getParent(pr_vecParent, p_iCom2);

	return p_iCom1 == p_iCom2;
};

// 부모 노드를 병합.
void unionParent(vector<int>& pr_vecParent, int p_iCom1, int p_iCom2) {
	p_iCom1 = getParent(pr_vecParent, p_iCom1);
	p_iCom2 = getParent(pr_vecParent, p_iCom2);

	// 숫자가 더 작은 부모로 병합.
	p_iCom1 < p_iCom2 ? pr_vecParent[p_iCom2] = p_iCom1 : pr_vecParent[p_iCom1] = p_iCom2;
};

int main()
{
	int iCount = 0;			// 컴퓨터의 수.
	int iLine = 0;			// 선의 수.
	scanf("%d", &iCount);
	scanf("%d", &iLine);

	// 초기화.
	vector <int> vecParent;
	for (int i = 0; i < iCount; i++) {
		vecParent.push_back(i);
	}

	vector <Computer> vecComputer;
	for (int i = 0; i < iLine; i++) {
		int iCom1 = 0;
		int iCom2 = 0;
		int iDistance = 0;
		scanf("%d", &iCom1);
		scanf("%d", &iCom2);
		scanf("%d", &iDistance);

		if (iCom1 == iCom2) {
			continue;
		}
		vecComputer.push_back(Computer(iCom1, iCom2, iDistance));
	}

	sort(vecComputer.begin(), vecComputer.end());

	// 거리 합 계산.
	int iSum = 0;
	for (int i = 0; i < vecComputer.size(); i++) {
		int iCom1 = vecComputer[i].iCom1 - 1;
		int iCom2 = vecComputer[i].iCom2 - 1;
		if (!find(vecParent, iCom1, iCom2)) {
			// 동일한 부모를 가르치지 않는 경우, 즉 사이클이 발생하지 않으면.
			iSum += vecComputer[i].iDistance;
			unionParent(vecParent, iCom1, iCom2);
		}
	}

	// 결과 출력.
	cout << iSum << "\n";

	return 0;
}