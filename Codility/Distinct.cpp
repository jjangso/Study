// https://app.codility.com/programmers/lessons/6-sorting/distinct/
// Detected time complexity: O(N*log(N)) or O(N)

#define MAX 1000000

int solution(vector<int> &A) {
    vector<bool> vecExist(2000001, false);

    int iResult = 0;
    for ( const auto& num : A ) {
        if ( !vecExist[num + MAX] ) {
            vecExist[num + MAX] = true;
            iResult++;
        }
    }

    return iResult;
}