#include <bits/stdc++.h>
using namespace std;

const int N = 1002;

bool visited[N][N]; 
int level[N][N];
char maze[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char moves[] = {'U', 'D', 'L', 'R'};
string path;

bool is_inside(int x, int y)
{
    return (x>=0 && x<n && y>=0 && y<m);
}

bool is_safe(int x, int y)
{
    return(is_inside(x,y) && maze[x][y] == '.' && !visited[x][y]);
}

void bfs(pair <int, int> src)
{
    queue<pair<int,int>> q;
    visited[src.first][src.second] = true;
    level[src.first][src.second] = 0;

    q.push(src);

    while(!q.empty())
    {
        pair <int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            pair<int,int> adj_node = {nx, ny};

            if(is_safe(nx,ny))
            {
                visited[nx][ny] = true;
                level[nx][ny] = level[x][y] + 1;
                q.push(adj_node);

                if(nx ==0 || nx == n-1 || ny ==0 || ny == m-1)
                {
                    while(nx!=src.first || ny !=src.second)
                    {
                        int px = nx-dx[i];
                        int py = ny-dy[i];

                        for(int j=0; j<4; j++)
                        {
                            if(nx+dx[j] == px && ny + dy[j] == py)
                            {
                                path += moves[j];
                                break;
                            }
                        }
                        nx = px;
                        ny = py;
                    }

                    reverse(path.begin(), path.end());
                    return;
                }
            }

            
        }

    }

}

int main ()
{
    cin >> n >> m;
    pair <int, int> src;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'A')
            {
                src = {i,j};
            }
        }
    }
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    path = "";

    if(path.empty())
    {
        cout<<"NO\n";
    }
    else
    {
        cout <<"YES\n";
        cout << path.size() <<"\n";
        cout << path <<"\n";
    }

    return 0;
}