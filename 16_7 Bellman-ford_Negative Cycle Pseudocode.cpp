/*

n -> number of nodes in graph
e -> number of edges in graph

Time Complexity: O(n^2)
Space Complexity: O(n+e)


// Psecdocode: Bellman-ford

Input --> A weighted graph & src node (with no negative cycles)
Output --> Shortest distance from src node to all other nodes

-- create a distance array "d" with all values to infinity
- d[src] = 0;

- negative_cycle = false

d[u] + c(u, v) < d[v]
==> d[v] = d[u] + c(u,v)

for i = 1 to n:
    for all edge e(u,v,w) 
        -if d[u]+ w < d[v]:
                d[v] = d[u] + w
                if i == 1

- print whether negative cycle exits
- print the distance array "d"
*/