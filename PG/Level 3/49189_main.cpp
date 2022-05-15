#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> vecNode (n+1, vector<int>());
    for ( const auto& pair : edge ) {
        int iNode1 = pair[0];
        int iNode2 = pair[1];
        vecNode[iNode1].push_back(iNode2);
        vecNode[iNode2].push_back(iNode1);
    }
    
    int iMax = 0;
    vector<int> vecDegree (n+1, -1);

    queue<pair<int, int>> queueNode;
    queueNode.push(make_pair(1, 0));
    while ( !queueNode.empty() ) {
        int iNode = queueNode.front().first;
        int iDegree = queueNode.front().second;
        queueNode.pop();
        
        if ( vecDegree[iNode] != -1 ) {
            continue;
        }
        
        if  ( iMax < iDegree ) {
            iMax = iDegree;
        }
        
        vecDegree[iNode] = iDegree;
        iDegree++;
        
        for ( const auto& node : vecNode[iNode] ) {
            if ( vecDegree[node] != -1 ) {
                continue;
            }
            
            queueNode.push(make_pair(node, iDegree));
        }
    }
    
    for ( int i = 1; i <= n; i++ ) {
        if ( vecDegree[i] == iMax ) {
            answer++;
        }
    }
    
    return answer;
}