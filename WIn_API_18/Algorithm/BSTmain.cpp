#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

#include "BinarySearchTree.h"

using namespace std;

// 이진트리는 log2의 N 

class Player
{
public:
	//  < , > 오버라이딩 하면 크기 비교 가능

	int _id;
	int _hp;
};


int main()
{
	BinarySearchTree tree;

	tree.Insert(56);
	tree.Insert(90);
	tree.Insert(80);
	tree.Insert(10);
	tree.Insert(2);
	tree.Insert(120);

	tree.Search(tree._root,90);
	tree.Min(tree._root)->key;
	tree.Max(tree._root)->key;

	map<int, int> myMap; // key , (node 의 data)
	// 2진 탐색 트리에서 key 값은 중복 X 
	// 비교 연산자 오버라이딩 하면 알아서 크기 비교 정렬 가능함 


	myMap[2] = 0;
	myMap[10] = 0;
	myMap[56] = 0;
	myMap[80] = 0;
	myMap[90] = 0;
	myMap[120] = 0;


	myMap.insert(make_pair<int, int>(100, 1));




	tree.PrintTree(tree._root); // 루트는 중간에꺼가 나와야 하는데... 아마 2부터 넣어서 2로 나올듯 
	// 수동으로 순서 맞췄음 
	return 0;

}