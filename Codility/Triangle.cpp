// https://app.codility.com/programmers/lessons/6-sorting/triangle/
// Detected time complexity: O(N*log(N))

#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    int iResult = 0;
    for ( int P = 0; P < A.size(); P++ ) {
        if ( A[P] <= 0 ) {
            continue;
        }
        
        for ( int Q = (P + 1); Q < A.size(); Q++ ) {
            for ( int R = (Q + 1); R < A.size(); R++ ) {
                long long llSumPQ = (long long)A[P] + A[Q];
                if ( llSumPQ <= A[R] ) {
                    break;
                }

                long long llSumQR = (long long)A[Q] + A[R];
                long long llSumRP = (long long)A[R] + A[P];
                if ( llSumQR > A[P] && llSumRP > A[Q] ) {
                    iResult = 1;
                    break;
                }
            }

            if ( iResult == 1 ) {
                break;
            }
        }
        
        if ( iResult == 1 ) {
            break;
        }
    }
	
    return iResult;
}