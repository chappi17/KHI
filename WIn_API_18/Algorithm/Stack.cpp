#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Stack, Queue


// Stack
// 팬케이크 굽고 먹기: First Input Last Out -> FILO, LIFO

// Queue
// :줄 서기 : First Input First Out ->FIFO, LILO

// 기본 생성자 Player()
// 복사 생성사 Player(const Player& p) 
// 이동 생성사 Player(Player&& p) 

//	t.emplace_back(2); // 임시객체가 필요없음.

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