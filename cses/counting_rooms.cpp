// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, vector<string>& grid, vector<vector<bool>>& visited) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#' ||
        visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    dfs(i + 1, j, grid, visited);
    dfs(i - 1, j, grid, visited);
    dfs(i, j + 1, grid, visited);
    dfs(i, j - 1, grid, visited);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                rooms++;
                dfs(i, j, grid, visited);
            }
        }
    }
    cout << rooms << endl;
    return 0;
}
