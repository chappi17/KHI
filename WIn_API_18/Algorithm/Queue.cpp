#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

template<typename T, typename Container = deque<T>>
class Queue
{
public:
	void push(const T& value)
	{
		q.push_back(value);
	}
	
	void pop()
	{
		q.pop_front();
	}

	const T& front()
	{
		return q.front();
	}

	bool empty()
	{
		return q.size() == 0;
	}

	

public:
	Container q;
};

int main()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);		

	while (true)
	{
		if (q.empty() == true)
			break;

		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}