// https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

vector<int> solution(vector<int> &A, int K) {
    vector<int> vecResult = A;

    if ( A.size() != 0 && K != 0 ) {
        int iRotate = K < A.size() ? K : K % A.size();  
          
        for ( int i = 0; i < A.size(); i++ ) {
            int iPos = i + iRotate;
            if ( iPos >= A.size() ) {
                iPos -= A.size();
            }
            vecResult[iPos] = A[i];
        }
    }

    return vecResult;
}