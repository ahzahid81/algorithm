#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];


int main ()
{
    int row, column;
    cin >> row >> column;

    dp[0][0] = 1;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(i==0 && j==0)
            {
                continue;
            }

            int ans = 0;
            if(i>0) ans += dp[i-1][j];
            if(j>0) ans += dp[i][j-1];
            dp[i][j] = ans;
        }
    }

    

    cout << dp[row-1][column-1]<< endl;
    return 0;
}