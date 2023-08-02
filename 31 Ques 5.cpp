#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_X = 1000;

bool dp[MAX_N + 1][MAX_N * MAX_X + 1];

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAX_N * MAX_X; j++) {
            dp[i][j] = dp[i - 1][j] || (j >= coins[i - 1] && dp[i - 1][j - coins[i - 1]]);
        }
    }

    int numSums = 0;
    vector<int> sums;
    for (int sum = 1; sum <= MAX_N * MAX_X; sum++) {
        if (dp[n][sum]) {
            numSums++;
            sums.push_back(sum);
        }
    }

    cout << numSums << endl;
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}