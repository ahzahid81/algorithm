// Memorization

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long dp[N], arr[N];

long long boredom(long long pd) {
  if(pd == 0)
    return 0;

  if( pd== 1)
    return dp[1];

  long long val1, val2;
  val1 = boredom(pd-2)+(pd*dp[pd]);
  val2 = boredom(pd-1);

  return max(val1, val2);
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