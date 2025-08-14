#include <bits/stdc++.h>
using namespace std;

const int N = 7;
string s;
int vis[N + 2][N + 2] = {0};
int ans = 0;

// y is the row, x is the column, aligning with Cartesian coordinates
void dfs(int y, int x, int step) {
    if (vis[y][x]) return;

    if (y == N && x == 1) {
        if (step == N * N) ans++;
        return;
    }

    bool down = vis[y + 1][x];
    bool up = vis[y - 1][x];
    bool left = vis[y][x - 1];
    bool right = vis[y][x + 1];

    // Pruning optimization: if we create a "corridor" that splits the grid,
    // we'll never be able to visit all cells. Two cases:
    // 1. Vertical corridor: both up and down are blocked, but left and right are free
    //    This creates a vertical barrier we can't cross
    // 2. Horizontal corridor: both left and right are blocked, but up and down are free
    //    This creates a horizontal barrier we can't cross
    if (down && up && !left && !right) return;  // Vertical corridor
    if (!down && !up && left && right) return;  // Horizontal corridor

    char d = s[step - 1];
    vis[y][x] = 1;
    if (d == '?' || d == 'D') dfs(y + 1, x, step + 1);
    if (d == '?' || d == 'U') dfs(y - 1, x, step + 1);
    if (d == '?' || d == 'L') dfs(y, x - 1, step + 1);
    if (d == '?' || d == 'R') dfs(y, x + 1, step + 1);
    vis[y][x] = false;
}

int main() {
    cin >> s;
    // Set boundary to true
    for (int i = 0; i < N + 2; ++i) {
        vis[0][i] = vis[N + 1][i] = 1;
        vis[i][0] = vis[i][N + 1] = 1;
    }
    dfs(1, 1, 1);
    cout << ans << '\n';
}
