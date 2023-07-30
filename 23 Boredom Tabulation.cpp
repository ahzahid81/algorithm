// Tabulation
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long dp[N], arr[N];

long long boredom(long long num) {
  dp[0] = 0;
  dp[1] = dp[1];

  for(int i = 2; i <= num; i++) {
    dp[i] = max(dp[i-1], dp[i-2]+(i*dp[i]));
  }
  
  return dp[num];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  long long n, mx=0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin>>arr[i];
    dp[arr[i]]++;
    mx = max(mx, arr[i]);
  }

  cout << boredom(mx);

  return 0;
}