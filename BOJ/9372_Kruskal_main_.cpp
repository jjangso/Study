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

// �θ� ��� Ž��
int getParent(vector<int>& pr_vecParent, int p_iParent) {
	if (pr_vecParent[p_iParent] == p_iParent) return p_iParent;

	return pr_vecParent[p_iParent] = getParent(pr_vecParent, pr_vecParent[p_iParent]);
};

// ���� �θ� �������� Ȯ��
bool find(vector<int>& pr_vecParent, int p_iCtry1, int p_iCtry2) {
	int iCtry1 = getParent(pr_vecParent, p_iCtry1);
	int iCtry2 = getParent(pr_vecParent, p_iCtry2);

	return iCtry1 == iCtry2;
}

// �θ� ��带 ����.
void unionParent(vector<int>& pr_vecParent, int p_iCtry1, int p_iCtry2) {
	p_iCtry1 = getParent(pr_vecParent, p_iCtry1);
	p_iCtry2 = getParent(pr_vecParent, p_iCtry2);

	// ���ڰ� �� ���� �θ�� ����.
	p_iCtry1 < p_iCtry2 ? pr_vecParent[p_iCtry2] = p_iCtry1 : pr_vecParent[p_iCtry1] = p_iCtry2;
}

int main()
{
	int iCount = 0;				// �׽�Ʈ ���̽�.
	scanf("%d", &iCount);

	vector <int> vecResult;
	for (int i = 0; i < iCount; i++) {
		int iCountry = 0;		// ������ ��.
		int iAirplane = 0;		// ������� ��.
		scanf("%d", &iCountry);
		scanf("%d", &iAirplane);

		// �ʱ�ȭ.
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

		// �Ÿ� �� ���.
		int iSum = 0;
		for (int j = 0; j < vecCountry.size(); j++) {
			int iCtry1 = vecCountry[j].iCtry1 - 1;
			int iCtry2 = vecCountry[j].iCtry2 - 1;
			if (!find(vecParent, iCtry1, iCtry2)) {
				// ������ �θ� ����ġ�� �ʴ� ���, �� ����Ŭ�� �߻����� ������.
				iSum++;
				unionParent(vecParent, iCtry1, iCtry2);
			}
		}
		vecResult.push_back(iSum);
	}

	// ��� ���.
	for (const auto& result : vecResult) {
		cout << result << "\n";
	}

	return 0;
}