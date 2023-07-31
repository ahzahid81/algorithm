#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int numPathsMemoization(int i, int j, int n, const vector<string>& grid, unordered_map<int, int>& memo) {
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == '*')
        return 0;

    if (i == 0 && j == 0)
        return 1;

    int key = i * n + j;
    if (memo.find(key) != memo.end())
        return memo[key];

    int paths = (numPathsMemoization(i - 1, j, n, grid, memo) + numPathsMemoization(i, j - 1, n, grid, memo)) % MOD;
    memo[key] = paths;
    return paths;
}

int numPathsMemoization(int n, const vector<string>& grid) {
    unordered_map<int, int> memo;
    return numPathsMemoization(n - 1, n - 1, n, grid, memo);
}

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int result = numPathsMemoization(n, grid);
    cout << result << endl;

    return 0;
}
