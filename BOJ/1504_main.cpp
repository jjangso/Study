#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE{
	int iNode = 0;
	int iDist = 0;

	NODE(const int& p_iNode, const int& p_iDist) : iNode(p_iNode), iDist(p_iDist) {};
};


int Dijkstra(const vector<vector<NODE>>& p_vecNode, const int& p_iStart, const int p_iEnd)
{
	int iNodeCnt = p_vecNode.size();
	vector<int> vecDist(iNodeCnt, -1);

	auto compare = [](const NODE &p_Node1, const NODE p_Node2) {
		return p_Node1.iDist > p_Node2.iDist;
	};
	priority_queue<NODE, vector<NODE>, decltype(compare)> queueNode(compare);
	queueNode.push(NODE(p_iStart, 0));
	while (!queueNode.empty()) {
		int iNode = queueNode.top().iNode;
		int iDist = queueNode.top().iDist;
		queueNode.pop();

		if (vecDist[iNode] != -1 && vecDist[iNode] <= iDist) {
			continue;
		}
		vecDist[iNode] = iDist;

		if (iNode == p_iEnd) {
			continue;
		}

		if (vecDist[p_iEnd] != -1 && vecDist[p_iEnd] <= iDist) {
			continue;
		}

		for (const auto& node : p_vecNode[iNode]) {
			int iNextDist = iDist + node.iDist;
			if (vecDist[node.iNode] != -1 && vecDist[node.iNode] <= iNextDist) {
				continue;
			}
			queueNode.push(NODE(node.iNode, iNextDist));
		}
	}
	return vecDist[p_iEnd];
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

	int iResult = Dijkstra(vecNode, iNode1, iNode2);
	if (iResult != -1) {
		int iFirst = Dijkstra(vecNode, 1, iNode1);
		if (iFirst != -1) {
			int iFristNext = Dijkstra(vecNode, iNode2, iNodeCnt);
			iFirst = iFristNext != -1 ? iFirst + iFristNext : -1;
		}

		int iSecond = Dijkstra(vecNode, 1, iNode2);
		if (iSecond != -1) {
			int iSecondNext = Dijkstra(vecNode, iNode1, iNodeCnt);
			iSecond = iSecondNext != -1 ? iSecond + iSecondNext : -1;
		}

		if (iFirst == -1) {
			iResult = iSecond != -1 ? iResult + iSecond : -1;
		}
		else {
			if (iSecond == -1) {
				iResult += iFirst;
			}
			else {
				iResult += iFirst < iSecond ? iFirst : iSecond;
			}
		}
	}

	cout << iResult << endl;
	return 0;
}