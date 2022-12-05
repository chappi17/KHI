#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node(key);

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}
	Node* node = _root;
	Node* parent = nullptr;

	// 새로 노드 넣을 자리 찾기
	while (true)
	{
		// 깊이 끝까지 갔는데 노드가 없을때
		if (node == nullptr)
			break;
		parent = node; // 노드 하나 위에 잇는 것 지정 
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BinarySearchTree::PrintTree(Node* root)
{
	// 3가지 순회방법
	// 전위순회 : 루트부터 순회
	// 중위순회 : 왼쪽 아래부터 ~ 루트 ~ 오른쪽 아래까지
	// 후위순회 : 루트가 마지막 

	if (root == nullptr)
		return;
	cout << root->key << endl;
	PrintTree(root->left);
	PrintTree(root->right);
}

Node* BinarySearchTree::Search(Node* root, int key)
{
	//if (root == nullptr || root->key == key)
	//	return root;

	//if (key < root->key)
	//{
	//	root = root->left;
	//	return Search(root, key);
	//}
	//else
	//{
	//	root = root->right;
	//	return Search(root, key);
	//}

	if (root == nullptr)
		return root;


	// 구하기
	if (root->key == key)
		return root;

	if (root->key > key)
	{
		return Search(root->left, key);
	}

	else
	{
		return Search(root->right, key);
	}
}

Node* BinarySearchTree::Min(Node* root)
{
	/*if (root == nullptr)
		return root;

	if (root->left == nullptr)
		return root;

	return Min(root->left);*/

	if (root == nullptr)
		return nullptr;

	Node* node = root;
	while (true)
	{
		if (node->left == nullptr)
			return node;
		node = node->left;
	}


}

Node* BinarySearchTree::Max(Node* root)
{
	//if (root == nullptr)
	//	return root;

	//if (root->right == nullptr)
	//	return root;

	//return Max(root->right);

	// 첫 예외처리 
	if (root == nullptr)
		return nullptr;
	// 기저사항 -> 더 이상 쪼개질수 없는 작업 
	if (root->right == nullptr)
		return root;
		return Max(root->right);
	
	

}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
		RePlace(node, node->right);
	else if (node->right == nullptr)
		RePlace(node, node->left);
	else
	{
		Node* prev = Previous(node);
		node->key = prev->key;
		Delete(prev);
	}
}

Node* BinarySearchTree::Previous(Node* node)
{
	if(node == nullptr)
	return node;

	if (node->left != nullptr)
	{
		Node* prev = Max(node->left);
		if (prev == nullptr)
			return node->left;
		else
			return prev;
	}

	Node* parent = node->parent;

	while (parent != nullptr && node == parent->left)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BinarySearchTree::RePlace(Node* node1, Node* node2)
{
	// node1이 루트노드일 때
	if (node1->parent == nullptr)
		_root = node2;

	// node1이 부모쪽에서 left에 있는 경우
	else if (node1 == node1->parent->left)
	{
		node1->parent->left = node2;
	}

	// node1이 부모쪽에서 right
	else
	{
		node1->parent->right = node2;
	}

	if (node2)
		node2->parent = node1->parent;

	delete node1;
}
