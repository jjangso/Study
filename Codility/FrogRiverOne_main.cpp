int solution(int X, vector<int> &A) {
    vector<bool> vecLeaves(X + 1, false);
    int iCount = X;
    int iResult = 0;
    for ( ; iResult < A.size(); iResult++ ) {
        const auto& leaf = A[iResult];
        if ( X < leaf || vecLeaves[leaf] ) {
            continue;
        }

        vecLeaves[leaf] = true;
        iCount--;

        if ( iCount == 0 ) {
            break;
        }
    }

    return iCount == 0 ? iResult : -1;
}