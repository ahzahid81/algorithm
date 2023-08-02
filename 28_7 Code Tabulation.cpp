#include <bits/stdc++.h>
using namespace std;

const int N = 60;
const int M = 1001;
const int MOD = 100000007;
int coin[N], limit[N];

int dp[N][M];

int fun(int n, int k)
{
    if(n==0)
    {
        if(k==0) return 1;
        return 0;
    }

    if(dp[n][k] != -1)
    {
        return dp[n][k];
    }

    int ans = fun(n-1, k);

    for(int i=1; i<= limit[n]; i++)
    {
        if(k-i*coin[n] <0)
        {
            break;
        }
        int ret = fun(n-1, k-i*coin[n]);

        ans = (ans+ ret) % MOD;
    }
    dp[n][k] = ans;
    return ans;
}

int main ()
{
    int t, tst = 0;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        for(int i=1; i<=n; i++)
        {
            cin >> coin[i];
        }

        for(int i=1; i<=n; i++)
        {
            cin >> limit[i];
        }

        for(int i=0; i<=n; i++)
        {
            for(int target =0; target <=k; target++)
            {
                dp[i][target] = 0;
            }
        }


        dp[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int target = 0; target <=k; target++)
            {
                dp[i][target] = dp[i-1][target];

                for(int j=1; j<=limit[i]; j++)
                {
                    int ret = dp[i-1][target - j*coin[i]];
                    dp[i][target] = (dp[i][target] + ret) % MOD;
                }
            }
        }

        cout <<"Case" << ++tst <<" : "<< fun(n,k) << endl;
    }

    return 0;
}