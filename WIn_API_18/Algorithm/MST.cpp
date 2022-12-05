#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

vector<vector<int>> adjacent;
vector<bool> discovered;
vector<int> parent;

// MST : 최소 신장 (스패닝) 트리 
// 1. 노드가 n개일떄, 간선의 개수는 n-1개
// 2. 사이클이 없어야한다.
// 3. 모든 노드를 방문해야 한다.

// Kruskal Algorithm
//-> 최소 스패닝 트리 찾기.
//-> 탐욕법(greedy algorithm)

// 탐욕법
// 각 부분마다 현재 최선의 선택을 찾아서 답을 구하는것.

struct KruskalEdge // 간선
{
	int cost; // 가중치
	int u; // 시작점
	int v; // 도착점

	bool operator<(const KruskalEdge& edge) const
	{
		if (cost < edge.cost)
			return true;
		return false; // 간선을 비교할때 가중치를 보겠다
	}
};



int Kruskal(vector<KruskalEdge>& selectEdges)
{
	int result = 0;

	selectEdges.clear();

	vector<KruskalEdge> edges;
	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent[u].size(); v++)
		{
			if (u > v)
				continue; // 최적화

			int cost = adjacent[u][v]; // 
			if (cost == -1)
				continue;

			edges.push_back({ cost,u,v }); // 간선들의 정보를 밀어 넣음 
		}
	}

	std::sort(edges.begin(), edges.end()); //모든 간선들의 정보가 있고, cost가 작은게 앞에 오게 정렬 되어 있음.

	Disjoint sets(adjacent.size());

	for (KruskalEdge& edge : edges)
	{
		if (sets.Find(edge.u) == sets.Find(edge.v)); // 시작 노드와 도착 노드가 같은 그룹이면 스킵 
		continue;

		// 시작노드와 도착노드가 서로 다른 그룹이면 Merge
		sets.Merge(edge.u, edge.v);
		selectEdges.push_back(edge);
		result += edge.cost;
	}
	return result;

}

void CreateGraph()
{
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	discovered = vector<bool>(6, false);
	parent = vector<int>(6, -1);

	adjacent[0][1] = 2;
	adjacent[0][2] = 10;
	adjacent[0][4] = 5;

	adjacent[1][0] = 2;
	adjacent[1][2] = 3;

	adjacent[2][0] = 10;
	adjacent[2][1] = 3;
	adjacent[2][3] = 4;
	adjacent[2][5] = 5;

	adjacent[3][2] = 4;

	adjacent[4][0] = 5;

	adjacent[5][2] = 5;
}

class Disjoint
{
public:
	Disjoint(int n)
		: _parent(n) // n개 만큼 만든다.
		, _rank(n, 1) // 깊이 
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}
	// 너의 최고 대장이 누구인지 묻기
	int Find(int u)
	{
		// 기저 사례
		if (u == _parent[u])
			return u;

		int parent = _parent[u];
		return Find(parent);
	}

	void Merge(int u, int v)
	{
		int uLeader = Find(u);
		int vLeader = Find(v);

		if (vLeader == uLeader)
			return;


		if (_rank[uLeader] > _rank[vLeader])
			std::swap(uLeader, vLeader);

		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;
	}
private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{
	CreateGraph();

	vector<KruskalEdge> mst; // 최소 신장트리 
	int sum = Kruskal(mst);
	cout << sum << endl;

	// mst에 최소 신장 트리 담겨있음 
	return 0;
}