#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int iKeyCnt = 0;
	int iPressCnt = 0;
	int iBtnCnt = 0;
	cin >> iKeyCnt >> iPressCnt >> iBtnCnt;

	vector<int> vecKey(iKeyCnt);
	for (int i = 0; i < iKeyCnt; i++) {
		int iKey = 0;
		cin >> iKey;

		vecKey[i] = iKey;
	}

	vector<int> vecPress(iPressCnt);
	for (int i = 0; i < iPressCnt; i++) {
		int iBtn = 0;
		cin >> iBtn;

		vecPress[i] = iBtn;
	}

	string sResult = "normal";
	if (iPressCnt >= iKeyCnt) {
		for (int i = 0; i < iPressCnt; i++) {
			if (iPressCnt - i < iKeyCnt) {
				break;
			}

			int iKey = 0;
			bool bIsSame = false;
			for (int j = i; j < iPressCnt; j++) {
				if (vecPress[j] == vecKey[iKey++]) {
					if (iKey == iKeyCnt) {
						bIsSame = true;
						break;
					}
					continue;
				}
				break;
			}

			if (bIsSame) {
				sResult = "secret";
				break;
			}
		}
	}

	cout << sResult.c_str() << "\n";
	return 0;
}