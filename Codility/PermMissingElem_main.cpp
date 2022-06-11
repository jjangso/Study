#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    int iResult = 1;
    for ( ; iResult <= A.size(); iResult++ ) {
        if ( A[iResult-1] != iResult ) {
            break;
        } 
    }

    return iResult;    
}