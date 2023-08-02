#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_X = 1e6;
const int MAX_N = 100;

int ways[MAX_X + 1];
int coinsValue[MAX_N];

int main() {
    int n, target;
    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        cin >> coinsValue[i];
    }

    ways[0] = 1;

    for (int sum = 1; sum <= target; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum >= coinsValue[i]) {
                ways[sum] += ways[sum - coinsValue[i]];
                ways[sum] %= MOD;
            }
        }
    }

    cout << ways[target] << endl;

    return 0;
}