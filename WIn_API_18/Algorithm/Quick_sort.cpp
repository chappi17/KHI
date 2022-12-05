#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// Quick Sort
// 기준(Pivot)을 정하고,
// 기준의 왼쪽을 무조건 나보다 작게
// 기준의 오른쪽은 무조건 나보다 크게
// 단점 -> 같은 값이면 자리가 불안정하다. 

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left]; // 기준 잡기 
	int lowIndex = left + 1;
	int highIndex = right;

	while (true)
	{
		if (lowIndex > highIndex)
			break;

		// 왼쪽에서 부터 올라감
		while (lowIndex <= right && pivot >= v[lowIndex])
			lowIndex++;
		// 오른쪽에서부터 내려감
		while (highIndex >= left && pivot <= v[highIndex])
			highIndex--;

		// 역전되기 전이면 스왑 
		if (lowIndex < highIndex)
			swap(v[lowIndex], v[highIndex]);
	}

	swap(v[highIndex], v[left]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	// 기저 사례
	if (left > right)
		return;

	// 구하기
	int pivotIndex = Partition(v, left, right);
	cout << left << " ~ " << pivotIndex- 1 << endl;
	QuickSort(v, left, pivotIndex - 1);
	QuickSort(v, pivotIndex+1,right);
}

int main()
{
	vector<int> v = { 5,10,100,8,1,70,56,40 };

	QuickSort(v, 0, 7);


}
