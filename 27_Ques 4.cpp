#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int numPaths(int n, const vector<string>& grid) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Start cell has one path to itself
    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;

    // Fill the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*')
                continue;

            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[n - 1][n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int result = numPaths(n, grid);
    cout << result << endl;

    return 0;
}
