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

// MST : �ּ� ���� (���д�) Ʈ�� 
// 1. ��尡 n���ϋ�, ������ ������ n-1��
// 2. ����Ŭ�� ������Ѵ�.
// 3. ��� ��带 �湮�ؾ� �Ѵ�.

// Kruskal Algorithm
//-> �ּ� ���д� Ʈ�� ã��.
//-> Ž���(greedy algorithm)

// Ž���
// �� �κи��� ���� �ּ��� ������ ã�Ƽ� ���� ���ϴ°�.

struct KruskalEdge // ����
{
	int cost; // ����ġ
	int u; // ������
	int v; // ������

	bool operator<(const KruskalEdge& edge) const
	{
		if (cost < edge.cost)
			return true;
		return false; // ������ ���Ҷ� ����ġ�� ���ڴ�
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
				continue; // ����ȭ

			int cost = adjacent[u][v]; // 
			if (cost == -1)
				continue;

			edges.push_back({ cost,u,v }); // �������� ������ �о� ���� 
		}
	}

	std::sort(edges.begin(), edges.end()); //��� �������� ������ �ְ�, cost�� ������ �տ� ���� ���� �Ǿ� ����.

	Disjoint sets(adjacent.size());

	for (KruskalEdge& edge : edges)
	{
		if (sets.Find(edge.u) == sets.Find(edge.v)); // ���� ���� ���� ��尡 ���� �׷��̸� ��ŵ 
		continue;

		// ���۳��� ������尡 ���� �ٸ� �׷��̸� Merge
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

int main()
{
	CreateGraph();

	vector<KruskalEdge> mst; // �ּ� ����Ʈ�� 
	int sum = Kruskal(mst);
	cout << sum << endl;

	// mst�� �ּ� ���� Ʈ�� ������� 
	return 0;
}