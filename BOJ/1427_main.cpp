#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main()
{
	char cNums[11] = "";
	scanf("%s", &cNums);
	string sNums = cNums;
	
	multiset <char, greater<char>> setNums;
	for (int i = 0; i < sNums.size(); i++) {
		setNums.insert(sNums[i]);
	}

	for (const auto& num : setNums) {
		cout << num;
	}
	return 0;
}