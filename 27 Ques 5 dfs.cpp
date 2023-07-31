// DFS
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int dx[] = {-1, -1, -1, 0, 0,  1, 1,  1};
const int dy[] = {-1,  0,  1, 1, -1, 1, 0, -1};
int visited[N][N];
int n;
pair<int , int> a, b, c;

bool is_inside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y];
}

bool is_sameRow(int x)
{
    return x == a.first;
}

bool is_sameCol(int y)
{
    return y == a.second;
}

bool is_sameDiagram(int x, int y)
{
    return abs(x - a.first) == abs(y - a.second);
}

bool dfs(int x, int y)
{
    if (x == c.first && y == c.second)
        return true;

    visited[x][y] = 1;

    for (int k = 0; k < 8; k++)
    {
        int new_x = x + dx[k];
        int new_y = y + dy[k];

        if (is_inside(new_x, new_y) && !is_sameRow(new_x) && !is_sameCol(new_y) && !is_sameDiagram(new_x, new_y))
        {
            if (dfs(new_x, new_y))
                return true;
        }
    }

    return false;
}

int main()
{
    cin >> n;

    cin >> a.first >> a.second;
    a.first--;
    a.second--;

    cin >> b.first >> b.second;
    b.first--;
    b.second--;

    cin >> c.first >> c.second;
    c.first--;
    c.second--;

    if (dfs(b.first, b.second))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    return 0;
}
