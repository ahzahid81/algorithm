// Memorization

#include <bits/stdc++.h>
using namespace std;

const int N = 31;
int dp[N];

class Solution {
public:
    int f(int n) {
      if(n==0)
        return 0;
      else if(n<=2)
        return 1;

      if(dp[n] > 0)
        return dp[n];

      return dp[n] = f(n-1) + f(n-2);
    }
};

int main ()
{
    Solution s;
    cout << s.f(8) <<"\n";
}