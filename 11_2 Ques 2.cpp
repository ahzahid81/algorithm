#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int visited[N];
vector <int> adj_list[N];
int level[N];

void bfs(int src)
{
    queue <int> q;
    visited[src] = 1;
    q.push(src);
    level[src] = 0;
    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        for(int adj_node: adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main ()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src;
    cout <<"\nEnter The source node:";
    cin >> src;

    bfs(src);

    for(int i=0; i<nodes; i++)
    {
        cout <<"node " << i <<" -> level: " <<level[i] <<"\n";
    }

    return 0;
}