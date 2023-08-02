#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAX_M = 1e9;
const int MAX_N = 101;

int ways[MAX_M +1];
int coins[MAX_N];

int main ()
{
    int n, t;
    cin >> n >> t;

    for(int i = 0; i <n; i++)
    {
        cin >> coins[i];
    }

    ways[0] = 1;

    for(int sum =1; sum<=t; sum++)
    {
        for(int i=0; i<n; i++)
        {
            if(sum >= coins[i])
            {
                ways[sum] += ways[sum - coins[i]];
                ways[sum] %= MOD;
            }
        }
    }

    cout << ways[t] << endl;

    return 0;

}