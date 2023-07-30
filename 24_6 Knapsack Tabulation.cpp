#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int M = 1e5+5;

long long dp[N][M];
int wt[N], val[N];

int main ()
{
    int n, W;
    cin >> n >> W;

    for(int i=1; i<=n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    for(int i=0; i<=W; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1; i<=n;i++)
    {
        for(int cap = 0; cap <=N; i++)
        {
            dp[i][cap] = max(val[i] + dp[i-1] -wt[i];
            )
        }
    }
}