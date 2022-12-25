//class Disjoint
//{
//public:
//	Disjoint(int n)
//		: _parent(n) // n개 만큼 만든다.
//		, _rank(n, 1) // 깊이 
//	{
//		for (int i = 0; i < n; i++)
//		{
//			_parent[i] = i;
//		}
//	}
//	// 너의 최고 대장이 누구인지 묻기
//	int Find(int u)
//	{
//		// 기저 사례
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