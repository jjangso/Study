#include <iostream>
#include <map>
using namespace std;

int main()
{
	int iNum = 0;
	scanf("%d", &iNum);

	multimap <int, string> mapMember;
	for (int i = 0; i < iNum; i++) {
		int iAge = 0;
		scanf("%d", &iAge);

		char cName[101] = "";
		scanf("%s", &cName);
		mapMember.insert(make_pair(iAge, cName));
	}
	
	auto it_s = mapMember.begin();
	auto it_e = mapMember.end();
	for (; it_s != it_e; it_s++) {
		cout << (*it_s).first << " " << (*it_s).second.c_str() << "\n";
	}

	return 0;
}