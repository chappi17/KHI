#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

#include "BinarySearchTree.h"

using namespace std;

// Disjoint : ���μ� : �������� ���� ���� 
// Set : ����

// �׷���, Ʈ�� ����
// �ּ� ���д� Ʈ��(�ּ� ���� Ʈ��)
// -> �ּ� ���� �κ� �׷���
// -> ������ ���� ���� ����
// -> * ������ ���� n-1 ��
// -> ** ��� �������� ���� �Ǿ��־�� �� 
// -> *** ����Ŭ�� �����ϸ� �ȵȴ�. (��ȯ�ϸ� �ȵ�)
// ���ٷ� 

// ���ý���
// ���� 1000��

struct User
{
	int guild_id;
};


void GuilSystem()
{
	vector<User> users;
	users.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		users.push_back(User({ i })); // id ���� 
	}
	// ���μ� ����
	// 1���̶� 5���̶� ���� ���
	users[1].guild_id = users[5].guild_id; 
	// [0] [1] [2] [3] [4] [5]
	// 0	5	2	3	4	5

	// guild�� 2�� �ֶ� 5�� �ֶ� ���� 

	for (auto& user : users)
	{
		if (user.guild_id == 2)
			user.guild_id = 5;
	}
	// union ����
	// [0] [1] [2] [3] [4] [5]
	// 0	5	5	3	4	5

	// N�� ° ���̸� ã�� �ʹ�. -> ��� 
	// ��� ���� -> ������ Ȯ���ϸ鼭 ���� �ؾ� �ϴϱ� N �� �ɸ� -> 0(N)

}

// Ʈ�������� �̿��� ���μ� ����
// ������ �� union ��Ű�°��� �ƴ϶� �������� union ��Ű��


// [1] ...     [3]
// [5] ... [2] [4]
//			   [0]

class Disjoint
{
public:
	Disjoint(int n)
		: _parent(n) // n�� ��ŭ �����.
		, _rank(n,1) // ���� 
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
		// [0][1][2][3][4][5]
		//  0	1	2 3 4 5  P
		//  1	1	1 1 1 1  R
		// Merge(0,1)
		// [1] [2] [3] [4] [5]
		// [0]

		// Merge(1,2)
		// [1]		[3] [4] [5]
		// [0][2]
		
		// Merge(5,4)
		// Merge(5,3)
		// [1]		[4]
		// [0][2]	[3][5]

		// Merge(1,4)
		// [4]
		// [1]		[3][5]
		// [0][2]
		
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
	Disjoint nds(6);
	// [0][1][2][3][4][5]
	//  0	1	2 3 4 5 
	nds.Merge(2, 0); // ù���� �ְ� ���׸��� �� 
	// [0][1][2][3][4][5]
	//  0	1	0 3 4 5 
	nds.Merge(0, 1); // ù���� �ְ� ���׸��� �� 
	return 0;
}