// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

int solution(int N) {
    int iResult = 0;
    int iCount = -1;
	
    while (true) {
        if ( N & 1 ) {
            if( iCount > iResult ) {
                iResult = iCount;
            } 
            iCount = 0;
        } else {
            if ( iCount != -1 ) {
                iCount++;
            }
        }
        
        N = N >> 1;
        
        if ( N <= 0 ) {
            break;
        }
    }
	
    return iResult;
}