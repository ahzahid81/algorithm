/*
Input --> a weighted graph and a source
Output --> distance of all nodes from the source

- create a distance array "d" 
- initialize all values of "d" to infinity
- d[src] = 0
- create a visited array and mark all nodes as unvisited


u -> v
d[u] + c(u, v) < d[v]:
    d[v] = d[u] + c(u,v)

for i = 0 to n-1
    - pick the "unvisited" one with shortest node d[node]
    - visited[node] = 1
    - for all adj_node of node:
        - if d[node] + c(node, adj_node) < d[adj_node]:
            - d[adj_node] = d[node] + c(node, adj_node)

- output array "d"


*/