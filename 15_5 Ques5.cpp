#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector <int> adj_list[N];
int visited[N];

bool bfs(int n)
{
    queue <int> q;
    q.push(1);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        if(head == n)
        {
            return true;
        }

        for( int adj_nodes: adj_list[head])
        {
            if(visited[adj_nodes] ==0)
            {
                visited[adj_nodes] = 1;
                q.push(adj_nodes);
            }
        }
    }

    return false;
}


int main ()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i = 0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    if(bfs(nodes))
    {
        cout << "YES\n";
    }
    else
    {
        cout <<"NO\n";
    }

    return 0;
}