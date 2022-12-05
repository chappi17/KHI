#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

#include "BinarySearchTree.h"

using namespace std;

// ����Ʈ���� log2�� N 

class Player
{
public:
	//  < , > �������̵� �ϸ� ũ�� �� ����

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

	map<int, int> myMap; // key , (node �� data)
	// 2�� Ž�� Ʈ������ key ���� �ߺ� X 
	// �� ������ �������̵� �ϸ� �˾Ƽ� ũ�� �� ���� ������ 


	myMap[2] = 0;
	myMap[10] = 0;
	myMap[56] = 0;
	myMap[80] = 0;
	myMap[90] = 0;
	myMap[120] = 0;


	myMap.insert(make_pair<int, int>(100, 1));




	tree.PrintTree(tree._root); // ��Ʈ�� �߰������� ���;� �ϴµ�... �Ƹ� 2���� �־ 2�� ���õ� 
	// �������� ���� ������ 
	return 0;

}