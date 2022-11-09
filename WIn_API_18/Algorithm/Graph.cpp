#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

struct Vertex
{
	int _data;
};

vector<vector<int>> adjacent; // 인접
vector<vector<bool>> adjacent2;
vector<bool> visited;

// 그래프
// 0 : 1 2 4
// 1 : 0 2
// 2 : 0 1 3 5
// 3 : 2
// 4 : 0
// 5 : 2

void CreateGraph() // 인접리스트 
{
	adjacent = vector<vector<int>>(6);

	adjacent[0].push_back(1);
	adjacent[0].push_back(2);
	adjacent[0].push_back(4);

	adjacent[1].push_back(0);
	adjacent[1].push_back(2);

	adjacent[2].push_back(0);
	adjacent[2].push_back(1);
	adjacent[2].push_back(3);
	adjacent[2].push_back(5);

	adjacent[3].push_back(2);

	adjacent[4].push_back(0);

	adjacent[5].push_back(2);

	for (auto& vertex : adjacent[0])
	{
		if (vertex == 2)
		{
			cout << "0번 vertex 와 2번 vertex가 이어져 있습니다" << endl;
			break;
		}
	}
	// 메모리는 덜 쓰지만 속도가 느리다. 
}

void CreateGraph2()
{
	adjacent2 = vector<vector<bool>>(6, vector<bool>(6, false));
	visited = vector<bool>(6, false);

//    [0][1][2][3][4][5]
// [0] 0  1  1  0  1  0
// [1] 1  0  1  0  0  0
// [2] 1  1  0  1  0  1
// [3] 0  0  1  0  0  0
// [4] 1  0  0  0  0  0
// [5] 0  0  1  0  0  0

	adjacent2[0][1] = true;
	adjacent2[0][2] = true;
	adjacent2[0][4] = true;

	adjacent2[1][0] = true;
	adjacent2[1][2] = true;

	adjacent2[2][0] = true;
	adjacent2[2][1] = true;
	adjacent2[2][3] = true;
	adjacent2[2][5] = true;

	adjacent2[3][2] = true;

	adjacent2[4][0] = true;

	adjacent2[5][2] = true;

	if (adjacent2[2][5] == true)
		cout << "연결되었습니다" << endl;
	// 메모리를 좀 쓰더라도 속도가 빠르다 
}

void DFS(int start)
{
	visited[start] = true;

	int next;
	for (int i = 0; i < adjacent2.size(); i++)
	{
		if (adjacent2[start][i] == true)
		{
			if (visited[i] == true) // 방문한 곳인가? 
			continue;
			next = i;
			DFS(next);
		}
	}
}

void DFS_ALL()
{
	int count = 0; // 뭉탱이 개수 //연결 되어있는 노드의 뭉탱이

	for (int i = 0; i < adjacent2.size(); i++)
	{
		if (visited[i] == false)
		{
			count++;
			DFS(i);
		}
	}

	cout << "뭉탱이 개수 :" << count << endl;
}


int main()
{
//	CreateGraph();
	CreateGraph2();
//	DFS(0);
	//if (visited[5] == true)
//	cout << "5는 0과 연결이 되어있습니다. " << endl;
	//else
//	cout << "5는 0과 연결이 안되어있습니다." << endl;


	DFS_ALL();

	return 0;
}

// 어떤식으로 탐색을 들어가야 하는지 생각하는게 중요
// 연결하는걸 모두 탐색가능한건지 