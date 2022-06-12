#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    int iResult = 1;
    for ( const auto& num : A ) {
        if ( num > 0 ) {
            if ( iResult < num ) {
                break;
            } else if ( iResult == num ) {
                iResult++;
            }
        }
    }

    return iResult;
}