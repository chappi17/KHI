#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// DP
// -�޸������̼�, ĳ��
// -�����κб���


// �Ǻ���ġ ����

int Fibonacci(int n)
{
	// ���� ���
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	// �޸������̼�
//	if (fAnswer[n] != -1)
	//
// 	return fAnswer[n];

	// ���ϱ�
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int cache[45][45];

int Combin(int n, int r)
{
	// ����
	if (r == 0 || n == r)
		return 1;

	// ĳ��
	if(cache[n][r] == -1) // ���� �� ���� ����� ��

	// ���ϱ�
	return Combin(n - 1, r - 1) + Combin(n - 1, r);

}


int main()
{
	cout << Fibonacci(4) << endl;

	cout << Combin(45, 6) << endl;

	return 0;
}