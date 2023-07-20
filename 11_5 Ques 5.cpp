#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adj_list[N];
int visited[N];
int nodes, edges;

void dfs(int node) {
    visited[node] = 1;

    for (int adj_node : adj_list[node]) {
        if (visited[adj_node]==0) {
            dfs(adj_node);
        }
    }
}

int countConnectedComponents() {
    int count = 0;
    for (int i = 0; i < nodes; ++i) {
        if (visited[i]==0) {
            dfs(i);
            ++count;
        }
    }
    return count;
}

int main() {
    cin >> nodes >> edges;

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // Since it's an undirected graph
    }


    int connectedComponents = countConnectedComponents();
    cout << connectedComponents << endl;

    return 0;
}
