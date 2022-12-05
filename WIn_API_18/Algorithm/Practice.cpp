#include <string>
#include <vector>

using namespace std;
    int answer = 0;

    void DFS(vector<int>& numbers, int target, int index, int sum) // ���� �˰��־�� �� 
    {
        // ���� ���
        // �ε����� ���鼭 numbers�� ����� �ʰ��ϸ� �ȵ�
        if (index >= numbers.size())
        {
            // �´� �����̸�, ���̵Ǵ� ��� ++
            if (sum == target)
            {
                answer++;
            }
            return;
        }
        
        // ���ϱ� 
        DFS(numbers, target, index + 1, sum + numbers[index]); 
        DFS(numbers, target, index + 1, sum - numbers[index]);
    }
    
int solution(vector<int> numbers, int target) {
    // ����Ʈ���� ���� �����ϸ� �Ǵ� ��������...

    DFS(numbers, target, 0, 0);
    
    return answer;
}