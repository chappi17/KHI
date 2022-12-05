#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct KruskalEdge // ����
{
	int cost; // ����ġ
	int u; // ������
	int v; // ������

	bool operator<(const KruskalEdge& edge) const
	{
		if (cost < edge.cost)
		{
			return true;
		}
		else
		{
			return false; // ������ ���Ҷ� ����ġ�� ���ڴ�
		}
	}
};

class Disjoint
{
public:
	Disjoint(int n)
		: _parent(n) // n�� ��ŭ �����.
		, _rank(n, 1) // ���� 
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}
	// ���� �ְ� ������ �������� ����
	int Find(int u)
	{
		// ���� ���
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

			edges.push_back({ cost,u,v }); // �������� ������ �о� ���� 
	}

	std::sort(edges.begin(), edges.end()); //��� �������� ������ �ְ�, cost�� ������ �տ� ���� ���� �Ǿ� ����.

	Disjoint sets(n);
	for (KruskalEdge& edge : edges)
	{
		if (sets.Find(edge.u) == sets.Find(edge.v)); // ���� ���� ���� ��尡 ���� �׷��̸� ��ŵ 
		continue;

		// ���۳��� ������尡 ���� �ٸ� �׷��̸� Merge
		sets.Merge(edge.u, edge.v);
		selectEdges.push_back(edge);
		answer += edge.cost;
	}
	return answer;
}