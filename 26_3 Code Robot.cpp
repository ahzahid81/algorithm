#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];

int unique_path(int row, int column)
{
    if(row == 0 && column == 0)
    {
        return 1;
    }

    if(dp[row][column] != -1)
    {
        return dp[row][column];
    }

    int ans = 0;
    if(row > 0) ans +=unique_path(row-1, column);
    if(column>0) ans +=unique_path(row, column-1);
    dp[row][column] = ans;
    return ans;
}


int main ()
{
    int row, column;
    cin >> row >> column;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << unique_path(row-1, column-1) << endl;
    return 0;
}