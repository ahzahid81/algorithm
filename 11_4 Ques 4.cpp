#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adj_list[N];
int colors[N];
int nodes, edges;

bool isBipartite(int start) {
    queue<int> q;
    q.push(start);
    colors[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int adj_node : adj_list[node]) {
            if (colors[adj_node] == -1) {
                colors[adj_node] = 1 - colors[node];
                q.push(adj_node);
            } else if (colors[adj_node] == colors[node]) {
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite() {
    for (int i = 0; i < nodes; ++i) {
        if (colors[i] == -1) {
            if (!isBipartite(i))
                return false;
        }
    }

    return true;
}

int main() {
    cin >> nodes >> edges;

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 0; i < nodes; ++i) {
        colors[i] = -1; // Initialize colors to -1 (unvisited)
    }

    if (checkBipartite()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}