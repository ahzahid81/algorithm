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
                parent[v] = u
                if i == n
                negative_cycle = true;
                last_updated_node = v;

- print whether negative cycle exitsts

- if negative_cycle = false:
    - print the distance array "d"
    - selected_node = destination_node
    - declate a vector path
    - while true:
        - path.push_back(selected_node)

        - if selected_node == src:
            break;
        - selected_node = parent[selected_node];
    
    - reverse the vector path
    - print the path

- else
    - print negative cycle exists
    - selected_node = last_updated_node

    for i = 1 to n-1
        - selected_node = parent[selected_node]
    
    - declare a vector "cycle"
    - cycle.push_back(selected_node)
    - while true:
        - selected_node = parent[selected_node]
        - cycle.push_back(selected_node)
        - if selected_node = last_updated_node:
            - break;
        - reverse the "cycle" vector
        - print the path


- print the distance array "d"
*/