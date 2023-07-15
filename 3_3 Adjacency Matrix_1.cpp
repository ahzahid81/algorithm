/*
Graph Representation
===================

Topic: Adjacency Matrix -> 2D Array

0 ---- 1
      / \
    2 ----3

# total nodes = 4
# total edge = 4
# Undirected + Unweighted

matrix -> #of nodes X #of nodes
    -> 4 x 4
matrix [i][j] = 1
    if and only if ( i -> j)

0 <===> 1
0 <===> 2
0 <===> 3
1 <===> 2
1 <===> 3
2 <===> 3


========
Space Complexity: O(n^2)
Time Complexity : O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int nodes = 4;

    int matrix[nodes][nodes] = {};

    for(int i=0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            matrix[i][j] = 1;


    /*
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[3][2] = 1;
    matrix[3][1] = 1;
    matrix[1][3] = 1;
    */



   /*  for(int i=0; i<nodes; i++)
    {
        for(int j =0; j<nodes; j++)
        {
            matrix[i][j] = 0;
        }
    } */

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            cout << matrix[i][j] <<" ";
        }
        cout <<"\n";
    }

}
