// https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/
// Detected time complexity: O(N)

int solution(vector<int> &A) {
    int iPCount = 0;
    int iResult = 0;
	
    for ( const auto& car : A ) {
        car == 0 ? iPCount++ : iResult += iPCount;

        if ( iResult > 1000000000 ) {
            iResult = -1;
            break;
        }
    }
	
    return iResult;
}