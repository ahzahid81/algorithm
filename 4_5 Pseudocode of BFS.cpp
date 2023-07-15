/*
Pseudocode of BFS
================

Time Complexity:
Space Complexity:

Input -> Connected Graph and a "Source"
Output -> Traverse all nodes and print the traversal order

BFS(graph, source):
- Initiate an array called "visited" and an empty queue "q"
- mark visied[source] = 1 and q.push(source)
- while the queue is not empty:
    -head = q.front()
    -q.pop()
    - print the node "head"
    - for all adjacent nodes of "head":
        -if visited[adj_node] ==0;
            - visited [adj_node] = 1 and q.push(adj_node)


*/