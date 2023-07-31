#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[N];

int numSquare(int num)
{
    if(num <= 0)
    {
        return 0;
    }

    if(dp[num] != -1)
    {
        return dp[num];
    }

    int sqrt_num = sqrt(num);
    if(sqrt_num * sqrt_num == num)
    {
        dp[num] = 1;
        return 1;
    }


    int ans = INT_MAX;
    for(int i=1; i*i<=num; i++)
    {
        ans = min(ans, numSquare(num - i*i));
    }

    ans++;
    dp[num] = ans;
    return dp[num];
}

int main ()
{
    int num;
    cin >> num;

    for(int i =0; i<=num; i++)
    {
        dp[i] = -1;
    }

    cout << numSquare(num) <<"\n";
    return 0;
}