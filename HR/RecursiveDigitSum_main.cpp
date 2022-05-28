#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* Complete the 'superDigit' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
*  1. STRING n
*  2. INTEGER k
*/

int superDigit(string n, int k) {
	if (n.size() <= 1) {
		return stoi(n);
	}

	long long llResult = 0;
	for (int i = 0; i < n.size(); i++) {
		llResult += (n[i] - '0');
	}

	if (k >= 1) {
		llResult *= k;
	}
	return superDigit(to_string(llResult), 0);
}