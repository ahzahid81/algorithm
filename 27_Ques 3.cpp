#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N];

int rob_helper(const vector<int>& nums, int start, int end) {
    int n = end - start + 1;
    if (n == 0) return 0;
    if (n == 1) return nums[start];

    if (dp[end] != -1) return dp[end];

    dp[end] = max(rob_helper(nums, start, end - 1),
                  rob_helper(nums, start, end - 2) + nums[end]);

    return dp[end];
}

int rob(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    memset(dp, -1, sizeof(dp));

    return max(rob_helper(nums, 1, n - 1), rob_helper(nums, 0, n - 2));
}

int main() {
    cout << rob({2, 3, 2}) << endl; 
    cout << rob({1, 2, 3, 1}) << endl; 
    cout << rob({1, 2, 3}) << endl; 

    return 0;
}