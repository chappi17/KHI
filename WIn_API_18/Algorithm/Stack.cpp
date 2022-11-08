#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Stack, Queue


// Stack
// ������ũ ���� �Ա�: First Input Last Out -> FILO, LIFO

// Queue
// :�� ���� : First Input First Out ->FIFO, LILO

// �⺻ ������ Player()
// ���� ������ Player(const Player& p) 
// �̵� ������ Player(Player&& p) 

//	t.emplace_back(2); // �ӽð�ü�� �ʿ����.

class Stack
{
public:
	void push(const int& value)
	{
		v.push_back(value);
	}

	void pop()
	{
		v.pop_back();
	}

	const int& top()
	{
		return v.back();
	}

	bool empty()
	{
		return v.size() == 0;
	}
	
public:
	vector<int> v;
};


int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	

	while (true)
	{
		if (s.empty() == true)
			break;

		cout << s.top() << endl;
		s.pop();
	}



	return 0;
}