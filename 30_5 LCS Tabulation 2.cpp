#include <bits/stdc++.h>
using namespace std;
const int N = 3003;

int dp[N][N];
int n, m;
string s, t;

int LCS(int i, int j)
{
    if(i==n || j==m)
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(s[i] == t[j])
    {
        int ans = 1 + LCS(i+1, j+1);
        dp[i][j] = ans;
        return ans;
    }

    int ans = max(LCS(i+1, j), LCS(i, j+1));
    dp[i][j] = ans;
    return ans;
}

int main ()
{
    
    cin >> s >> t;

    n = s.size();
    m = t.size();

    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }

    for(int j = 0; j<=n; j++)
    {
        dp[0][j] = 0;
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j]  = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}