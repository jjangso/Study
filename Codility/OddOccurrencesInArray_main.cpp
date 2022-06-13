// https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
// Detected time complexity: O(N) or O(N*log(N))

#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    int iNum = 0;
    int iCount = 0;
    
    for ( int i = 0; i < A.size(); i++ ) {
        if ( iNum == A[i] ) {
            iCount++;
            continue;
        }

        if ( iCount != 0 && (iCount % 2) == 1 ) {
            break;
        }
        
        iNum = A[i];
        iCount = 1;
    }

    return iNum;
}