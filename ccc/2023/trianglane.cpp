// https://dmoj.ca/problem/ccc23s1

#include <bits/stdc++.h>

using namespace std;

int dx[2] = {-1, 1};
int dy[2] = {-1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;
    cin.ignore();

    vector<vector<int>> t(2, vector<int>(C, 0));

    // read inputs
    for (int i = 0; i < 2; i++) {
        string line;
        getline(cin, line);
        string row;
        int j = 0;
        for (char ch : line) {
            if (ch != ' ') {
                t[i][j++] = ch - '0';
            }
        }
    }

    int res = 0;

    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < C; y++) {
            if (t[x][y] == 1) {
                res += 3;
                for (int k = 0; k < 2; k++) {
                    int nx = x + dx[k];
                    if (nx >= 0 && nx < 2 && t[nx][y] == 1 && (y % 2 == 0)) {
                        res = res - 1;
                    }
                }

                cout << res << endl;

                for (int k = 0; k < 2; k++) {
                    int ny = y + dy[k];
                    if (ny >= 0 && ny < C && t[x][ny] == 1) {
                        res = res - 1;
                    }
                }

                cout << res << endl;
            }
        }
    }

    cout << res << endl;

    return 0;
}