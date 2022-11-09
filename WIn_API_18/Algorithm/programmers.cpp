#include <string>
#include <vector>

using namespace std;
bool visited[200];

void DFS(int n, vector<vector<int>> computers) {

    for (int i = 1; i < n; i++)
    {
        if (computers[n][i] == 1 && visited[i] == false)
            visited[i] = true;
        DFS(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            DFS(i, computers);
        answer++;
    }

    return answer;
}

int main()
{
    return 0;
}