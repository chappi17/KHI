#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

#include "BinarySearchTree.h"

using namespace std;

// Disjoint : 서로소 : 교집합이 없는 집합 
// Set : 집합

// 그래프, 트리 응용
// 최소 스패닝 트리(최소 신장 트리)
// -> 최소 연결 부분 그래프
// -> 간선의 수가 가장 적다
// -> * 간선의 수는 n-1 개
// -> ** 모든 정점들이 연결 되어있어야 함 
// -> *** 사이클을 포함하면 안된다. (순환하면 안됨)
// 한줄로 

// 길드시스템
// 유저 1000명

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
		users.push_back(User({ i })); // id 배정 
	}
	// 서로소 과정
	// 1번이랑 5번이랑 같은 길드
	users[1].guild_id = users[5].guild_id; 
	// [0] [1] [2] [3] [4] [5]
	// 0	5	2	3	4	5

	// guild가 2인 애랑 5인 애랑 통합 

	for (auto& user : users)
	{
		if (user.guild_id == 2)
			user.guild_id = 5;
	}
	// union 과정
	// [0] [1] [2] [3] [4] [5]
	// 0	5	5	3	4	5

	// N번 째 아이를 찾고 싶다. -> 상수 
	// 길드 통합 -> 일일이 확인하면서 통합 해야 하니까 N 번 걸림 -> 0(N)

}

// 트리구조를 이용한 서로소 집합
// 일일이 다 union 시키는것이 아니라 최적으로 union 시키기


// [1] ...     [3]
// [5] ... [2] [4]
//			   [0]

class Disjoint
{
public:
	Disjoint(int n)
		: _parent(n) // n개 만큼 만든다.
		, _rank(n,1) // 깊이 
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
	nds.Merge(2, 0); // 첫번쨰 애가 수그리고 들어감 
	// [0][1][2][3][4][5]
	//  0	1	0 3 4 5 
	nds.Merge(0, 1); // 첫번쨰 애가 수그리고 들어감 
	return 0;
}