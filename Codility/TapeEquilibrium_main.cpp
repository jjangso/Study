#define INF 1000000000

int solution(vector<int> &A) {
    vector<int> vecSum(A.size(), 0);
    for ( int i = 0; i < A.size(); i++ ) {
        if ( i > 0 ) {
            vecSum[i] = vecSum[i-1];
        }
        vecSum[i] += A[i];
    }

    int iResult = INF;
    for ( int i = 0; i < (A.size() - 1); i++ ) {
        int iMin = (vecSum[i] * 2) - vecSum[A.size() - 1];
        if ( iMin < 0 ) {
            iMin = -iMin;
        }

        if ( iResult > iMin ) {
            iResult = iMin;
        }
    }

    return iResult;
}