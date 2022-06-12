vector<int> solution(int N, vector<int> &A) {
    vector<int> vecResult(N, 0);
    int iFill = 0;
    int iMax = 0;
    for ( const auto& count : A ) {
        if ( count == (N + 1) ) {
            iFill = iMax;
            continue;
        }

        vecResult[count-1] = iFill > vecResult[count-1] ? (iFill + 1) : vecResult[count-1] + 1;

        if ( iMax < vecResult[count-1] ) {
            iMax = vecResult[count-1];
        }
    }

    for ( auto& result : vecResult ) {
        if ( result < iFill ) {
            result = iFill;
        }
    }

    return vecResult;
}