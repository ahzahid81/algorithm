// Tabulation

#include <bits/stdc++.h>
using namespace std;
const int N = 31;

int dp[N];
class Solution {
public:
    int fib(int n) {
        dp[0] = 0;
        dp[1] = 1;

        for(int i =2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n]; 
    }
};

int main ()
{
    Solution s;
    cout << s.fib(3) <<"\n";
}