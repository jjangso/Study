#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e8

struct NODE{
	int iNode = 0;
	int iDist = 0;

	NODE(const int& p_iNode, const int& p_iDist) : iNode(p_iNode), iDist(p_iDist) {};
};

vector<int> dijkstra(const vector<vector<NODE>>& p_vecNode, const int& p_iStart)
{
	int iNodeCnt = p_vecNode.size();
	vector<int> vecDist(iNodeCnt, INF);

	auto compare = [](const NODE &p_Node1, const NODE p_Node2) {
		return p_Node1.iDist > p_Node2.iDist;
	};
	priority_queue<NODE, vector<NODE>, decltype(compare)> queueNode(compare);
	queueNode.push(NODE(p_iStart, 0));
	while (!queueNode.empty()) {
		int iNode = queueNode.top().iNode;
		int iDist = queueNode.top().iDist;
		queueNode.pop();

		if (vecDist[iNode] <= iDist) {
			continue;
		}
		vecDist[iNode] = iDist;

		for (const auto& node : p_vecNode[iNode]) {
			int iNextDist = iDist + node.iDist;
			if (vecDist[node.iNode] <= iNextDist) {
				continue;
			}
			queueNode.push(NODE(node.iNode, iNextDist));
		}
	}
	return vecDist;
};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int iNodeCnt = 0;
	int iEdgeCnt = 0;
	cin >> iNodeCnt >> iEdgeCnt;

	vector<vector<NODE>> vecNode(iNodeCnt + 1);
	for (int i = 0; i < iEdgeCnt; i++) {
		int iNode1 = 0;
		int iNode2 = 0;
		int iDist = 0;
		cin >> iNode1 >> iNode2 >> iDist;

		vecNode[iNode1].push_back(NODE(iNode2, iDist));
		vecNode[iNode2].push_back(NODE(iNode1, iDist));
	}

	int iNode1 = 0;
	int iNode2 = 0;
	cin >> iNode1 >> iNode2;

	vector<int> vecDist1 = dijkstra(vecNode, iNode1);
	vector<int> vecDist2 = dijkstra(vecNode, iNode2);
	int iResult = vecDist1[iNode2] + min(vecDist1[1] + vecDist2[iNodeCnt], vecDist2[1] + vecDist1[iNodeCnt]);

	cout << (iResult >= INF ? -1 : iResult) << endl;
	return 0;
};