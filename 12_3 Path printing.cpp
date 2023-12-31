 #include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> adj_list[N];
int visited[N];
int level[N];
int parent[N];

void bfs(int src)
{
    queue <int> q;
    visited[src] = 1;
    level[src] = 1;
    parent[src] = -1;
    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        for(int adj_node: adj_list[head])
        {
            if(!visited[adj_node])
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                parent[adj_node] = head;
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

    int src = 1;
    bfs(src);
    int dst = nodes;

    if(!visited[dst])
    {
        cout <<"IMPOSSIBLE\n";
    }
    cout << level[dst] <<"\n";
    vector  <int> path;
    int selected_node = dst;
    while(true)
    {
        path.push_back(selected_node);
        if(selected_node == 1)
        {
            break;
        }
        selected_node = parent[selected_node];
    }
    reverse(path.begin(), path.end());

    for(int i: path)
    {
        cout << i <<" ";
    }
    cout << "\n";

}
