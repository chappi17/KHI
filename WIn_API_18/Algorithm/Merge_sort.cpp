#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// MergeSort
// ���� ����(Divided And Conquer)
// ���� : ������ �� �ܼ��ϰ� �����Ѵ� 
// ���� : ������ �ذ��Ѵ�.
// ���� : ����� �����Ͽ� ������ �Ѵ�.

// Quick Sort, Merge Sort
// �־��� ��� : n^2
// ��������� n * log2n

// Partial Sort
// �־��� ��� : n^2
// ��������� n x log 2n - hip �Ҷ� ���´ٰ� �� 
// ���� m�� ��ŭ�� �����ҽ�, n * log2m

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIndex = left;
	int rightIndex = mid +1;

	vector<int> temp;

	while (leftIndex <= mid && rightIndex <= right)
	{	
		if (v[leftIndex] <= v[rightIndex])
		{
			if (v[leftIndex] <= v[rightIndex])
			{
				temp.push_back(v[leftIndex]);
				leftIndex++;
			}
			else
			{
				temp.push_back(v[rightIndex]);
				rightIndex++;
			}
		}
	}
	// ������ ���� ����
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	// ����
	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid+1, right);

	// ����, ���� 
	MergeResult(v, left, mid, right);

}

int main()
{
	vector<int> v = { 5,10,100,8,1,70,56,40 };
	MergeSort(v, 0, 7);


	return 0;
}