#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
	map <int, int> myMap; // 작은거부터 , 크게 하고 싶으면 greater 추가해주면 댐 
	unordered_map<int, int> myUmap; // 정렬이 안되어있는 map // 해쉬테이블로 연상하면 됨.

	// hash function 키가 있으면, % 쳐내서 넣겠다.
	// key 1001 , 체이닝 리스트. 해쉬 함수를 알면 모든 데이터 접근 가능
	// 뽑는 속도가 빠르다. 상수번 걸림.
	// 체이닝 함수라 여러번 걸릴수도 있음.

	myUmap[0] = 1; // insert 와 같다.
	myUmap[1] = 2;
	myUmap[4] = 5;
	myUmap[2] = 3;
	myUmap[3] = 4;

	for (auto& pair : myUmap)
	{
		cout << "Key : " << pair.first << "Value: " << pair.second << endl;
	}

	myMap[0] = 1;
	myMap[1] = 2;
	myMap[4] = 5;
	myMap[2] = 3;
	myMap[3] = 4;

	for (auto& pair : myMap)
	{
		cout << "Key : " << pair.first << "Value: " << pair.second << endl;
	}

	

	// myUmap.find() // key 찾는거 , iterator 반환
	// myUmap.at() // key 넣으면 value 나오는거 
	// myUmap[0] == at() 이랑 같다. index 접근



	return 0;
}