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

// �θ� ��� Ž��.
int getParent(vector<int>& pr_vecParent, int p_iParent) {
	if (pr_vecParent[p_iParent] == p_iParent) return p_iParent;

	return pr_vecParent[p_iParent] = getParent(pr_vecParent, pr_vecParent[p_iParent]);
};

// ���� �θ� �������� Ȯ��.
bool find(vector<int>& pr_vecParent, int p_iCom1, int p_iCom2) {
	p_iCom1 = getParent(pr_vecParent, p_iCom1);
	p_iCom2 = getParent(pr_vecParent, p_iCom2);

	return p_iCom1 == p_iCom2;
};

// �θ� ��带 ����.
void unionParent(vector<int>& pr_vecParent, int p_iCom1, int p_iCom2) {
	p_iCom1 = getParent(pr_vecParent, p_iCom1);
	p_iCom2 = getParent(pr_vecParent, p_iCom2);

	// ���ڰ� �� ���� �θ�� ����.
	p_iCom1 < p_iCom2 ? pr_vecParent[p_iCom2] = p_iCom1 : pr_vecParent[p_iCom1] = p_iCom2;
};

int main()
{
	int iCount = 0;			// ��ǻ���� ��.
	int iLine = 0;			// ���� ��.
	scanf("%d", &iCount);
	scanf("%d", &iLine);

	// �ʱ�ȭ.
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

	// �Ÿ� �� ���.
	int iSum = 0;
	for (int i = 0; i < vecComputer.size(); i++) {
		int iCom1 = vecComputer[i].iCom1 - 1;
		int iCom2 = vecComputer[i].iCom2 - 1;
		if (!find(vecParent, iCom1, iCom2)) {
			// ������ �θ� ����ġ�� �ʴ� ���, �� ����Ŭ�� �߻����� ������.
			iSum += vecComputer[i].iDistance;
			unionParent(vecParent, iCom1, iCom2);
		}
	}

	// ��� ���.
	cout << iSum << "\n";

	return 0;
}