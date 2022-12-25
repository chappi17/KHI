//class Disjoint
//{
//public:
//	Disjoint(int n)
//		: _parent(n) // n�� ��ŭ �����.
//		, _rank(n, 1) // ���� 
//	{
//		for (int i = 0; i < n; i++)
//		{
//			_parent[i] = i;
//		}
//	}
//	// ���� �ְ� ������ �������� ����
//	int Find(int u)
//	{
//		// ���� ���
//		if (u == _parent[u])
//			return u;
//
//		int parent = _parent[u];
//		return Find(parent);
//	}
//
//	void Merge(int u, int v)
//	{
//		int uLeader = Find(u);
//		int vLeader = Find(v);
//
//		if (vLeader == uLeader)
//			return;
//
//		if (_rank[uLeader] > _rank[vLeader])
//			std::swap(uLeader, vLeader);
//
//		_parent[uLeader] = vLeader;
//
//		if (_rank[uLeader] == _rank[vLeader])
//			_rank[vLeader]++;
//	}
//
//private:
//	vector<int> _parent;
//	vector<int> _rank;
//};