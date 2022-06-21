// https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
// Detected time complexity: O(N*log(N)) or O(N)

#include <algorithm>
#define MAX 10000000

bool compare(pair<int, int>& p_Pair1, pair<int, int>& p_Pair2) {
    if ( p_Pair1.first == p_Pair2.first ) {
        return p_Pair1.second < p_Pair2.second;
    }
    return p_Pair1.first < p_Pair2.first;
}

int solution(vector<int> &A) {
	vector<pair<int, int>> vecDiscs(A.size());
    for ( int i = 0 ; i < A.size(); i++ ) {
        int iLeft = A[i] > 100000 ? 0 : (i - A[i]);
        int iRight = A[i] > 100000 ? 100000 : (i + A[i]);
        vecDiscs[i] = { iLeft, iRight };
    }
    sort(vecDiscs.begin(), vecDiscs.end(), compare);

    int iResult = 0;
    for ( int i = 0; i < vecDiscs.size(); i++ ) {
        for ( int j = (i + 1) ; j < vecDiscs.size(); j++ ) {
            if ( vecDiscs[i].second < vecDiscs[j].first ) {
                break;
            }
            iResult++;
            
            if ( iResult > MAX ) {
                iResult = -1;
                break;
            }
        }

        if ( iResult == -1 ) {
            break;
        }
    }

    return iResult;
}