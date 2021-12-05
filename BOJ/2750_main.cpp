#include <iostream>
#include <set>
using namespace std;

int main()
{
	int iCount = 0;
	scanf("%d", &iCount);

	set <int> setResult;
	for (int i = 0; i < iCount; i++) {
		int iNum = 0;
		scanf("%d", &iNum);

		setResult.insert(iNum);
	}

	for (const auto& num : setResult) {
		cout << num << "\n";
	}
	return 0;
}