// https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
// Detected time complexity: O(N * log(N))

#include <algorithm>
#define MIN -1234567890

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    int iResult = MIN;
    for ( int i = 0; i <= 3; i++ ) {
        int iMulti = 1;
        for ( int j = 0; j < (3 - i); j++ ) {
            iMulti *= A[j];
        }

        for ( int j = 0; j < i; j++ ) {
            iMulti *= A[A.size() - 1 - j];
        }

        if ( iResult < iMulti ) {
            iResult = iMulti;
        }
    }
	
    return iResult;
}