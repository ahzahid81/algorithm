#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int& volume)
{
    int n = grid.size();
    int m = grid[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
    {
        return;
    }

    volume += grid[i][j];
    grid[i][j] = 0; // Mark the cell as visited by setting its value to 0

    dfs(grid, i - 1, j, volume);
    dfs(grid, i + 1, j, volume);
    dfs(grid, i, j - 1, volume);
    dfs(grid, i, j + 1, volume);
}

int largest_lake_volume(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    int max_volume = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] > 0)
            {
                int lake_volume = 0;
                dfs(grid, i, j, lake_volume);
                max_volume = max(max_volume, lake_volume);
            }
        }
    }
    return max_volume;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int result = largest_lake_volume(grid);
        cout << result << endl;
    }
    return 0;
}
