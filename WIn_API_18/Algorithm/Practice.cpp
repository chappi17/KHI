#include <string>
#include <vector>

using namespace std;
    int answer = 0;

    void DFS(vector<int>& numbers, int target, int index, int sum) // 내용 알고있어야 함 
    {
        // 기저 사례
        // 인덱스가 돌면서 numbers의 사이즈를 초과하면 안됨
        if (index >= numbers.size())
        {
            // 맞는 조건이면, 답이되는 경우 ++
            if (sum == target)
            {
                answer++;
            }
            return;
        }
        
        // 구하기 
        DFS(numbers, target, index + 1, sum + numbers[index]); 
        DFS(numbers, target, index + 1, sum - numbers[index]);
    }
    
int solution(vector<int> numbers, int target) {
    // 이진트리로 만들어서 생각하면 되는 문제였다...

    DFS(numbers, target, 0, 0);
    
    return answer;
}