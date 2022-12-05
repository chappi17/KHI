#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// DP
// -메모이제이션, 캐시
// -최적부분구조


// 피보나치 수열

int Fibonacci(int n)
{
	// 기저 사례
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	// 메모이제이션
//	if (fAnswer[n] != -1)
	//
// 	return fAnswer[n];

	// 구하기
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int cache[45][45];

int Combin(int n, int r)
{
	// 기저
	if (r == 0 || n == r)
		return 1;

	// 캐시
	if(cache[n][r] == -1) // 있을 수 없는 경우의 수

	// 구하기
	return Combin(n - 1, r - 1) + Combin(n - 1, r);

}


int main()
{
	cout << Fibonacci(4) << endl;

	cout << Combin(45, 6) << endl;

	return 0;
}