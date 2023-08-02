#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> dist(n + 1, INF);

        for (const auto& loop : times) 
        {
            int u = loop[0];
            int v = loop[1];
            int w = loop[2];
            graph[u].emplace_back(v, w);
        }

        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) {
                continue;
            }

            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = *max_element(dist.begin() + 1, dist.end());
        return maxTime == INF ? -1 : maxTime;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n1 = 4, k1 = 2;
    cout << "Output: " << sol.networkDelayTime(times1, n1, k1) << endl;

    vector<vector<int>> times2 = {{1, 2, 1}};
    int n2 = 2, k2 = 1;
    cout << "Output: " << sol.networkDelayTime(times2, n2, k2) << endl;

    vector<vector<int>> times3 = {{1, 2, 1}};
    int n3 = 2, k3 = 2;
    cout << "Output: " << sol.networkDelayTime(times3, n3, k3) << endl; 

    return 0;
}
