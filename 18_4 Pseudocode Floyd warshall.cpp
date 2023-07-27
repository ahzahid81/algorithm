// Pseudocode: Floyd-warshall
/*
Input -> A weighted graph as an adjancency matrix
output -> All pair shortest distance

- create a distance_matrix "d" where d[i][j] = x where there is a direct edge form "i" to node "j" and the cost is "x"

- for all node "i" d[i][j] = 0
- for all nodes "i" & "j" where there isn't any direct edge form "i" to "j",
    d[i][j] = INF


- for all node "k" -> O(v)
    - for all node "u" -> O(V)
        - for all node "v" -> O(V)
            - d[u][v] = min(d[u][v], d[u][k] + d[k][v])

- output all pair shortest distance "d"
*/