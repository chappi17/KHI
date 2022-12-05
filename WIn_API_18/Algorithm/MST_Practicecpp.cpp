#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct KruskalEdge // 간선
{
	int cost; // 가중치
	int u; // 시작점
	int v; // 도착점

	bool operator<(const KruskalEdge& edge) const
	{
		if (cost < edge.cost)
		{
			return true;
		}
		else
		{
			return false; // 간선을 비교할때 가중치를 보겠다
		}
	}
};

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

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<KruskalEdge> selectEdges;
	selectEdges.clear();

	vector<KruskalEdge> edges;
	for (int i = 0; i < costs.size(); i++)
	{
			int cost = costs[i][2]; // 
			int u = costs[i][0];
			int v = costs[i][1];
				continue;

			edges.push_back({ cost,u,v }); // 간선들의 정보를 밀어 넣음 
	}

	std::sort(edges.begin(), edges.end()); //모든 간선들의 정보가 있고, cost가 작은게 앞에 오게 정렬 되어 있음.

	Disjoint sets(n);
	for (KruskalEdge& edge : edges)
	{
		if (sets.Find(edge.u) == sets.Find(edge.v)); // 시작 노드와 도착 노드가 같은 그룹이면 스킵 
		continue;

		// 시작노드와 도착노드가 서로 다른 그룹이면 Merge
		sets.Merge(edge.u, edge.v);
		selectEdges.push_back(edge);
		answer += edge.cost;
	}
	return answer;
}