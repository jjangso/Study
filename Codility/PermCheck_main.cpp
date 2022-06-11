#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    bool bResult = true;
    for ( int i = 0; i < A.size(); i++ ) {
        if ( A[i] != (i + 1) ) {
            bResult = false;
            break;
        }
    }
	
    return bResult;
}