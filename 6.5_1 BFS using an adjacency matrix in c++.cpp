#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 100

void BFS(int graph[MAX_NODES][MAX_NODES], int numNodes, int stratNode)
{
    bool visited[MAX_NODES] = {false};
    int checkedCount[MAX_NODES] = {0};

    queue <int> q;
    q.push(stratNode);
    visited[stratNode] = true;

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        cout << "Checking node: " << currentNode << endl;
        checkedCount[currentNode]++;

        for(int i=0; i<numNodes; i++)
        {
            if(graph[currentNode][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main ()
{
    int graph[MAX_NODES][MAX_NODES] = {0};
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for(int i=0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int startNode = 0;
    BFS(graph, numNodes, startNode);

    return 0;
}