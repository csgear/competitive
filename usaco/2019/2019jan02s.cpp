// https://usaco.org/index.php?page=viewproblem2&cpid=895
// USACO 2019 January Contest, Silver
// Problem 2. Icy Perimeter

#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n;
vector<string> grid;
vector<vector<bool>> visited;

pair<int, int> bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    int area = 0, peri = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        area++;
        for (int dir = 0; dir < 4; dir++) {
            int x1 = x + dx[dir];
            int y1 = y + dy[dir];
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) {
                peri++;
            } else if (grid[x1][y1] == '.') {
                peri++;
            } else if (grid[x1][y1] == '#' && !visited[x1][y1]) {
                q.push({x1, y1});
                visited[x1][y1] = true;
            }
        }
    }
    return {area, peri};
}

int main() {
    cin >> n;
    grid.resize(n);
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == '#') {
                ans.push_back(bfs(i, j));
            }
        }
    }

    sort(ans.begin(), ans.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    cout << ans[0].first << " " << ans[0].second << endl;
    return 0;
}