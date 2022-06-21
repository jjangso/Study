int solution(int X, int Y, int D) {
    Y -= X;
	
    int iResult = Y/D;
    if ( Y%D != 0 ) {
        iResult++;
    }
	
    return iResult;
}