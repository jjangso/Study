#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Node {
public:
	Node(int p_iNode1, int p_iNode2, long long p_llDistance)
	{
		this->iNode1 = p_iNode1;
		this->iNode2 = p_iNode2;
		this->llDistance = p_llDistance;
	}

	int iNode1 = 0;
	int iNode2 = 0;
	long long llDistance = 0;

	bool operator<(Node& pr_Node){
		return this->llDistance < pr_Node.llDistance;
	}
};

// 부모 노드 탐색.
int getParent(vector<int>& pr_vecParent, int p_iParent) {
	if (pr_vecParent[p_iParent] == p_iParent) return p_iParent;

	return pr_vecParent[p_iParent] = getParent(pr_vecParent, pr_vecParent[p_iParent]);
};

// 같은 부모를 가지는지 확인.
bool find(vector<int>& pr_vecParent, int p_iNode1, int p_iNode2) {
	p_iNode1 = getParent(pr_vecParent, p_iNode1);
	p_iNode2 = getParent(pr_vecParent, p_iNode2);

	return p_iNode1 == p_iNode2;
};

// 부모 노드를 병합.
void unionParent(vector<int>& pr_vecParent, int p_iNode1, int p_iNode2) {
	p_iNode1 = getParent(pr_vecParent, p_iNode1);
	p_iNode2 = getParent(pr_vecParent, p_iNode2);

	// 숫자가 더 작은 부모로 병합.
	p_iNode1 < p_iNode2 ? pr_vecParent[p_iNode2] = p_iNode1 : pr_vecParent[p_iNode1] = p_iNode2;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int island = 0;	// 섬의 수.
		cin >> island;

		// 초기화.
		vector <int> vecParent;
		for (int j = 0; j < island; j++) {
			vecParent.push_back(j);
		}

		vector <pair<int, int>> vecIsland;
		for (int j = 0; j < island; j++) {
			int iX = 0;
			cin >> iX;
			vecIsland.push_back(make_pair(iX, 0));
		}

		for (int j = 0; j < island; j++) {
			int iY = 0;
			cin >> iY;
			vecIsland[j].second = iY;
		}

		long double ldE;
		cin >> ldE;

		vector <Node> vecNode;
		for (int j = 0; j < vecIsland.size(); j++) {
			for (int k = j + 1; k < vecIsland.size(); k++) {
				long long llDistance = pow(vecIsland[j].first - vecIsland[k].first, 2) + pow(vecIsland[j].second - vecIsland[k].second, 2);
				vecNode.push_back(Node(j, k, llDistance));
			}
		}
		sort(vecNode.begin(), vecNode.end());

		// 거리 합 계산.
		long long llSum = 0;
		for (int j = 0; j < vecNode.size(); j++) {
			int iNode1 = vecNode[j].iNode1;
			int iNode2 = vecNode[j].iNode2;
			if (!find(vecParent, iNode1, iNode2)) {
				// 동일한 부모를 가르치지 않는 경우, 즉 사이클이 발생하지 않으면.
				llSum += vecNode[j].llDistance;
				unionParent(vecParent, iNode1, iNode2);
			}
		}

		// 결과 출력.
		llSum = round(ldE * llSum);
		cout.precision(0);
		cout.setf(ios::fixed);
		cout << "#" << test_case << " " << llSum << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}