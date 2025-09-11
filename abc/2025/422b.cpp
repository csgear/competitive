// https://atcoder.jp/contests/abc422/tasks/abc422_b

#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int h, w;
vector<string> grid;

bool check(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == '#') {
            cnt++;
        }
    }
    return cnt == 2 || cnt == 4;
}

int main() {
    cin >> h >> w;
    grid.resize(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#' && !check(i, j)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
