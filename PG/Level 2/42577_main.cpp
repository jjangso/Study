#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());

	bool bFind = false;
	unordered_set <string> hashPhone;
	for (const auto& phone : phone_book) {
		string sNum;
		for (int i = 0; i < phone.size() - 1; i++) {
			sNum.push_back(phone[i]);

			if (hashPhone.find(sNum) != hashPhone.end()) {
				bFind = true;
				break;
			}
		}

		if (bFind) {
			break;
		}

		hashPhone.insert(phone);
	}

	return !bFind;
}