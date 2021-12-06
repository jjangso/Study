#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

long long search(const vector<int>& p_vecTimes, const int& p_iPerson, long long p_llStart, long long p_llEnd) {
	if (p_llStart == p_llEnd) {
		return p_llStart;
	}

	long long llMid = (p_llStart + p_llEnd) / 2;
	int iCount = 0;
	for (const auto& time : p_vecTimes) {
		if (llMid < time) {
			continue;
		}

		iCount += (llMid / time);

		if (iCount >= p_iPerson) {
			break;
		}
	}

	return p_iPerson <= iCount ? search(p_vecTimes, p_iPerson, p_llStart, llMid) : search(p_vecTimes, p_iPerson, llMid + 1, p_llEnd);
};

long long solution(int n, vector<int> times) {
	long long answer = 0;
	
	sort(times.begin(), times.end(), greater<int>());

	return search(times, n, (long long)times[times.size() - 1], (long long)times[0] * n);
}