#include<vector>
#include<queue>

using namespace std;

struct Vector2
{
    int x;
    int y;
    Vector2(int _y, int _x) { y = _y, x = _x; }
};

int solution(vector<vector<int> > maps)
{
    const int n = maps.size();
    const int m = maps[0].size();

    int DirY[4] = { -1,0,1,0 };
    int DirX[4] = { 0,1,0,-1 };

    vector<vector<bool>> check(n, vector<bool>(m));
    vector<vector<int>> distance(n, vector<int>(m));
    queue<Vector2> q;

    q.push(Vector2(0, 0));
    check[0][0] = true;
    distance[0][0] = 1;

    while (!q.empty())
    {
        Vector2 pos = q.front();
        q.pop();
        int hereY = pos.y;
        int hereX = pos.x;

        for (int i = 0; i < 4; i++)
        {
            int nextY = hereY + DirY[i];
            int nextX = hereX + DirX[i];

            if (nextY < 0 || nextY >= n || nextX >= m)
                continue;
            if (maps[nextY][nextX] == 0)
                continue;
            if (check[nextY][nextX])
                continue;

            q.push(Vector2(nextY, nextX));
            check[nextY][nextX] = true;
            distance[nextY][nextX] = distance[hereX][hereY] + 1;
        }

        if (!check[n - 1][m - 1])
            return -1;
        else
            return distance[n - 1][m - 1];

    }
}