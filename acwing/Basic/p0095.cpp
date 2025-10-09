// https://www.acwing.com/problem/content/97/

#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void turn(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            g[nx][ny] ^= '1' ^ '0';
        }
    }
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        char g[N][N], bg[N][N];

        for (int i = 0; i < 5; i++) cin >> bg[i];

        int res = 10;

        for (int op = 0; op < 32; op++) {
            int cnt = 0;
            memcpy(g, bg, sizeof g);
            for (int i = 0; i < 5; i++) {
                if (op >> i & 1) {
                    cnt++;
                    turn(0, i);
                }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 5; j++) {
                    if (g[i][j] == '1') {
                        cnt++;
                        turn(i + 1, j);
                    }
                }
            }
        }
    }
}
