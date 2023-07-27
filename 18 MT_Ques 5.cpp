#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int dx[] = {-1, 0, 1, 0}; 
const int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<char>> building;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y) {
    if (!isValid(x, y) || visited[x][y] || building[x][y] == '#')
        return 0;

    visited[x][y] = true;
    int size = 1;

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        size += dfs(newX, newY);
    }

    return size;
}

int main() {
    cin >> n >> m;

    building.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> building[i][j];
        }
    }

    int room = 0;
    int longestRoom = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && building[i][j] == '.') {
                room++;
                int roomSize = dfs(i, j);
                longestRoom = max(longestRoom, roomSize);
            }
        }
    }

    cout << "Rooms - " << room << endl;
    cout << "Length of the longest room - " << longestRoom << endl;

    return 0;
}